/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 13:49:41 by fherbine          #+#    #+#             */
/*   Updated: 2017/12/30 19:18:53 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printing_decm(t_flags flags, intmax_t n, int *a)
{
	int zeros;
	int tmp;
	int i;

	i = 0;
	zeros = 0;
	tmp = 0;
	flags.precision += (n < 0 && flags.precision != -1) ? 1 : 0;
	if (flags.precision > ft_nlen_10(n))
		zeros = flags.precision - ft_nlen_10(n);
	else
	{
		if (flags.precision == -1 && ft_strchr(flags.flag, '0') && ft_strchr(flags.flag, '-') == NULL)
		{
			zeros = flags.width - ft_nlen_10(n);
			flags.width = 0;
		}
		else if (flags.precision == -1)
			flags.precision = ft_nlen_10(n);
	}
	if (flags.width > ft_nlen_10(n))
		tmp = (flags.precision > flags.width) ? 0 : flags.width - flags.precision;
	else
		flags.width = ft_nlen_10(n);
	if (zeros + ft_nlen_10(n) < flags.width && zeros > 0)
		flags.width -= (ft_strchr(flags.flag, '+') || ft_strchr(flags.flag, ' ')) ?  zeros : zeros - 1;
	if (ft_strchr(flags.flag, '-'))
		tmp = 0;
	if (ft_strchr(flags.flag, ' ') || ft_strchr(flags.flag, '+'))
	{
		//zeros -= (n > 0 && ft_strchr(flags.flag, '0') && flags.precision <= ft_nlen_10(n)) ? 1 : 0;
		tmp -= (tmp > 0) ?  1 : 0;
	}
	while (i < flags.width)
	{
		if (i == tmp)
		{
			if (n >= 0 && (ft_strchr(flags.flag, '+') || ft_strchr(flags.flag, ' ')))
			{
				if (ft_strchr(flags.flag, '+'))
					ft_putchar('+');
				else if (ft_strchr(flags.flag, ' '))
					ft_putchar(' ');
				if (flags.precision <= ft_nlen_10(n) && ft_strchr(flags.flag, '0'))
					zeros--;
				//i++;
				(*a)++;
			}
			//(*a) += ft_put_nz(zeros);
			//zeros = 0;
			if (!(flags.precision == 0 && n == 0 && flags.specifier == 'd'))
			{
				ft_putnbr_z(n, &zeros, a);
				i += (flags.precision > ft_nlen_10(n)) ? (flags.precision - ft_nlen_10(n)) : 0;
				(*a) += ft_nlen_10(n) - 1;
			}
			else
				(*a)--;
			i += ft_nlen_10(n) - 1;
		}
		else
			ft_putchar(flags.to_put);
		(*a)++;
		i++;
	}
}

void	ft_printing_dec(t_flags flags, intmax_t n, int *a)
{
	if (flags.specifier == 'd')
		ft_printing_decm(flags, n, a);
	else
		ft_printing_decm(flags, (long)n, a);
}
