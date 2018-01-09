/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 15:30:57 by fherbine          #+#    #+#             */
/*   Updated: 2018/01/09 17:04:13 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ch_includes/checker.h"

static void	ft_pp(t_instruction inst, t_pile **pile_a, t_pile **pile_b)
{
	t_pile	*tmp;

	tmp = NULL;
	if (inst == pa)
	{
		if (!(*pile_b))
			ft_kill(EXIT_FAILURE);
		tmp->next = *pile_a;
		tmp->nb = (*pile_b)->nb;
		*pile_a = tmp;
	}
	else
	{
		if (!(*pile_a))
			ft_kill(EXIT_FAILURE);
		tmp->next = *pile_b;
		tmp->nb = (*pile_a)->nb;
		*pile_b = tmp;
	}
}

static void	ft_ss(t_instruction inst, t_pile **pile_a, t_pile **pile_b)
{
	t_pile *tmp;

	if (inst == sa || inst == ss)
	{
		if (!(*pile_a) || !((*pile_a)->next))
			ft_kill(EXIT_FAILURE);
		tmp = (*pile_a)->next;
		(*pile_a)->next = tmp->next;
		tmp->next = (*pile_a);
		(*pile_a) = tmp;
	}
	if (inst == sb || inst == ss)
	{
		if (!(*pile_b) || !((*pile_b)->next))
			ft_kill(EXIT_FAILURE);
		tmp = (*pile_b)->next;
		(*pile_b)->next = tmp->next;
		tmp->next = (*pile_b);
		(*pile_b) = tmp;
	}
}

static void	ft_rr(t_instruction inst, t_pile **pile_a, t_pile **pile_b)
{
	t_pile	*tmp;

	if ((inst == ra || inst == rr))
	{
		if (!(*pile_a) || !((*pile_a)->next))
			ft_kill(EXIT_FAILURE);
		tmp = *pile_a;
		while (tmp)
			tmp = tmp->next;
		tmp = (*pile_a);
		tmp->next = NULL;
		(*pile_a) = (*pile_a)->next;

	}
	if ((inst == rb || inst == rr))
	{
		if (!(*pile_b) || !((*pile_b)->next))
			ft_kill(EXIT_FAILURE);
		tmp = *pile_b;
		while (tmp)
			tmp = tmp->next;
		tmp = (*pile_b);
		tmp->next = NULL;
		(*pile_b) = (*pile_b)->next;
	}
}

static void	ft_rrr(t_instruction inst, t_pile **pile_a, t_pile **pile_b)
{
	t_pile	*tmp;

	if ((inst == rra || inst == rrr))
	{
		if (!(*pile_a) || !((*pile_a)->next))
			ft_kill(EXIT_FAILURE);
		tmp = *pile_a;
		while (tmp->next)
			tmp = tmp->next;
		(*pile_a) = ft_add_in_pile(tmp->nb, *pile_a);
		tmp = NULL;
	}
	if ((inst == rrb || inst == rrr))
	{
		if (!(*pile_b) || !((*pile_b)->next))
			ft_kill(EXIT_FAILURE);
		tmp = *pile_b;
		while (tmp->next)
			tmp = tmp->next;
		(*pile_b) = ft_add_in_pile(tmp->nb, *pile_b);
		tmp = NULL;
	}
}

void	ft_do_actions(t_order *orders, t_pile **pile_a, t_pile **pile_b)
{
	while (orders->next != NULL)
	{
		if (orders->inst == pa || orders->inst == pb)
			ft_pp(orders->inst, pile_a, pile_b);
		else if (orders->inst == sa || orders->inst == sb || orders->inst == ss)
			ft_ss(orders->inst, pile_a, pile_b);
		else if (orders->inst == ra || orders->inst == rb || orders->inst == rr)
			ft_rr(orders->inst, pile_a, pile_b);
		else if (orders->inst == rra || orders->inst == rrb || orders->inst == rrr)
			ft_rrr(orders->inst, pile_a, pile_b);
	}
}
