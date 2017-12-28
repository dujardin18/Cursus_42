/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_length.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 15:27:45 by fherbine          #+#    #+#             */
/*   Updated: 2017/12/27 15:34:33 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	ft_cast_length(intmax_t n, t_flags flags)
{
	if (flags.length == hh)
		return ((signed char)n);
	else if (flags.length == h)
		return ((short)n);
	else if (flags.length == l)
		return ((long)n);
	else if (flags.length == ll)
		return ((long long)n);
	else if (flags.length == j)
		return (n);
	else if (flags.length == z)
		return ((size_t)n);
	return (n);
}
