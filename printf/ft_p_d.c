/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 13:49:41 by fherbine          #+#    #+#             */
/*   Updated: 2017/12/29 17:09:49 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printing_dec(t_flags flags, intmax_t n, int *a)
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
	if ((ft_strchr(flags.flag, ' ') || ft_strchr(flags.flag, '+')) && tmp != 0)
		tmp--;
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
				i++;
				(*a)++;
			}
			(*a) += ft_put_nz(zeros);
			zeros = 0;
			ft_putnbr(n);
			(*a) += ft_nlen_base(n, 10) - 1;
			i += ft_nlen_base(n, 10) - 1;
		}
		else
			ft_putchar(flags.to_put);
		(*a)++;
		i++;
	}
}
