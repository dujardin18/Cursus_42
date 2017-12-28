/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 17:22:06 by fherbine          #+#    #+#             */
/*   Updated: 2017/11/28 16:35:42 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "babab.h"

static int			*ft_aux(char **tab, int x, int y, int *i)
{
	if (x + 1 < 4 && tab[y][x + 1] == '#')
		i[0]++;
	if (x - 1 >= 0 && tab[y][x - 1] == '#')
		i[0]++;
	if (y + 1 < 4 && tab[y + 1][x] == '#')
		i[0]++;
	if (y - 1 >= 0 && tab[y - 1][x] == '#')
		i[0]++;
	i[1]++;
	return (i);
}

static int			ft_is_tetri(char **tab)
{
	int				x;
	int				y;
	int				i[2];

	y = 0;
	i[0] = 0;
	i[1] = 0;
	while (tab[y])
	{
		x = 0;
		while (tab[y][x])
		{
			if ((tab[y][x] != '.' && tab[y][x] != '#') || (tab[y][x] == '#'
				&& (x > 2 || tab[y][x + 1] == '.') && (x < 1 ||
				tab[y][x - 1] == '.') && (y > 2 || tab[y + 1][x] == '.')
				&& (y < 1 || tab[y - 1][x] == '.')))
				return (0);
			else if (tab[y][x] == '#')
				ft_memcpy(i, ft_aux(tab, x, y, i), 2);
			x++;
		}
		y++;
	}
	return (((i[0] == 6 || i[0] == 8) && i[1] == 4) ? 1 : 0);
}

static char			**ft_put_up_left(char **tab, int x, int y)
{
	int				i;
	int				i2;
	int				tmp;
	char			**tab2;

	i = 0;
	i2 = 0;
	tab2 = ft_malloc_square(tab, 4);
	tmp = x;
	while (i < 4)
	{
		while (i2 < 4)
		{
			if (y < 4 && x < 4)
				tab2[i][i2] = tab[y][x];
			i2++;
			x++;
		}
		i2 = 0;
		i++;
		x = tmp;
		y++;
	}
	return (tab2);
}

static char			**ft_up_left(char **tab)
{
	int				x;
	int				y;
	int				i;
	int				i2;

	x = 5;
	y = 5;
	i = 0;
	i2 = 0;
	while (tab[i])
	{
		while (tab[i][i2])
		{
			if (tab[i][i2] != '.' && i2 < x)
				x = i2;
			if (tab[i][i2] != '.' && i < y)
				y = i;
			i2++;
		}
		i2 = 0;
		i++;
	}
	return (ft_put_up_left(tab, x, y));
}

t_tt_list			*ft_tetri(int fd)
{
	size_t			i2;
	char			*buf;
	char			**tab;
	t_tt_list		*list;
	char			tmp;

	i2 = 0;
	list = NULL;
	if (!(buf = (char *)ft_memalloc(sizeof(char) * 22)))
		return (NULL);
	while (read(fd, buf, 21) != 0 && (list != NULL || i2 == 0))
	{
		tmp = buf[20];
		if (!(tab = ft_new_tab(buf)))
			return (NULL);
		free(buf);
		if (!(buf = (char *)ft_memalloc(sizeof(char) * 22)))
			return (NULL);
		if (!(tab = ft_up_left(tab)))
			return (NULL);
		list = (ft_is_tetri(tab) == 1) ? ft_add_tts(list, tab, i2) : NULL;
		i2++;
	}
	return ((tmp != '\0') ? NULL : list);
}
