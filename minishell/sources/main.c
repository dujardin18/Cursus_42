/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 16:34:00 by fherbine          #+#    #+#             */
/*   Updated: 2018/02/25 18:37:39 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static t_shvar	*get_shvar_from_env(char **envp, t_shvar *shvar)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		shvar = add_shvar_elem(shvar, envp[i]);
		i++;
	}
	return (shvar);
}

int		main(int argc, char **argv, char **envp)
{
	int		end;
	t_shvar *shvar;
	char	**envcp;

	end = 0;
	shvar = NULL;
	envcp = ft_copy_tab(envp);
	shvar = get_shvar_from_env(envcp, shvar);
	envcp = init_env(envcp, &shvar);
	if (argc == 1)
		prompt_get_cmd_line(envcp, shvar);
	else
		ms_too_much_params(argc, argv);
	return (0);
}
