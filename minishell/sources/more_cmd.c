/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 19:27:10 by fherbine          #+#    #+#             */
/*   Updated: 2018/02/22 19:44:17 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	exec_or_var(char **argv, char **envp)
{
	pid_t	father;

	if (ftsh_ispath(argv[0]) && access(argv[0], F_OK) == 0)
	{
		if (access(argv[0], X_OK) == 0)
		{
			//father = fork();
			//if (father > 0)
			//	execve(argv[0], argv, envp);
			//if (father == 0)
			//	wait(&father);
		}
	}
	else
		ft_prints("Is it var ?\n");
}
