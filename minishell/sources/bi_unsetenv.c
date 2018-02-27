/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 15:53:36 by fherbine          #+#    #+#             */
/*   Updated: 2018/02/27 15:53:45 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**bi_unsetenv(char **envp, t_shvar **shvar, char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		envp = ftsh_del_envar(shvar, argv[i], envp);
		i++;
	}
	return (envp);
}
