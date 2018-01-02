/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 20:26:14 by fherbine          #+#    #+#             */
/*   Updated: 2018/01/02 14:19:07 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flags	ft_ztaux(int *zeros, int *tmp, t_flags flags, uintmax_t n)
{
	if (flags.precision > ft_nlen_base(n, 8))
		*zeros = flags.precision - ft_nlen_base(n, 8);
	else
	{
		if (flags.precision == -1 && ft_strchr(flags.flag, '0') && \
				!ft_strchr(flags.flag, '-'))
		{
			*zeros = flags.width - ft_nlen_base(n, 8);
			flags.width = 0;
		}
		else if (flags.precision == -1)
			flags.precision = ft_nlen_base(n, 8);
	}
	if (flags.width > ft_nlen_base(n, 8) && flags.width > flags.precision)
		*tmp = (flags.precision <= 0 && n == 0) ? flags.width - \
			flags.precision : flags.width - ft_nlen_base(n, 8) - *zeros;
	else
		flags.width = ft_nlen_base(n, 8);
	flags.width -= (*zeros + ft_nlen_base(n, 8) < flags.width) ? *zeros : 0;
	*tmp = (ft_strchr(flags.flag, '-')) ? 0 : *tmp;
	return (flags);
}

static void		ft_putaux(int *i, int *a, t_flags flags, uintmax_t b[3])
{
	if (*i == (int)b[0])
	{
		if (b[1] > 0 && ft_strchr(flags.flag, '#'))
		{
			ft_putchar('0');
			(*i)++;
			(*a)++;
		}
		if (!(flags.precision <= 0 && b[1] == 0) || ft_strchr(flags.flag, '#'))
		{
			(*a) += ft_put_nz(b[2]);
			b[2] = 0;
			ft_putnbr_base(b[1], "01234567");
			(*a) += ft_nlen_base(b[1], 8) - 1;
		}
		else
			(*a)--;
		(*i) += ft_nlen_base(b[1], 8) - 1;
	}
	else
		ft_putchar(flags.to_put);
	(*a)++;
	(*i)++;
}

static void		ft_printing_octm(t_flags flags, uintmax_t n, int *a)
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
		tmp = (tmp != 0) ? tmp - 1 : tmp;
		zeros--;
	}
	bridge[0] = (uintmax_t)tmp;
	bridge[1] = n;
	bridge[2] = (uintmax_t)zeros;
	while (i < flags.width)
		ft_putaux(&i, a, flags, bridge);
}

void			ft_printing_oct(t_flags flags, uintmax_t n, int *a)
{
	if (flags.specifier == 'o')
		ft_printing_octm(flags, ft_ucast_length(n, flags), a);
	else
		ft_printing_octm(flags, (unsigned long)n, a);
}
