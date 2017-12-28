/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_table.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchiche <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:26:35 by dchiche           #+#    #+#             */
/*   Updated: 2017/11/16 16:25:32 by dchiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort_int_table(int *tab, int size)
{
	int a;
	int t;
	int b;

	a = 0;
	b = 0;
	while (a < size - b - 1)
	{
		while (a < size - 1)
		{
			if (tab[a] > tab[a + 1])
			{
				t = tab[a];
				tab[a] = tab[a + 1];
				tab[a + 1] = t;
			}
			a++;
		}
		b++;
		a = 0;
	}
}
