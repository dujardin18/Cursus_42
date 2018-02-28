/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftsh_free_envlist.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 16:15:22 by fherbine          #+#    #+#             */
/*   Updated: 2018/02/19 16:17:23 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void			free_envlist(t_envlist *lst)
{
	t_envlist	*cp;

	cp = lst;
	while (lst)
	{
		free(lst->value);
		lst = lst->next;
		free(cp);
		cp = lst;
	}
}
