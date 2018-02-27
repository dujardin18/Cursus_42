/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 15:30:16 by fherbine          #+#    #+#             */
/*   Updated: 2018/02/27 15:50:47 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	command_unknown(char *unknown)
{
	ft_prints_fd(2, "minishell: %s: command not found.\n", unknown);
}

t_shvar	*env_var_used(char *name, char *to_free, t_shvar *shvar)
{
	ft_prints_fd(2, "minishell: %s: \
			This is an env variable use 'setenv' to edit.\n", name);
	free(to_free);
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
