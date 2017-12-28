/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchiche <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:14:53 by dchiche           #+#    #+#             */
/*   Updated: 2017/11/15 13:01:50 by dchiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_iter(const char *s, size_t i)
{
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	return (i);
}

static size_t	ft_iter2(const char *s, int i)
{
	while (s[i])
		i++;
	i--;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i--;
	return (i);
}

char			*ft_strtrim(char const *s)
{
	char	*tab;
	size_t	i;
	size_t	start;
	size_t	end;

	i = 0;
	if (!s)
		return (0);
	i = ft_iter(s, i);
	if (ft_strlen(s) == i)
		return (ft_strnew(0));
	start = i;
	i = ft_iter2(s, i);
	end = i;
	if (!(tab = (char *)malloc(sizeof(char) * (end - start + 2))))
		return (NULL);
	i = 0;
	while (start <= end)
	{
		tab[i] = s[start];
		i++;
		start++;
	}
	tab[i] = '\0';
	return (tab);
}
