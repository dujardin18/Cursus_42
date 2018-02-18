/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 16:43:48 by fherbine          #+#    #+#             */
/*   Updated: 2018/02/18 18:06:26 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_commands		*get_all_cmds(char *all_cmd)
{
	t_commands	*first;
	size_t		i;

	i = 0;
	first = NULL;
	while (all_cmd[i])
	{
		while (all_cmd[i] && (all_cmd[i] == ' ' || all_cmd[i] == ';' || all_cmd[i] == '\t'))
			i++;
		i += cmd_add_cmd(&(all_cmd[i]), &first);
		i += (all_cmd[i] == ';') ? 1 : 0;
	}
	return (first);
}

static int	cmd_getargc(t_commands *elem)
{
	int		i;
	int		argc;

	i = 0;
	argc = 0;
	while ((elem->cmd)[i])
	{
		while ((elem->cmd)[i] && ((elem->cmd)[i] == ' ' || (elem->cmd)[i] == '\t'))
			i++;
		if ((elem->cmd)[i])
			argc++;
		while ((elem->cmd)[i] && elem->cmd[i] != ' ' && elem->cmd[i] != '\t')
			i++;
		i++;
	}
	return (argc);	
}

static int	c_len_spec(char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != '\t')
		i++;
	return (i);
}

static char	**cmd_getargv(t_commands *elem)
{
	int		i;
	int		i2;
	int		i3;
	char	**argv;

	i = 0;
	i2 = 0;
	if (!(argv = (char **)malloc(sizeof(char *) * (elem->argc + 2))))
		exit(EXIT_FAILURE);
	while (i2 < elem->argc)
	{
		i3 = 0;
		while (elem->cmd[i] && (elem->cmd[i] == ' ' || elem->cmd[i] == '\t'))
			i++;
		if (!(argv[i2] = (char *)malloc(sizeof(char) * c_len_spec(&(elem->cmd[i])))))
			exit(EXIT_FAILURE);
		while (elem->cmd[i] && elem->cmd[i] != ' ' && elem->cmd[i] != '\t')
		{
			argv[i2][i3] = elem->cmd[i];
			i++;
			i3++;
		}
		argv[i2][i3] = '\0';
		i2++;
	}
	argv[i2] = 0;
	return (argv);
}

t_commands	*cmd_getargs(t_commands *elem)
{
	elem->argc = cmd_getargc(elem);
	elem->argv = cmd_getargv(elem);
	return (elem);
}
