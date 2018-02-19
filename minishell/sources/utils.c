/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 15:25:23 by fherbine          #+#    #+#             */
/*   Updated: 2018/02/19 15:29:28 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		cmd_is_builtin(char *cmd)
{
	if (ft_strcmp(cmd, "cd") == 0 || ft_strcmp(cmd, "echo") == 0 || \
			ft_strcmp(cmd, "env") == 0 || ft_strcmp(cmd, "setenv") == 0 || \
			ft_strcmp(cmd, "unsetenv") || ft_strcmp(cmd, "exit"))
		return (1);
	else
		return (0);
}
