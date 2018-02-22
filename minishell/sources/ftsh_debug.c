/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftsh_debug.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 17:18:24 by fherbine          #+#    #+#             */
/*   Updated: 2018/02/18 18:56:39 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void			ftsh_debug_t_cmd(t_commands *c, char *msg)
{
	t_commands	*cp;
	int			i;

	if (DEBUG)
	{
		ft_prints("\t\t\t= %s =\n\n", msg);
		cp = c;
		while (cp)
		{
			i = 0;
			ft_prints("cmd : %s\nargc: %d\nARGVS : \t", cp->cmd, cp->argc);
			while (cp->argv[i])
			{
				ft_prints(">%s<\t", cp->argv[i]);
				i++;
			}
			ft_putendl("\n");
			cp = cp->next;
		}
	}
}

void			ftsh_debug_shvar(t_shvar *shvar, char *msg)
{
	t_shvar		*cp;

	if (DEBUG)
	{
		cp = shvar;
		ft_prints("\n%s:\n\n", msg);
		while (cp)
		{
			ft_prints("|%s=%s|\n", cp->name, cp->value);
			cp = cp->next;
		}
	}
}
