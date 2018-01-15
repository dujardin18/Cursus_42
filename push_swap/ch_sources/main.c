/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:11:25 by fherbine          #+#    #+#             */
/*   Updated: 2018/01/15 17:13:45 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ch_includes/checker.h"

///////////////////////////////// DEBUG
void ft_display_list(t_pile *pile)
{
	if (!pile && DEBUG)
		ft_putendl("\033[0;33;40m|X|\033[0m \033[0;31;40mEMPTY\033[0;33;40m |X|\033[0m");
	while (DEBUG && pile)
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
		if (DEBUG && order->inst == sa) {ft_putendl("sa");}
		else if (DEBUG && order->inst == sb) {ft_putendl("sb");}
		else if (DEBUG && order->inst == ss) {ft_putendl("ss");}
		else if (DEBUG && order->inst == ra) {ft_putendl("ra");}
		else if (DEBUG && order->inst == rb) {ft_putendl("rb");}
		else if (DEBUG && order->inst == rr) {ft_putendl("rr");}
		else if (DEBUG && order->inst == rra) {ft_putendl("rra");}
		else if (DEBUG && order->inst == rrb) {ft_putendl("rrb");}
		else if (DEBUG && order->inst == rrr) {ft_putendl("rrr");}
		else if (DEBUG && order->inst == pa) {ft_putendl("pa");}
		else if (DEBUG && order->inst == pb) {ft_putendl("pb");}
		order = order->next;
	}
}

void	ft_debug(t_pile *pile_a, t_pile *pile_b)
{
	if (DEBUG)
	{
		ft_putendl("pile_A:");
		ft_display_list(pile_a);
		ft_putendl("pile_B:");
		ft_display_list(pile_b);
		ft_putendl("------------");
		ft_putendl("");
	}
}
///////////////////////////////// EOD

int		main(int argc, char **argv)
{
	t_pile	*pile_a;
	t_pile	*pile_b;

	pile_b = NULL;
	pile_b = ft_malloc_secure(pile_b);
	pile_b = NULL;
	pile_a = ft_parser(argc, argv);
	ft_check_piles(pile_a, pile_b);

	free(pile_a);
	free(pile_b);
	ft_kill(EXIT_FAILURE);
	return (0);
}
