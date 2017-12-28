/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchiche <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 18:18:24 by dchiche           #+#    #+#             */
/*   Updated: 2017/11/15 12:33:53 by dchiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nblen(int nb, int i)
{
	while (nb >= 10)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	int		i;
	long	nb;
	char	*tab;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	nb = (n < 0) ? -n : n;
	i = (n < 0) ? 2 : 1;
	i = ft_nblen(nb, i);
	if (!(tab = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	nb = (n < 0) ? -n : n;
	i = 0;
	while (nb >= 10)
	{
		tab[i++] = nb % 10 + '0';
		nb = nb / 10;
	}
	tab[i++] = nb + '0';
	if (n < 0)
		tab[i++] = '-';
	tab[i] = '\0';
	return (ft_strrev(tab));
}
