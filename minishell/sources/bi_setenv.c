/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 19:19:18 by fherbine          #+#    #+#             */
/*   Updated: 2018/02/27 17:37:30 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	cmd_is_compatible(char *arg)
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	while (arg[i])
	{
		if (!ret && arg[i] == '=')
			ret = 1;
		else if (arg[i] == '=' && ret)
			return (0);
		if ((arg[i] > 0 && arg[i] <= 32) || arg[i] == 127)
			return (0);
		i++;
	}
	return (ret);
}

static char	*get_varname_aux(char *val)
{
	int		i;
	char	*ret;

	if (!(ret = (char *)malloc(sizeof(char) * (ft_strlen(val) + 1))))
		exit(EXIT_FAILURE);
	i = 0;
	while (val[i] && val[i] != '=')
	{
		ret[i] = val[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

char		**bi_setenv(char **envp, char **argv, t_shvar **shvar)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	i = 1;
	while (argv[i])
	{
		tmp = get_varname_aux(argv[i]);
		tmp2 = ftsh_search_envar(envp, tmp);
		if (cmd_is_compatible(argv[i]) && !tmp2)
		{
			envp = ft_add_tab_elem(envp, argv[i]);
			*shvar = add_shvar_elem(*shvar, argv[i]);
		}
		else if (tmp2)
		{
			env_exist(tmp);
			free(tmp2);
		}
		free(tmp);
		i++;
	}
	return (envp);
}
