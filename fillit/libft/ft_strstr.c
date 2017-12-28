/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchiche <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:39:34 by dchiche           #+#    #+#             */
/*   Updated: 2017/11/14 15:52:49 by dchiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t t;
	size_t a;
	size_t b;

	a = 0;
	b = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[a])
	{
		t = a;
		b = 0;
		while (needle[b] == haystack[t])
		{
			b++;
			t++;
			if (needle[b] == '\0')
				return ((char *)haystack + a);
		}
		a++;
	}
	return (0);
}
