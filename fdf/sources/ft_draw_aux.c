/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_aux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 15:42:34 by fherbine          #+#    #+#             */
/*   Updated: 2017/12/21 18:24:41 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fdf.h"

int			*ft_flat_coord(int x, int y, int z, t_map map)
{
	int		*ret;

	if (!(ret = (int *)ft_memalloc(sizeof(int) * 2)))
		return (NULL);
	ret[0] = map.x0 + map.zoom * (cos(map.omega * (M_PI / 180)) * x + \
			sin(map.omega * (M_PI / 180)) * y);
	ret[1] = map.y0 + map.zoom * (sin(map.alpha * (M_PI / 180)) * \
			(sin(map.omega * (M_PI / 180)) * x - cos(map.omega * (M_PI / 180)) \
				* y) + z * cos(map.alpha * (M_PI / 180)));
	return (ret);
}

int			ft_put_point(t_map map, int y, int color)
{
	if (map.x2 > 0 && map.x2 < map.width && y > 0 && y < map.height)
	{
		map.img_chars[y * map.s_l + map.x2 * 4] = (char)color;
		map.img_chars[y * map.s_l + map.x2 * 4 + 1] = (char)(color >> 8);
		map.img_chars[y * map.s_l + map.x2 * 4 + 2] = (char)(color >> 16);
		map.img_chars[y * map.s_l + map.x2 * 4 + 3] = (char)(color >> 24);
	}
	return (1);
}

t_map		ft_put_in_place(double factor, t_map map, int x, int add)
{
	map.y2 = (map.x != x) ? ((int)(((double)x) * factor) + add) : map.y;
	return (map);
}

t_map		ft_wich(t_map map, int cal)
{
	if (map.z2 > map.z1 && cal > 0)
	{
		map.col.color = map.col.color + ((map.col.color1 - map.col.color2) \
				/ (0x1 * (cal)));
	}
	else if (map.z2 < map.z1 && cal > 0)
		map.col.color = map.col.color - ((map.col.color1 - map.col.color2) \
				/ (0x1 * cal));
	else
	{
		if (map.z1 < map.col.middle)
			map.col.color = map.col.color1;
		if (map.z1 >= map.col.middle)
			map.col.color = map.col.color2;
	}
	return (map);
}
