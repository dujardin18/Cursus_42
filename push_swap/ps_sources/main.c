/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:09:26 by fherbine          #+#    #+#             */
/*   Updated: 2018/01/15 17:22:08 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ps_includes/push_swap.h"

int			main(int argc, char **argv)
{
	t_pile	*pile_a;
	t_pile	*pile_b;

	pile_b = NULL;
	pile_b = ft_malloc_secure(pile_b);
	pile_b = NULL;
	pile_a = ft_parser(argc, argv);
	ft_push_swap(pile_a, pile_b);
	return (0);
}
