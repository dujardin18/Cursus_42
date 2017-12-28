/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchiche <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:15:54 by dchiche           #+#    #+#             */
/*   Updated: 2017/11/12 20:27:18 by dchiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*tab;

	i = 0;
	tab = (unsigned char *)b;
	while (i < len)
	{
		tab[i] = (unsigned char)c;
		i++;
	}
	return ((void *)b);
}
