/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 18:37:52 by fherbine          #+#    #+#             */
/*   Updated: 2017/12/30 17:51:10 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printing_hex(t_flags flags, uintmax_t n, int *a)
{
	int zeros;
	int tmp;
	int i;

	i = 0;
	zeros = 0;
	tmp = 0;
	if (flags.precision > ft_nlen_base(n, 16))
		zeros = flags.precision - ft_nlen_base(n, 16);
	else
	{
		if (flags.precision == -1 && ft_strchr(flags.flag, '0') && ft_strchr(flags.flag, '-') == NULL)
		{
			zeros = flags.width - ft_nlen_base(n, 16);
			flags.width = 0;
		}
		else if (flags.precision == -1)
			flags.precision = ft_nlen_base(n, 16);
	}
	if (flags.width > ft_nlen_base(n, 16) && flags.width > flags.precision)
		tmp = (flags.precision <= 0 && n == 0) ? flags.width - flags.precision : flags.width - ft_nlen_base(n, 16);
	else
		flags.width = ft_nlen_base(n, 16);
	if (zeros + ft_nlen_base(n, 16) < flags.width)
		flags.width -= zeros;
	if (ft_strchr(flags.flag, '-'))
		tmp = 0;
	if (ft_strchr(flags.flag, '#'))
	{
		zeros -= 2;
		tmp = (tmp != 0) ? tmp - 2 : tmp;
	}
	//	printf("f.w: %d, t: %d", flags.width, tmp);
	while (i < flags.width)
	{
		if (i == tmp)
		{
			if (n > 0 && ft_strchr(flags.flag, '#'))
			{
				(flags.specifier == 'x') ? ft_putstr("0x") : ft_putstr("0X");
				i += 2;
				(*a) += 2;
			}
			if (!(flags.precision <= 0 && n == 0))
			{
				(*a) += ft_put_nz(zeros);
				zeros = 0;
				(flags.specifier == 'x') ? ft_putnbr_base(n, "0123456789abcdef") : ft_putnbr_base(n, "0123456789ABCDEF");
				(*a) += ft_nlen_base(n, 16) - 1;
			}
			else
				(*a)--;
			i += ft_nlen_base(n, 16) - 1;
		}
		else
			ft_putchar(flags.to_put);
		(*a)++;
		i++;
	}
}
