/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 14:15:17 by fherbine          #+#    #+#             */
/*   Updated: 2018/01/09 15:30:03 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ch_includes/checker.h"

static t_instruction	check_order(char *order)
{
	if (ft_strcmp(order, "sa") == 0)
		return (sa);
	else if (ft_strcmp(order, "sb") == 0)
		return (sb);
	else if (ft_strcmp(order, "ss") == 0)
		return (ss);
	else if (ft_strcmp(order, "rr") == 0)
		return (rr);
	else if (ft_strcmp(order, "ra") == 0)
		return (ra);
	else if (ft_strcmp(order, "rb") == 0)
		return (rb);
	else if (ft_strcmp(order, "pa") == 0)
		return (pa);
	else if (ft_strcmp(order, "pb") == 0)
		return (pb);
	else if (ft_strcmp(order, "rra") == 0)
		return (rra);
	else if (ft_strcmp(order, "rrb") == 0)
		return (rrb);
	else if (ft_strcmp(order, "rrr") == 0)
		return (rrr);
	return (none);
}

static t_order			*ft_new_order_lst(char *order)
{
	t_order *first;

	if (!(first = (t_order *)malloc(sizeof(t_order))))
		ft_kill(EXIT_FAILURE);
	first->inst = check_order(order);
	if (first->inst == none)
		ft_error();
	first->next = NULL;
	return (first);
}

static t_order			*ft_add_order(char *order, t_order *first)
{
	t_order *tmp;
	t_order *new;

	tmp = first;
	if (!(new = (t_order *)malloc(sizeof(t_order))))
		ft_kill(EXIT_FAILURE);
	while (tmp->next != NULL)
		tmp = tmp->next;
	new->inst = check_order(order);
	if (new->inst == none)
		ft_error();
	new->next = NULL;
	tmp->next = new;
	return (first);
}

t_order					*ft_instructions(void)
{
	t_order	*first;
	int n;
	char *order;

	first = NULL;
	n = get_next_line(0, &order);
	if (n > 0)
		first = ft_new_order_lst(order);
	while (n > 0)
	{
		free(order);
		n = get_next_line(0, &order);
		first = ft_add_order(order, first);
	}
	return (first);
}
