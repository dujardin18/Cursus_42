/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 19:19:18 by fherbine          #+#    #+#             */
/*   Updated: 2018/02/27 15:53:27 by fherbine         ###   ########.fr       */
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

char		**bi_setenv(char **envp, char **argv, t_shvar **shvar)
{
	int		i;

	i = 1;
	while (argv[i])
	{
		if (cmd_is_compatible(argv[i]))
		{
			envp = ft_add_tab_elem(envp, argv[i]);
			*shvar = add_shvar_elem(*shvar, argv[i]);
		}
		i++;
	}
	return (envp);
}
