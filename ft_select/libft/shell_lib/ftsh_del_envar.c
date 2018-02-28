/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftsh_del_envar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 18:30:31 by fherbine          #+#    #+#             */
/*   Updated: 2018/02/25 18:40:23 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	**ftsh_del_envar(t_shvar **first, char *name, char **envp)
{
	t_shvar	*cp;
	int		i;

	cp = *first;
	i = 0;
	envp = ft_tab_del_elem(envp, name);
	while (cp && ft_strcmp(name, cp->name) != 0)
		cp = cp->next;
	if (cp)
	{
		cp->name[0] = 0;
		cp->value[0] = 0;
	}
	return (envp);
}
