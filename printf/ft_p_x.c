/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 18:37:52 by fherbine          #+#    #+#             */
/*   Updated: 2017/12/28 18:39:15 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printing_hex(t_flags flags, uintmax_t n, int *a)
{
	int i;
	int tmp;
	char t;

	i = 0;
	t = '#';
	tmp = 0;
	if (ft_strchr(flags.flag, '#'))
		t = (flags.specifier == 'X') ? 'X' : 'x';
	if (ft_nlen_base(n, 16) < (int)flags.width)
		tmp = (int)flags.width - ft_nlen_base(n, 16);
	else
		flags.width = ft_nlen_base(n, 16);
	if (ft_strchr(flags.flag, '-'))
		tmp = 0;
	else if (ft_strchr(flags.flag, '0'))
		flags.to_put = '0';
	if (flags.width > ft_nlen_base(n, 16) && (ft_strchr(flags.flag, '-') || flags.to_put == '0') && t != '#')
	{
		if (flags.to_put == '0')
			i += 2;
		else
			(flags.width) -= 2;
		ft_putchar('0');
		ft_putchar(t);
		t = '#';
		(*a) += 2;
	}
	else if (t != '#')
	{
		(flags.width) -= 2;
		if (flags.width > ft_nlen_base(n, 16))
			tmp -= 2;
		(*a) += 2;
	}
	while (i < flags.width)
	{
		if (tmp == i)
		{
			if (t != '#')
			{
				ft_putchar('0');
				ft_putchar(t);
			}
			(flags.specifier == 'x') ? ft_putnbr_base(n, "0123456789abcdef") : ft_putnbr_base(n, "0123456789ABCDEF");
			i += (ft_nlen_base(n, 16) - 1);
			(*a) += (ft_nlen_base(n, 16) - 1);
		}
		else
			ft_putchar(flags.to_put);
		i++;
		(*a)++;
	}
}
