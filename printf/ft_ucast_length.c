/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ucast_length.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 15:19:17 by fherbine          #+#    #+#             */
/*   Updated: 2017/12/27 15:19:20 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t	ft_ucast_length(uintmax_t n, t_flags flags)
{
	if (flags.length == hh)
		return ((unsigned char)n);
	else if (flags.length == h)
		return ((unsigned short)n);
	else if (flags.length == l)
		return ((unsigned long)n);
	else if (flags.length == ll)
		return ((unsigned long long)n);
	else if (flags.length == j)
		return (n);
	else if (flags.length == z)
		return ((size_t)n);
	return (n);
}
