/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 17:39:40 by fherbine          #+#    #+#             */
/*   Updated: 2017/12/29 17:16:20 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_recv(intmax_t n)
{
	if (n >= 10)
	{
		ft_putnbr_recv(n / 10);
		ft_putnbr_recv(n % 10);
	}
	else
		ft_putchar(n + 48);
}

void		ft_putnbr(intmax_t n)
{
	if (n < 0)
	{
		ft_putchar('-');
		//if (n == -9223372036854775808)
		//{
		//	ft_putnbr(922337203685477580);
		//	ft_putchar('8');
		//}
		//else
			ft_putnbr_recv(n * -1);
	}
	else
		ft_putnbr_recv(n);
}
