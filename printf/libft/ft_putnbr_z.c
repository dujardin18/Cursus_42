/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_z.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 12:59:15 by fherbine          #+#    #+#             */
/*   Updated: 2018/01/02 10:36:57 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_pnz(int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		ft_putchar('0');
		i++;
	}
	return (i);
}

static void	ft_putnbr_recv(unsigned long long n)
{
	if (n >= 10)
	{
		ft_putnbr_recv(n / 10);
		ft_putnbr_recv(n % 10);
	}
	else
		ft_putchar(n + 48);
}

void		ft_putnbr_z(intmax_t n, int *zeros, int *a)
{
	if (n < 0)
	{
		ft_putchar('-');
		(*a) += ft_pnz(*zeros);
		*zeros = 0;
		ft_putnbr_recv((unsigned long long)n * -1);
	}
	else
	{
		(*a) += ft_pnz(*zeros);
		*zeros = 0;
		ft_putnbr_recv(n);
	}
}
