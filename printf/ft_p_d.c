/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 13:49:41 by fherbine          #+#    #+#             */
/*   Updated: 2018/01/02 14:41:39 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flags	ft_ztaux(int *zeros, int *tmp, t_flags flags, uintmax_t n)
{
	if (flags.precision > ft_nlen_10(n))
		*zeros = flags.precision - ft_nlen_10(n);
	else
	{
		if (flags.precision == -1 && ft_strchr(flags.flag, '0') && \
				!ft_strchr(flags.flag, '-'))
		{
			*zeros = flags.width - ft_nlen_10(n);
			flags.width = 0;
		}
		else if (flags.precision == -1)
			flags.precision = ft_nlen_10(n);
	}
	if (flags.width > ft_nlen_10(n) && flags.width > flags.precision)
		*tmp = (flags.precision <= 0 && n == 0) ? flags.width - \
			flags.precision : flags.width - ft_nlen_10(n) - *zeros;
	else
		flags.width = ft_nlen_10(n);
	if (*zeros + ft_nlen_10(n) < flags.width && *zeros > 0)
		flags.width -= (ft_strchr(flags.flag, '+') || \
				ft_strchr(flags.flag, ' ')) ? *zeros : *zeros - 1;
	*tmp = (ft_strchr(flags.flag, '-')) ? 0 : *tmp;
	if (ft_strchr(flags.flag, ' ') || ft_strchr(flags.flag, '+'))
		*tmp -= (*tmp > 0) ? 1 : 0;
	return (flags);
}

static void		ft_putaux(int *i, int *a, t_flags flags, intmax_t b[2])
{
	if (b[0] >= 0 && (ft_strchr(flags.flag, '+') || ft_strchr(flags.flag, ' ')))
	{
		if (ft_strchr(flags.flag, '+'))
			ft_putchar('+');
		else if (ft_strchr(flags.flag, ' '))
			ft_putchar(' ');
		if (flags.precision <= ft_nlen_10(b[0]) && ft_strchr(flags.flag, '0'))
			(b[1])--;
		(*a)++;
	}
	if (!(flags.precision == 0 && b[0] == 0) || flags.specifier == 'D')
	{
		ft_putnbr_z(b[0], (int *)&(b[1]), a);
		(*i) += (flags.precision > ft_nlen_10(b[0])) ? (flags.precision \
				- ft_nlen_10(b[0])) : 0;
		(*a) += ft_nlen_10(b[0]) - 1;
	}
	else
		(*a)--;
	(*i) += ft_nlen_10(b[0]) - 1;
}

static void		ft_printing_decm(t_flags flags, intmax_t n, int *a)
{
	int			zeros;
	int			tmp;
	int			i;
	intmax_t	bridge[2];

	i = 0;
	zeros = 0;
	tmp = 0;
	flags.precision += (n < 0 && flags.precision != -1) ? 1 : 0;
	flags = ft_ztaux(&zeros, &tmp, flags, n);
	bridge[0] = n;
	bridge[1] = (intmax_t)zeros;
	while (i < flags.width)
	{
		if (i == tmp)
			ft_putaux(&i, a, flags, bridge);
		else
			ft_putchar(flags.to_put);
		(*a)++;
		i++;
	}
}

void			ft_printing_dec(t_flags flags, intmax_t n, int *a)
{
	if (flags.specifier == 'd' || flags.specifier == 'i')
		ft_printing_decm(flags, ft_cast_length(n, flags), a);
	else
		ft_printing_decm(flags, (long)n, a);
}
