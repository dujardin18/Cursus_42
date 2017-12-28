/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchiche <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:53:56 by dchiche           #+#    #+#             */
/*   Updated: 2017/11/15 13:11:10 by dchiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nb_words(char *str, char c)
{
	int		nb;
	int		i;

	i = 0;
	nb = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] == '\0')
			return (nb);
		nb++;
		while (str[i] != c && str[i] != '\0')
			i++;
		i++;
	}
	return (nb);
}

static char		*ft_strdup_c(const char *str, char c)
{
	int		i;
	char	*tab;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	if (!(tab = (char *)malloc(sizeof(tab) * (i + 1))))
		return (NULL);
	i = 0;
	while (str[i] != c && str[i] != '\0')
	{
		tab[i] = str[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

static char		**ft_aux(const char *s, char c, int x, char **res)
{
	int		i;

	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
		{
			res[x] = 0;
			return (res);
		}
		if (s[i] != c)
		{
			res[x] = ft_strdup_c(s + i, c);
			x++;
		}
		while (s[i] != c && s[i] != '\0')
			i++;
		if (s[i] != '\0')
			i++;
	}
	res[x] = 0;
	return (res);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		word;
	int		x;

	x = 0;
	if (s == 0)
		return (0);
	word = ft_nb_words((char *)s, c);
	if (!(res = (char **)malloc(sizeof(*res) * word + 2)))
		return (NULL);
	res = ft_aux(s, c, x, res);
	return (res);
}
