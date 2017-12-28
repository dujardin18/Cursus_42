/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 19:55:53 by fherbine          #+#    #+#             */
/*   Updated: 2017/11/25 20:19:33 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "babab.h"

static	size_t	ft_nb_elem(t_tt_list *list)
{
	size_t		i;

	while (list != NULL)
	{
		i = list->i;
		list = list->next;
	}
	return (i);
}

size_t			ft_square_min(t_tt_list *list)
{
	size_t		n;

	n = (ft_nb_elem(list) + 1) * 4;
	while (ft_sqrt(n) == 0)
		n++;
	n = ft_sqrt(n);
	return (n);
}

char			**ft_make_square(size_t n)
{
	size_t		y;
	size_t		x;
	char		**square;

	y = 0;
	x = 0;
	if (!(square = (char **)malloc(sizeof(char *) * (n + 1))))
		return (NULL);
	while (y < n)
	{
		if (!(square[y] = (char *)malloc(sizeof(char) * (n + 1))))
			return (NULL);
		while (x < n)
		{
			square[y][x] = '.';
			x++;
		}
		square[y][x] = '\0';
		y++;
		x = 0;
	}
	square[y] = 0;
	return (square);
}

char			**ft_malloc_square(char **square, int size)
{
	int			i;
	int			i2;

	i = 0;
	i2 = 0;
	if (!(square = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		if (!(square[i] = (char *)malloc(sizeof(char) * (size + 1))))
			return (NULL);
		while (i2 < size)
		{
			square[i][i2] = '.';
			i2++;
		}
		square[i][i2] = '\0';
		i++;
		i2 = 0;
	}
	square[i] = 0;
	return (square);
}

size_t			ft_nline(char *str)
{
	size_t		i;
	size_t		n;

	i = 0;
	n = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			n++;
		i++;
	}
	return (n);
}
