/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 17:22:02 by fherbine          #+#    #+#             */
/*   Updated: 2017/11/27 10:55:07 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "babab.h"

static	int		ft_check_confrontation(char **square, char **tti, int x, int y)
{
	size_t		i2;
	size_t		tmp;
	size_t		i3;
	int			c;

	i2 = 0;
	c = 0;
	tmp = x;
	while (tti[i2] && square[y])
	{
		i3 = 0;
		while (tti[i2][i3] && square[y][x])
		{
			if (tti[i2][i3] != '.' && square[y][x] != '.' && i2 < 4 && i3 < 4)
				return (1);
			c = (tti[i2][i3] != '.' && i2 < 4 && i3 < 4) ? c + 1 : c;
			x++;
			i3++;
		}
		x = tmp;
		y++;
		i2++;
	}
	return ((c == 4) ? 0 : 1);
}

static	char	**ft_put_empty(size_t index, char **square)
{
	int			i;
	int			i2;

	i = 0;
	while (square[i])
	{
		i2 = 0;
		while (square[i][i2])
		{
			if (square[i][i2] == (char)index + (char)65)
				square[i][i2] = '.';
			i2++;
		}
		i++;
	}
	return (square);
}

static char		**ft_put_tetrimino(char **square, char **tti, int pos, int idx)
{
	int			x;
	int			i;
	int			y;
	int			i2;

	x = pos % ft_strlen(square[0]);
	y = pos / ft_strlen(square[0]);
	i = 0;
	i2 = 0;
	while (tti[i])
	{
		while (tti[i][i2])
		{
			if (tti[i][i2] != '.')
				square[y + i][x + i2] = ((char)idx + 65);
			i2++;
		}
		i++;
		i2 = 0;
	}
	return (square);
}

int				ft_fillit_backtrack(t_tt_list *list, char ***square, size_t pos)
{
	int			x;
	int			y;

	x = pos % ft_strlen(*square[0]);
	y = pos / ft_strlen(*square[0]);
	if (list == NULL)
		return (1);
	if (pos >= ((ft_strlen(*square[0])) * (ft_strlen(*square[0]))))
		return (0);
	if (ft_check_confrontation(*square, list->tetrimino, x, y) == 1)
		return (ft_fillit_backtrack(list, square, pos + 1));
	if (ft_check_confrontation(*square, list->tetrimino, x, y) == 0)
	{
		*square = ft_put_tetrimino(*square, list->tetrimino, pos, list->i);
		if (ft_fillit_backtrack(list->next, square, 0) == 0)
		{
			*square = ft_put_empty(list->i, *square);
			return (ft_fillit_backtrack(list, square, pos + 1));
		}
		else
			return (1);
	}
	if (ft_fillit_backtrack(list->next, square, 0) == 1)
		return (1);
	return (0);
}
