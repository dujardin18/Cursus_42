/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:11:25 by fherbine          #+#    #+#             */
/*   Updated: 2018/01/12 15:49:18 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ch_includes/checker.h"

///////////////////////////////// DEBUG
void ft_display_list(t_pile *pile)
{
	while (pile)
	{
		ft_putstr("nb: ");
		ft_putnbr(pile->nb);
		ft_putendl("");
		pile = pile->next;
	}
}

void ft_display_list2(t_order *order)
{
	while (order)
	{
		ft_putstr("inst: ");
		if (order->inst == sa) {ft_putendl("sa");}
		else if (order->inst == sb) {ft_putendl("sb");}
		else if (order->inst == ss) {ft_putendl("ss");}
		else if (order->inst == ra) {ft_putendl("ra");}
		else if (order->inst == rb) {ft_putendl("rb");}
		else if (order->inst == rr) {ft_putendl("rr");}
		else if (order->inst == rra) {ft_putendl("rra");}
		else if (order->inst == rrb) {ft_putendl("rrb");}
		else if (order->inst == rrr) {ft_putendl("rrr");}
		else if (order->inst == pa) {ft_putendl("pa");}
		else if (order->inst == pb) {ft_putendl("pb");}
		order = order->next;
	}
}
///////////////////////////////// EOD

int		main(int argc, char **argv)
{
	t_pile	*pile_a;
	t_pile	*pile_b;

	pile_b = NULL;
//	pile_b = ft_malloc_secure(pile_b);
//	pile_b = NULL;
	pile_a = ft_parser(argc, argv);
	//ft_display_list(pile_a);
	ft_check_piles(pile_a, pile_b);

	free(pile_a);
	free(pile_b);
	ft_kill(EXIT_FAILURE);
	return (0);
}
