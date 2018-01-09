/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:11:25 by fherbine          #+#    #+#             */
/*   Updated: 2018/01/09 17:09:31 by fherbine         ###   ########.fr       */
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
///////////////////////////////// EOD

int		main(int argc, char **argv)
{
	t_pile	*pile_a;
	t_pile	*pile_b;

	pile_b = NULL;
	pile_a = ft_parser(argc, argv);
	//ft_display_list(pile_a);
	ft_check_piles(pile_a, pile_b);

	free(pile_a);
	free(pile_b);
	return (0);
}
