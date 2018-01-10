/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 15:30:57 by fherbine          #+#    #+#             */
/*   Updated: 2018/01/10 16:17:01 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ch_includes/checker.h"

static void	ft_pp(t_instruction inst, t_pile **pile_a, t_pile **pile_b)
{
	t_pile	*tmp;

	tmp = NULL;
	tmp = ft_malloc_secure(tmp);
	if (inst == pa)
	{
		if (!(*pile_b))
			ft_kill(EXIT_FAILURE);
		tmp->next = *pile_a;
		tmp->nb = (*pile_b)->nb;
		free(*pile_a);
		*pile_a = tmp;
		(*pile_b) = (*pile_b)->next;
	}
	else
	{
		if (!(*pile_a))
			ft_kill(EXIT_FAILURE);
		tmp->next = *pile_b;
		tmp->nb = (*pile_a)->nb;
		free(*pile_b);
		*pile_b = tmp;
		(*pile_a) = (*pile_a)->next;
	}
//	free(tmp);
}

static void	ft_ss(t_instruction inst, t_pile **pile_a, t_pile **pile_b)
{
	int tmp;

	if (inst == sa || inst == ss)
	{
		if (!(*pile_a) || !((*pile_a)->next))
			ft_kill(EXIT_FAILURE);
		tmp = (*pile_a)->next->nb;
		(*pile_a)->next->nb = (*pile_a)->nb;
		(*pile_a)->nb = tmp;
	}
	if (inst == sb || inst == ss)
	{
		if (!(*pile_b) || !((*pile_b)->next))
			ft_kill(EXIT_FAILURE);
		tmp = (*pile_b)->next->nb;
		(*pile_b)->next->nb = (*pile_b)->nb;
		(*pile_b)->nb = tmp;
	}
}

static void	ft_rr(t_instruction inst, t_pile **pile_a, t_pile **pile_b)
{
	t_pile	*tmp;

	if (inst == ra || inst == rr)
	{
		if (!(*pile_a) || !((*pile_a)->next))
			ft_kill(EXIT_FAILURE);
		tmp = *pile_a;
		while (tmp->next)
		{
			ft_ss(sa, &tmp, &tmp);
			tmp = tmp->next;
		}
	}
	if (inst == rb || inst == rr)
	{
		if (!(*pile_b) || !((*pile_b)->next))
			ft_kill(EXIT_FAILURE);
		tmp = *pile_b;
		while (tmp->next)
		{
			ft_ss(sb, &tmp, &tmp);
			tmp = tmp->next;
		}
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
		ft_swap(&(tmp->nb), &((*pile_a)->nb));
	}
	if ((inst == rrb || inst == rrr))
	{
		if (!(*pile_b) || !((*pile_b)->next))
			ft_kill(EXIT_FAILURE);
		tmp = *pile_b;
		while (tmp->next)
			tmp = tmp->next;
		ft_swap(&(tmp->nb), &((*pile_b)->nb));
	}
}

void	ft_do_actions(t_order *orders, t_pile **pile_a, t_pile **pile_b)
{
	while (orders)
	{
		if (orders->inst == pa || orders->inst == pb)
			ft_pp(orders->inst, pile_a, pile_b);
		else if (orders->inst == sa || orders->inst == sb || orders->inst == ss)
			ft_ss(orders->inst, pile_a, pile_b);
		else if (orders->inst == ra || orders->inst == rb || orders->inst == rr)
			ft_rr(orders->inst, pile_a, pile_b);
		else if (orders->inst == rra || orders->inst == rrb || orders->inst == rrr)
			ft_rrr(orders->inst, pile_a, pile_b);
		orders = orders->next;
	}
}
