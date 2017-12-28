/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 19:58:27 by fherbine          #+#    #+#             */
/*   Updated: 2017/12/11 14:54:02 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_putnbr_base_recv(size_t n, char *base, size_t b)
{
	if (n >= b)
	{
		ft_putnbr_base_recv(n / b, base, b);
		ft_putnbr_base_recv(n % b, base, b);
	}
	else
		ft_putchar(base[n]);
}

void			ft_putnbr_base(int n, char *base)
{
	size_t b;

	b = ft_strlen(base);
	if (n < 0)
	{
		if (n == -2147483648)
		{
			ft_putnbr_base(-2147483, base);
			ft_putnbr_base(648, base);
		}
		else
		{
			ft_putchar('-');
			ft_putnbr_base(n * -1, base);
		}
	}
	else
		ft_putnbr_base_recv((size_t)n, base, b);
}
