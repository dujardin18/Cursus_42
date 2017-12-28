/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 10:17:33 by fherbine          #+#    #+#             */
/*   Updated: 2017/11/07 16:25:06 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int len;
	int i;
	int *tab;

	if (max <= min)
		return (0);
	else
	{
		len = max - min;
		i = 0;
		if ((tab = (int *)malloc(sizeof(int) * len)) == NULL)
			return (NULL);
		while (i < len)
		{
			tab[i] = min;
			i++;
			min++;
		}
		return (tab);
	}
}
