/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:27:59 by fherbine          #+#    #+#             */
/*   Updated: 2017/11/14 11:51:28 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*joined;
	size_t	len;
	size_t	i;
	size_t	i2;

	i = 0;
	i2 = 0;
	if (!(s1) || !(s2))
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) - 1;
	if ((joined = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		joined[i] = s1[i];
		i++;
	}
	while (i2 < ft_strlen(s2))
	{
		joined[i] = s2[i2];
		i++;
		i2++;
	}
	joined[i] = '\0';
	return (joined);
}
