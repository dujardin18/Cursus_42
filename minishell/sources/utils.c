/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 15:25:23 by fherbine          #+#    #+#             */
/*   Updated: 2018/02/20 18:56:17 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		cmd_is_builtin(char *cmd)
{
	if (ft_strcmp(cmd, "cd") == 0 || ft_strcmp(cmd, "echo") == 0 || \
			ft_strcmp(cmd, "env") == 0 || ft_strcmp(cmd, "setenv") == 0 || \
			ft_strcmp(cmd, "unsetenv") == 0 || ft_strcmp(cmd, "exit") == 0)
		return (1);
	else
		return (0);
}

void	launch_builtin(int argc, char **argv, char **envp, t_shvar *shvar)
{
	if (ft_strcmp(argv[0], "env") == 0)
		bi_env(envp);
	else if (ft_strcmp(argv[0], "exit") == 0)
		bi_exit();
	else if (ft_strcmp(argv[0], "echo") == 0)
		bi_echo(argv, shvar);
	else if (ft_strcmp(argv[0], "unsetenv") == 0)
		bi_unsetenv(envp, &shvar, argv);
}

void			launch_other(t_envlist *paths, char **argv, char **envp)
{
	t_envlist	*cp;

	cp = paths;
	while (cp)
	{
		if (ft_is_in_dir(argv[0], cp->value))
			break ;
		cp = cp->next;
	}
	cp->value = ft_strjoin(cp->value, argv[0]);
	execve(cp->value, argv, envp);
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

int				bin_path(char *name, t_envlist *path)
{
	t_envlist	*cp;

	cp = path;
	while (cp)
	{
		if (ft_is_in_dir(name, cp->value) == 1)
			return (1);
		cp = cp->next;
	}
	return (0);
}
