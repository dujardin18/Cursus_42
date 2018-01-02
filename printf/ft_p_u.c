/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 16:52:56 by fherbine          #+#    #+#             */
/*   Updated: 2018/01/02 13:21:53 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flags	ft_ztaux(int *zeros, int *tmp, t_flags flags, uintmax_t n)
{
	if (flags.precision > ft_nlen_base(n, 10))
		*zeros = flags.precision - ft_nlen_base(n, 10);
	else
	{
		if (flags.precision == -1 && ft_strchr(flags.flag, '0'))
		{
			*zeros = flags.width - ft_nlen_base(n, 10);
			flags.width = 0;
		}
		else if (flags.precision == -1)
			flags.precision = ft_nlen_base(n, 10);
	}
	if (flags.width > ft_nlen_base(n, 10) && flags.width > flags.precision)
		*tmp = (flags.precision <= 0 && n == 0) ? flags.width - \
			flags.precision : flags.width - ft_nlen_base(n, 10) - *zeros;
	else
		flags.width = ft_nlen_base(n, 10);
	flags.width -= (*zeros + ft_nlen_base(n, 10) < flags.width) ? *zeros : 0;
	*tmp = (ft_strchr(flags.flag, '-')) ? 0 : *tmp;
	return (flags);
}

static void		ft_putaux(int *i, int *a, t_flags flags, uintmax_t b[3])
{
	while (*i < flags.width)
	{
		if (*i == (int)b[0])
		{
			if (!(flags.precision <= 0 && b[1] == 0))
			{
				(*a) += ft_put_nz(b[2]);
				b[2] = 0;
				ft_putnbr_base(b[1], "0123456789");
				(*a) += ft_nlen_base(b[1], 10) - 1;
			}
			else
				(*a)--;
			(*i) += ft_nlen_base(b[1], 10) - 1;
		}
		else
			ft_putchar(flags.to_put);
		(*a)++;
		(*i)++;
	}
}

static void		ft_printing_udecm(t_flags flags, uintmax_t n, int *a)
{
	int			zeros;
	int			tmp;
	int			i;
	uintmax_t	bridge[3];

	i = 0;
	zeros = 0;
	tmp = 0;
	flags = ft_ztaux(&zeros, &tmp, flags, n);
	bridge[0] = (uintmax_t)tmp;
	bridge[1] = n;
	bridge[2] = (uintmax_t)zeros;
	ft_putaux(&i, a, flags, bridge);
}

void			ft_printing_udec(t_flags flags, uintmax_t n, int *a)
{
	if (flags.specifier == 'u')
		ft_printing_udecm(flags, ft_ucast_length(n, flags), a);
	else
		ft_printing_udecm(flags, (unsigned long)n, a);
}
