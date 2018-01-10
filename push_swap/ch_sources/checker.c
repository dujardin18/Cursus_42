/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:12:46 by fherbine          #+#    #+#             */
/*   Updated: 2018/01/10 15:22:43 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ch_includes/checker.h"

int		ft_check_piles(t_pile *pile_a, t_pile *pile_b)
{
	t_order	*orders;

	orders = ft_instructions();
	ft_display_list2(orders);
	ft_putendl("PILE A:");
	ft_display_list(pile_a);
	ft_putendl("PILE B:");
	ft_display_list(pile_b);
	ft_putendl("--------");
	ft_do_actions(orders, &pile_a, &pile_b);
	ft_putendl("PILE A:");
	ft_display_list(pile_a);
	ft_putendl("PILE B:");
	ft_display_list(pile_b);
	free(orders);
	if (ft_pile_is_sorted(pile_a) && !pile_b)
	{
		free(pile_a);
		free(pile_b);
		ft_kill(EXIT_SUCCESS);
	}
	return (0);
}
