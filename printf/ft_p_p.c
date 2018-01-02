/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 21:06:06 by fherbine          #+#    #+#             */
/*   Updated: 2018/01/02 10:38:55 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printing_ptr(t_flags flags, void *p, int *n)
{
	int		i;

	i = 0;
	while (flags.flag[i] != '\0' && flags.flag[i] != '#')
		i++;
	if (flags.flag[i] == '\0')
	{
		flags.flag[i] = '#';
		flags.flag[i + 1] = '\0';
	}
	ft_printing_hex(flags, (uintmax_t)p, n);
}
