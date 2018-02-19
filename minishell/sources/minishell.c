/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 16:35:00 by fherbine          #+#    #+#             */
/*   Updated: 2018/02/19 15:35:22 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		launch_cmd(int argc, char **argv, char **envp)
{
	if (cmd_is_builtin(argv[0]))
	else
}

int			exec_cmd(int argc, char **argv, char **envp)
{
	pid_t	father;

	father = fork;
	if (fork == 0)
		launch_cmd();
	else
	{
		wait(&father);
	}
}

void			exec_all_cmds(t_commands *cmds, char **envp)
{
	t_commands	*cp;

	cp = cmds;
	while (cp)
	{
		exec_cmd(cp->argc, cp->argv, envp);
		cp = cp->next;
	}
}

void		exec_cmd_line(void)
{
	t_commands	*cmds;
	char		*ln;
	int			n;

	n = get_next_line(0, &ln);
	if (n > 0)
	{
		cmds = parse_cmds(ln);
		ftsh_debug_t_cmd(cmds, "exec_cmd_line (minishell.c)");
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
		exec_cmd_line();
		free(prompt);
	}
}
