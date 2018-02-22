/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 16:35:00 by fherbine          #+#    #+#             */
/*   Updated: 2018/02/22 19:24:55 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		launch_cmd(int argc, char **argv, char **envp)
{
	pid_t	father;
	t_envlist	*paths;

	if (cmd_is_builtin(argv[0]))
		launch_builtin(argc, argv, envp);
	else
	{
		paths = new_envpath(envp);
		if (bin_path(argv[0], paths))
		{
			father = fork();
			if (father == 0)
				launch_other(paths, argv, envp);
			if (father > 0)
				wait(&father);
		}
		else
			exec_or_var(argv, envp);
		if (paths)
			free_envlist(paths);
	}
}

void			exec_all_cmds(t_commands *cmds, char **envp)
{
	t_commands	*cp;

	cp = cmds;
	while (cp)
	{
		launch_cmd(cp->argc, cp->argv, envp);
		cp = cp->next;
	}
}

void		exec_cmd_line(char **envp)
{
	t_commands	*cmds;
	char		*ln;
	int			n;

	n = get_next_line(0, &ln);
	if (n > 0)
	{
		cmds = parse_cmds(ln);
		ftsh_debug_t_cmd(cmds, "exec_cmd_line (minishell.c)");
		exec_all_cmds(cmds, envp);
		free(ln);
	}
}

void		prompt_get_cmd_line(char **envp)
{
	char	*prompt;

	while (1)
	{
		prompt = ms_get_prompt(envp);
		ft_prints("%s $> ", prompt);
		exec_cmd_line(envp);
		free(prompt);
	}
}
