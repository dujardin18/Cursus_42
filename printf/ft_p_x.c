/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 18:37:52 by fherbine          #+#    #+#             */
/*   Updated: 2018/01/02 12:54:00 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flags	ft_ztaux(int *zeros, int *tmp, t_flags flags, uintmax_t n)
{
	if (flags.precision > ft_nlen_base(n, 16))
		*zeros = flags.precision - ft_nlen_base(n, 16);
	else
	{
		if (flags.precision == -1 && ft_strchr(flags.flag, '0') && \
				!ft_strchr(flags.flag, '-'))
		{
			*zeros = flags.width - ft_nlen_base(n, 16);
			flags.width = 0;
		}
		else if (flags.precision == -1)
			flags.precision = ft_nlen_base(n, 16);
	}
	if (flags.width > ft_nlen_base(n, 16) && flags.width > flags.precision)
		*tmp = (flags.precision <= 0 && n == 0) ? flags.width - \
			flags.precision : flags.width - ft_nlen_base(n, 16) - *zeros;
	else
		flags.width = ft_nlen_base(n, 16);
	flags.width -= (*zeros + ft_nlen_base(n, 16) < flags.width) ? *zeros : 0;
	*tmp = (ft_strchr(flags.flag, '-')) ? 0 : *tmp;
	return (flags);
}

static void		ft_putaux(int *i, int *a, t_flags flags, uintmax_t b[3])
{
	if (*i == (int)b[0])
	{
		if ((b[1] > 0 || flags.specifier == 'p') && ft_strchr(flags.flag, '#'))
		{
			(flags.specifier == 'X') ? ft_putstr("0X") : ft_putstr("0x");
			(*i) += 2;
			(*a) += 2;
		}
		if (!(flags.precision <= 0 && b[1] == 0))
		{
			(*a) += ft_put_nz((int)b[2]);
			b[2] = 0;
			(flags.specifier == 'X') ? ft_putnbr_base(b[1], "0123456789ABCDEF")\
				: ft_putnbr_base(b[1], "0123456789abcdef");
			(*a) += ft_nlen_base(b[1], 16) - 1;
		}
		else
			(*a)--;
		(*i) += ft_nlen_base(b[1], 16) - 1;
	}
	else
		ft_putchar(flags.to_put);
	(*a)++;
	(*i)++;
}

static void		ft_printing_hexm(t_flags flags, uintmax_t n, int *a)
{
	int			zeros;
	int			tmp;
	int			i;
	uintmax_t	bridge[3];

	i = 0;
	zeros = 0;
	tmp = 0;
	flags = ft_ztaux(&zeros, &tmp, flags, n);
	if (ft_strchr(flags.flag, '#'))
	{
		zeros -= (flags.precision > ft_nlen_base(n, 16)) ? 0 : 2;
		tmp = (tmp != 0) ? tmp - 2 : tmp;
	}
	bridge[0] = (uintmax_t)tmp;
	bridge[1] = n;
	bridge[2] = (uintmax_t)zeros;
	while (i < flags.width)
		ft_putaux(&i, a, flags, bridge);
}

void			ft_printing_hex(t_flags flags, uintmax_t n, int *a)
{
	if (flags.specifier == 'x' || flags.specifier == 'X')
		ft_printing_hexm(flags, ft_ucast_length(n, flags), a);
	else
		ft_printing_hexm(flags, n, a);
}
