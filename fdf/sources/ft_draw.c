/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 15:27:03 by fherbine          #+#    #+#             */
/*   Updated: 2017/12/21 18:17:39 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fdf.h"

static void		ft_put_line_aux(t_map map, double factor, int tmp, int y)
{
	int			tmp2;

	tmp2 = map.x2;
	while (map.x2 <= map.x)
	{
		y = map.y2;
		map = ft_put_in_place(factor, map, map.x2, tmp);
		while (y < map.y2)
		{
			ft_put_point(map, y, map.col.color);
			y++;
		}
		while (y > map.y2)
		{
			ft_put_point(map, y, map.col.color);
			y--;
		}
		map = ft_wich(map, ((int)(map.x - tmp2) + 1));
		ft_put_point(map, y, map.col.color);
		(map.x2)++;
	}
}

static void		ft_put_line(t_map map)
{
	double		factor;
	int			tmp;
	int			y;

	if (map.z2 > map.z1)
		map.col.color = map.col.color2;
	else if (map.z2 < map.z1)
		map.col.color = map.col.color1;
	if (map.x < map.x2)
	{
		ft_swap(&(map.x), &(map.x2));
		ft_swap(&(map.y), &(map.y2));
	}
	factor = (((double)map.y) - ((double)map.y2)) / \
		(((double)map.x) - ((double)map.x2));
	tmp = (map.y) - (factor * (map.x));
	y = map.y2;
	ft_put_line_aux(map, factor, tmp, y);
}

t_map			ft_draw_aux(t_map map, int *coord, int x, int y)
{
	coord = ft_flat_coord(x, y, map.map_tab[y][x], map);
	map.x = coord[0];
	map.y = coord[1];
	map.z1 = map.map_tab[y][x];
	free(coord);
	if (x > 0)
	{
		coord = ft_flat_coord(x - 1, y, map.map_tab[y][x - 1], map);
		map.x2 = coord[0];
		map.y2 = coord[1];
		map.z2 = map.map_tab[y][x - 1];
		free(coord);
		ft_put_line(map);
	}
	if (y > 0)
	{
		coord = ft_flat_coord(x, y - 1, map.map_tab[y - 1][x], map);
		map.x2 = coord[0];
		map.y2 = coord[1];
		map.z2 = map.map_tab[y - 1][x];
		free(coord);
		ft_put_line(map);
	}
	return (map);
}

int				ft_draw(t_map map)
{
	int			x;
	int			y;
	int			*coord;

	x = 0;
	y = 0;
	coord = NULL;
	while (y < map.y_max)
	{
		while (x < map.x_max)
		{
			map = ft_draw_aux(map, coord, x, y);
			x++;
		}
		x = 0;
		y++;
	}
	return (1);
}
