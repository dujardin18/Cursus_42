/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 20:26:14 by fherbine          #+#    #+#             */
/*   Updated: 2017/12/29 16:25:24 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printing_oct(t_flags flags, uintmax_t n, int *a)
{
	int zeros;
	int tmp;
	int i;

	i = 0;
	zeros = 0;
	tmp = 0;
	if (flags.precision > ft_nlen_base(n, 8))
		zeros = flags.precision - ft_nlen_base(n, 8);
	else
	{
		if (flags.precision == -1 && ft_strchr(flags.flag, '0') && ft_strchr(flags.flag, '-') == NULL)
		{
			zeros = flags.width - ft_nlen_base(n, 8);
			flags.width = 0;
		}
		else if (flags.precision == -1)
			flags.precision = ft_nlen_base(n, 8);
	}
	if (flags.width > ft_nlen_base(n, 8))
		tmp = (flags.precision > flags.width) ? 0 : flags.width - flags.precision;
	else
		flags.width = ft_nlen_base(n, 8);
	if (zeros + ft_nlen_base(n, 8) < flags.width)
		flags.width -= zeros;
	if (ft_strchr(flags.flag, '-'))
		tmp = 0;
	if (ft_strchr(flags.flag, '#'))
	{
		tmp = (tmp != 0) ? tmp - 1: tmp;
		zeros--;
	}
	while (i < flags.width)
	{
		if (i == tmp)
		{
			if (n > 0 && ft_strchr(flags.flag, '#'))
			{
				ft_putchar('0');
				i++;
				(*a)++;
			}
			(*a) += ft_put_nz(zeros);
			zeros = 0;
			ft_putnbr_base(n, "01234567");
			(*a) += ft_nlen_base(n, 8) - 1;
			i += ft_nlen_base(n, 8) - 1;
		}
		else
			ft_putchar(flags.to_put);
		(*a)++;
		i++;
	}
}
