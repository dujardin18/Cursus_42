/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchiche <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 17:30:24 by dchiche           #+#    #+#             */
/*   Updated: 2017/11/14 20:59:15 by dchiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t len;
	size_t ret;

	i = 0;
	j = 0;
	ret = ft_strlen(dst);
	len = size - 1;
	if (size > ret)
	{
		while (dst[i])
			i++;
		while (src[j] && j + i < len)
		{
			dst[i + j] = src[j];
			j++;
		}
		dst[i + j] = '\0';
		return (ret + ft_strlen(src));
	}
	return (ft_strlen(src) + size);
}
