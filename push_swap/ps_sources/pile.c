/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 11:14:59 by fherbine          #+#    #+#             */
/*   Updated: 2018/01/15 15:12:29 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ch_includes/checker.h"

t_pile	*ft_new_pile(int first_nb)
{
	t_pile	*first;
	
	if (!(first = (t_pile *)malloc(sizeof(t_pile))))
		ft_kill(EXIT_FAILURE);
	first->next = NULL;
	first->nb = first_nb;
	return (first);
}

t_pile	*ft_add_in_pile(int nb_to_add, t_pile *first)
{
	t_pile	*tmp;
	t_pile	*new;

	tmp = first;
	if (!(new = (t_pile *)malloc(sizeof(t_pile))))
		ft_kill(EXIT_FAILURE);
	while (tmp->next)
		tmp = tmp->next;
	new->next = NULL;
	new->nb = nb_to_add;
	tmp->next = new;
	return (first);
}

int		ft_pile_len(t_pile *pile)
{
	int	n;

	n = 0;
	while (pile->next)
	{
		pile = pile->next;
		n++;
	}
	return (n);
}

int		ft_pile_is_sorted(t_pile *pile)
{
	while (pile->next)
	{
		if (pile->next->nb < pile->nb)
			return (0);
		pile = pile->next;
	}
	return (1);
}
