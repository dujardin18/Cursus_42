/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 20:26:14 by fherbine          #+#    #+#             */
/*   Updated: 2017/12/28 17:50:59 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_printing_oct(t_flags flags, uintmax_t n, int *a)
{
	int i;
	int tmp;
	char t;

	i = 0;
	t = '#';
	tmp = 0;
	if (ft_strchr(flags.flag, '#'))
		t = '0';
	if (ft_nlen_base(n, 8) < (int)flags.width)
		tmp = (int)flags.width - ft_nlen_base(n, 8);
	else
		flags.width = ft_nlen_base(n, 8);
	if (ft_strchr(flags.flag, '-'))
		tmp = 0;
	else if (ft_strchr(flags.flag, '0'))
		flags.to_put = '0';
		if (flags.width > ft_nlen_base(n, 8) && (ft_strchr(flags.flag, '-') || flags.to_put == '0') && t != '#')
		{
			if (flags.to_put == '0')
				i += 1;
			else
				(flags.width)--;
			ft_putchar(t);
			t = '#';
			(*a)++;
		}
		else if (t != '#')
		{
			(flags.width)--;
			if (flags.width > ft_nlen_base(n, 8))
				tmp -= 1;
			(*a)++;
		}
	while (i < flags.width)
	{
		if (tmp == i)
		{
			if (t != '#')
				ft_putchar(t);
			ft_putnbr_base(n, "01234567");
			i += (ft_nlen_base(n, 8) - 1);
			(*a) += (ft_nlen_base(n, 8) - 1);
		}
		else
			ft_putchar(flags.to_put);
		i++;
		(*a)++;
	}
}
