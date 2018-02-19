/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 15:25:23 by fherbine          #+#    #+#             */
/*   Updated: 2018/02/19 16:57:01 by fherbine         ###   ########.fr       */
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

void	launch_builtin(int argc, char **argv, char **envp)
{
	if (ft_strcmp(argv[0], "env") == 0)
		bi_env(envp);
	else if (ft_strcmp(argv[0], "exit") == 0)
		bi_exit();
}

void			launch_other(int argc, char **argv, char **envp)
{
	t_envlist	*paths;
	t_envlist	*cp;
	char		*tmp;
	int			succeed;

	paths = get_envlist(envp, "PATH");
	cp = paths;
	while (cp)
	{
		tmp = ft_strdup(cp->value);
		tmp = ft_append_slash(tmp);
		tmp = ft_strjoin(tmp, argv[0]);
		succeed = execve(tmp, argv, envp); // arret >> leaks !
		free(tmp);
		cp = cp->next;
	}
	free_envlist(paths);
}
