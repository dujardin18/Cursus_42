/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 16:52:56 by fherbine          #+#    #+#             */
/*   Updated: 2017/12/30 15:49:01 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printing_udecm(t_flags flags, uintmax_t n, int *a)
{
	int zeros;
	int tmp;
	int i;

	i = 0;
	zeros = 0;
	tmp = 0;
	if (flags.precision > ft_nlen_base(n, 10))
		zeros = flags.precision - ft_nlen_base(n, 10);
	else
	{
		if (flags.precision == -1 && ft_strchr(flags.flag, '0'))
		{
			zeros = flags.width - ft_nlen_base(n, 10);
			flags.width = 0;
		}
		else if (flags.precision == -1)
			flags.precision = ft_nlen_base(n, 10);
	}
	if (flags.width > ft_nlen_base(n, 10))
		tmp = (flags.precision > flags.width) ? 0 : flags.width - flags.precision;
	else
		flags.width = ft_nlen_base(n, 10);
	if (zeros + ft_nlen_base(n, 10) < flags.width)
		flags.width -= zeros;
	if (ft_strchr(flags.flag, '-'))
		tmp = 0;
	while (i < flags.width)
	{
		if (i == tmp)
		{
			(*a) += ft_put_nz(zeros);
			zeros = 0;
			ft_putnbr_base(n, "0123456789");
			(*a) += ft_nlen_base(n, 10) - 1;
			i += ft_nlen_base(n, 10) - 1;
		}
		else
			ft_putchar(flags.to_put);
		(*a)++;
		i++;
	}
}

void	ft_printing_udec(t_flags flags, uintmax_t n, int *a)
{
	if (flags.specifier == 'u')
		ft_printing_udecm(flags, n, a);
	else
		ft_printing_udecm(flags, (unsigned long)n, a);
}
