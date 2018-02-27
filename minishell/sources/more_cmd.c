/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 19:27:10 by fherbine          #+#    #+#             */
/*   Updated: 2018/02/27 17:24:37 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int				ms_isvar(char *cmd)
{
	int			i;

	i = 0;
	if (cmd[0] == '=')
		return (0);
	while (cmd[i] != '=' && cmd[i])
	{
		if (!ft_isalpha(cmd[i]))
			return (0);
		i++;
	}
	if (!cmd[i])
		return (0);
	while (cmd[i])
	{
		if (!ft_isprint(cmd[i]) || cmd[i] <= 32)
			return (0);
		i++;
	}
	return (1);
}

static t_shvar	*get_all_shvar(char **argv, char **envp, t_shvar *shvar)
{
	char		*notenv;
	char		*tmp;
	int			i;

	i = 0;
	while (argv[i])
	{
		if (ms_isvar(argv[i]))
		{
			tmp = get_var_name(argv[i]);
			notenv = ftsh_search_envar(envp, tmp);
			shvar = (!notenv) ? add_shvar_elem(shvar, argv[i]) : \
					env_var_used(tmp, shvar);
			free(tmp);
			free(notenv);
		}
		else
		{
			command_unknown(argv[0]);
			break ;
		}
		i++;
	}
	return (shvar);
}

t_shvar			*exec_or_var(char **argv, char **envp, t_shvar *shvar)
{
	pid_t		father;

	if (ftsh_ispath(argv[0]) && access(argv[0], F_OK) == 0)
	{
		if (access(argv[0], X_OK) == 0)
		{
			father = fork();
			if (father == 0)
				execve(argv[0], argv, envp);
			if (father > 0)
				wait(&father);
		}
	}
	else
		shvar = get_all_shvar(argv, envp, shvar);
	return (shvar);
}
