/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 17:39:40 by fherbine          #+#    #+#             */
/*   Updated: 2017/11/11 17:40:41 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_recv(int n)
{
	if (n >= 10)
	{
		ft_putnbr_recv(n / 10);
		ft_putnbr_recv(n % 10);
	}
	else
		ft_putchar(n + 48);
}

void		ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		if (n == -2147483648)
		{
			ft_putnbr(214748364);
			ft_putchar('8');
		}
		else
			ft_putnbr_recv(n * -1);
	}
	else
		ft_putnbr_recv(n);
}
