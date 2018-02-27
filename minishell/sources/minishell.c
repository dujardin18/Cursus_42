/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 16:35:00 by fherbine          #+#    #+#             */
/*   Updated: 2018/02/27 15:21:32 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static t_shvar	*lcmd_aux(char **argv, t_envlist *paths, \
		char ***envp, t_shvar *shvar)
{
	t_envlist	*cp;
	pid_t		father;

	paths = new_envpath(*envp);
	cp = paths;
	paths = launch_other(cp, argv);
	if (bin_path(paths))
	{
		father = fork();
		if (father == 0)
		{
			while (access(cp->value, X_OK) != 0)
				cp = cp->next;
			execve(cp->value, argv, *envp);
		}
		if (father > 0)
			wait(&father);
	}
	else
		shvar = exec_or_var(argv, *envp, shvar);
	free_envlist(paths);
	return (shvar);
}

static t_shvar	*launch_cmd(int argc, char **argv, char ***envp, t_shvar *shvar)
{
	t_envlist	*paths;

	paths = NULL;
	if (cmd_is_builtin(argv[0]))
		*envp = launch_builtin(argc, argv, *envp, &shvar);
	else
		shvar = lcmd_aux(argv, paths, envp, shvar);
	return (shvar);
}

static t_shvar	*exec_all_cmds(t_commands *cmds, char ***envp, t_shvar *shvar)
{
	t_commands	*cp;

	cp = cmds;
	while (cp)
	{
		shvar = launch_cmd(cp->argc, cp->argv, envp, shvar);
		cp = cp->next;
	}
	return (shvar);
}

static t_shvar	*exec_cmd_line(char ***envp, t_shvar *shvar)
{
	t_commands	*cmds;
	char		*ln;
	int			n;

	ln = NULL;
	n = get_next_line(0, &ln);
	if (n > 0)
	{
		cmds = parse_cmds(ln);
		ftsh_debug_t_cmd(cmds, "exec_cmd_line (minishell.c)");
		shvar = exec_all_cmds(cmds, envp, shvar);
		free_cmds(cmds);
		free(ln);
	}
	return (shvar);
}

void			prompt_get_cmd_line(char **envp, t_shvar *shvar)
{
	char		*prompt;

	while (1)
	{
		ftsh_debug_shvar(shvar, "Looking for shell vars");
		prompt = ms_get_prompt(envp);
		ft_prints("%s $> ", prompt);
		shvar = exec_cmd_line(&envp, shvar);
		free(prompt);
	}
}
