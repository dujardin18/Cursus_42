/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_nz.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 14:03:18 by fherbine          #+#    #+#             */
/*   Updated: 2017/12/29 14:26:05 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_nz(int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		ft_putchar('0');
		i++;
	}
	return (i);
}
