/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 18:25:05 by fherbine          #+#    #+#             */
/*   Updated: 2018/02/13 19:15:18 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static t_commands	*cmd_new_lst(char *cmd)
{
	t_commands		*first;

	if (!(first = (t_commands *)malloc(sizeof(t_commands))))
		exit(EXIT_FAILURE);
	first->cmd = ft_strdup(cmd);
	first->next = NULL;
	return (first);
}

t_commands			*cmd_add_elem(t_commands *first, char *cmd)
{
	t_commands		*new;
	t_commands		*tmp;


	tmp = first;
	if (first)
	{
		if (!(new = (t_commands *)malloc(sizeof(t_commands))))
			exit(EXIT_FAILURE);
		new->cmd = ft_strdup(cmd);
		new->next = NULL;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		first = cmd_new_lst(cmd);
	return (first)
}

static size_t		cmd_len(char *cmd)
{
	size_t			i;

	i = 0;
	while (cmd[i] && cmd[i] != ';')
		i++;
	return (i);
}

size_t				cmd_add_cmd(char *all_cmd, t_commands *first)
{
	size_t			i;
	size_t			c_len;
	char			*tmp

	c_len = cmd_len(all_cmd);
	i = 0;
	if (!(tmp = (char *)malloc(sizeof(char) * (c_len + 1))))
		exit(EXIT_FAILURE);
	while (all_cmd[i] && all_cmd[i] != ';')
	{
		tmp[i] = all_cmd[i];
		i++;
	}
	tmp[i] = '\0';
	first = cmd_add_elem(first, tmp);
	free(tmp);
	return (i);
}
