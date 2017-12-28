/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 14:59:05 by fherbine          #+#    #+#             */
/*   Updated: 2017/12/28 18:36:48 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void  ft_printing_char(t_flags flags, int c, int *n)
{
	int i;

	i = 0;
	if (flags.width > 0)
		(flags.width)--;
	if (ft_strchr(flags.flag, '0'))
		flags.to_put = '0';
	if (ft_strchr(flags.flag, '-'))
		i = flags.width;
	while (flags.width >= 0)
	{
		if (flags.width == i)
			ft_putchar((char)c);
		else
			ft_putchar(flags.to_put);
		(flags.width)--;
		(*n)++;
	}
}
