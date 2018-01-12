/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 15:30:57 by fherbine          #+#    #+#             */
/*   Updated: 2018/01/12 16:04:51 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ch_includes/checker.h"

static void	ft_pp(t_instruction inst, t_pile **pile_a, t_pile **pile_b)
{
	t_pile	*tmp;
	int nb;

	ft_putendl(">pb strt");
	ft_putendl("A:");
	ft_display_list(*pile_a);
	ft_putendl("B:");
	ft_display_list(*pile_b);
	tmp = NULL;
	//tmp = ft_malloc_secure(tmp);
	if (inst == pa)
	{
		ft_putendl("beware ===================");
		if (!(*pile_b))
			ft_kill(EXIT_FAILURE);
		tmp->next = *pile_a;
		tmp->nb = (*pile_b)->nb;
		*pile_a = tmp;
		(*pile_b) = (*pile_b)->next;
		free(tmp);
	}
	else
	{
		if (!(*pile_a))
			ft_kill(EXIT_FAILURE);
		nb = (*pile_a)->nb;
		if (*pile_b)
			tmp->next = *pile_b;
		else
		{
			ft_putendl("ICICICICICI");
		ft_putendl(">Here");
		ft_putendl("A:");
		ft_display_list(*pile_a);
			*pile_b = ft_malloc_secure(*pile_b);
		ft_putendl(">Here");
		ft_putendl("A:");
		ft_display_list(*pile_a);
			tmp->next = NULL; ////////////////////// --------------- > ca chie
		ft_putendl(">Here");
		ft_putendl("A:");
		ft_display_list(*pile_a);
		}
		ft_putendl(">Here");
		ft_putendl("A:");
		ft_display_list(*pile_a);
		ft_putendl("B:");
		//ft_display_list(*pile_b);
		tmp->nb = nb;
		*pile_b = tmp;
		(*pile_a) = (*pile_a)->next;
	}
	ft_putendl(">pb end");
	ft_putendl("A:");
	ft_display_list(*pile_a);
	ft_putendl("B:");
	ft_display_list(*pile_b);
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
	t_pile	*new;
	new = NULL;

	ft_putendl(">rra strt");
	ft_putendl("A:");
	ft_display_list(*pile_a);
	ft_putendl("B:");
	ft_display_list(*pile_b);
	if ((inst == rra || inst == rrr))
	{
		if (!(*pile_a) || !((*pile_a)->next))
			ft_kill(EXIT_FAILURE);
		new = ft_malloc_secure(new);
		new->next = *pile_a;
		tmp = *pile_a;
		while (tmp->next->next)
			tmp = tmp->next;
		new->nb = tmp->next->nb;
		tmp->next = NULL;
		*pile_a = new;
	}
	if ((inst == rrb || inst == rrr))
	{
		if (!(*pile_b) || !((*pile_b)->next))
			ft_kill(EXIT_FAILURE);
		new = ft_malloc_secure(new);
		new->next = *pile_b;
		tmp = *pile_b;
		while (tmp->next->next)
			tmp = tmp->next;
		new->nb = tmp->next->nb;
		tmp->next = NULL;
		*pile_b = new;
	}
	free(new);
	ft_putendl(">rra end");
	ft_putendl("A:");
	ft_display_list(*pile_a);
	ft_putendl("B:");
	ft_display_list(*pile_b);
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
