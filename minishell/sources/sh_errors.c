/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 15:30:16 by fherbine          #+#    #+#             */
/*   Updated: 2018/02/27 17:37:25 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	command_unknown(char *unknown)
{
	ft_prints_fd(2, "minishell: %s: command not found.\n", unknown);
}

t_shvar	*env_var_used(char *name, t_shvar *shvar)
{
	ft_prints_fd(2, \
			"minishell: %s: This is an env variable use 'setenv' to edit.\n", \
			name);
	return (shvar);
}

void	no_fod(char *disp)
{
	ft_prints_fd(2, "minishell: cd: %s: No such file or directory\n", disp);
}

void	no_opwd(void)
{
	ft_prints_fd(2, "minishell: cd: OLDPWD not set\n");
}

void	env_exist(char *name)
{
	ft_prints_fd(2, "minishell: %s: Already exist use 'unsetenv' before.\n", \
			name);
}
