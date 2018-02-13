/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 18:17:07 by fherbine          #+#    #+#             */
/*   Updated: 2018/02/13 19:48:48 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void			free_tab(char **tab)
{
	int				i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void				free_cmds(t_commands *cmds)
{
	t_commands		*tmp;

	tmp = cmds;
	while (cmds)
	{
		free(cmds->cmd);
		free_tab(cmds->argv);
		cmds = cmds->next;
		free(tmp);
		tmp = cmds;
	}
}
