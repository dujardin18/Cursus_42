/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 17:05:30 by fherbine          #+#    #+#             */
/*   Updated: 2017/11/12 18:43:44 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_strrev(char *str)
{
	size_t	s;
	size_t	e;
	char	tmp;

	s = 0;
	e = ft_strlen(str) - 1;
	while (s <= e)
	{
		tmp = str[s];
		str[s] = str[e];
		str[e] = tmp;
		s++;
		e--;
	}
	return (str);
}

static	int		ft_nlen(long *n, int *neg)
{
	size_t	len;
	long	tmp;

	len = 0;
	if (*n < 0)
	{
		len++;
		*n = *n * -1;
		*neg = 1;
	}
	tmp = *n;
	while (tmp >= 10)
	{
		tmp = tmp / 10;
		len++;
	}
	len++;
	return (len);
}

char			*ft_itoa(int n)
{
	char	*ret;
	int		neg;
	size_t	len;
	size_t	i;
	long	nb;

	nb = (long)n;
	neg = 0;
	i = 0;
	len = ft_nlen(&nb, &neg);
	if ((ret = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	while (nb >= 10)
	{
		ret[i] = nb % 10 + 48;
		i++;
		nb = nb / 10;
	}
	ret[i] = nb + 48;
	if (neg == 1)
		ret[i + 1] = '-';
	ret[len] = '\0';
	if (len > 1)
		ft_strrev(ret);
	return (ret);
}
