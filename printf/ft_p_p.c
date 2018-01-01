/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 21:06:06 by fherbine          #+#    #+#             */
/*   Updated: 2018/01/01 17:03:26 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printing_ptr(t_flags flags, void *p, int *n)
{
	int i;

	i = 0;
	//flags.specifier = 'x';
	while (flags.flag[i] != '\0' && flags.flag[i] != '#')
		i++;
//	if (flags.precision > 0)
//		(flags.precision) += 2;
	if (flags.flag[i] == '\0')
	{
		flags.flag[i] = '#';
		flags.flag[i + 1] = '\0';
	}
	ft_printing_hex(flags, (uintmax_t)p, n);
}
