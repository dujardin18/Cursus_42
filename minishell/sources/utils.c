/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 15:25:23 by fherbine          #+#    #+#             */
/*   Updated: 2018/02/27 19:02:55 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int				cmd_is_builtin(char *cmd)
{
	if (ft_strcmp(cmd, "cd") == 0 || ft_strcmp(cmd, "echo") == 0 || \
			ft_strcmp(cmd, "env") == 0 || ft_strcmp(cmd, "setenv") == 0 || \
			ft_strcmp(cmd, "unsetenv") == 0 || ft_strcmp(cmd, "exit") == 0 || \
			ft_strcmp(cmd, "history") == 0)
		return (1);
	else
		return (0);
}

char			**launch_builtin(int argc, char **argv, char **envp, \
		t_shvar **shvar)
{
	if (ft_strcmp(argv[0], "env") == 0)
		bi_env(envp);
	else if (ft_strcmp(argv[0], "exit") == 0)
		bi_exit();
	else if (ft_strcmp(argv[0], "echo") == 0)
		bi_echo(argv, *shvar);
	else if (ft_strcmp(argv[0], "unsetenv") == 0)
		envp = bi_unsetenv(envp, shvar, argv);
	else if (ft_strcmp(argv[0], "setenv") == 0)
		envp = bi_setenv(envp, argv, shvar);
	else if (ft_strcmp(argv[0], "cd") == 0)
		envp = bi_cd(shvar, argv, envp, argc);
	else if (ft_strcmp(argv[0], "history") == 0)
		bi_history(envp);
	return (envp);
}

t_envlist		*launch_other(t_envlist *paths, char **argv)
{
	t_envlist	*cp;

	cp = paths;
	while (cp)
	{
		cp->value = ft_strjoin(cp->value, argv[0]);
		cp = cp->next;
	}
	return (paths);
}

t_envlist		*new_envpath(char **envp)
{
	t_envlist	*new;
	t_envlist	*cp;

	new = get_envlist(envp, "PATH");
	cp = new;
	while (cp)
	{
		cp->value = ft_append_slash(cp->value);
		cp = cp->next;
	}
	return (new);
}

int				bin_path(t_envlist *path)
{
	t_envlist	*cp;

	cp = path;
	while (cp)
	{
		if (access(cp->value, F_OK) == 0)
			return (1);
		cp = cp->next;
	}
	return (0);
}
