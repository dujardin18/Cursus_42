/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 19:52:58 by fherbine          #+#    #+#             */
/*   Updated: 2018/02/13 19:58:46 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_commands		*parse_cmds(char *line)
{
	t_commands	*first;
	t_commands	*tmp;

	first = NULL;
	first = get_all_cmds(line);
	tmp = first;
	while (tmp)
	{
		tmp = cmd_getargs(tmp);
		tmp = tmp->next;
	}
	return (first);
}
