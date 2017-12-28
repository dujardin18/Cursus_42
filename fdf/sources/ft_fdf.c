/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 22:15:04 by fherbine          #+#    #+#             */
/*   Updated: 2017/12/21 19:17:53 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fdf.h"

static void		ft_key_move(int keycode, t_map *map)
{
	if (keycode == 69)
		(map->zoom) += 5;
	else if (keycode == 78)
		(map->zoom) = ((map->zoom) - 5 > 0) ? (map->zoom) - 5 : (map->zoom);
	else if (keycode == 91)
		(map->y0) -= 20;
	else if (keycode == 84)
		(map->y0) += 20;
	else if (keycode == 86)
		(map->x0) -= 20;
	else if (keycode == 88)
		(map->x0) += 20;
	else if (keycode == 89)
		(map->omega) += 5;
	else if (keycode == 92)
		(map->omega) -= 5;
	else if (keycode == 83)
		(map->alpha) = \
			((map->alpha) + 5 <= -90) ? (map->alpha) + 5 : (map->alpha);
	else if (keycode == 85)
		(map->alpha) -= 5;
}

static void		ft_key_colors(int keycode, t_map *map)
{
	if (keycode == 12)
		(map->col.color2) = 0x00FFFFFF;
	else if (keycode == 1)
		(map->col.color2) = 0x00FFFF00;
	else if (keycode == 0)
		(map->col.color2) = 0x00000000 + 0x1 * rand() % (0x00FFFFFE);
}

static int		ft_key_read(int keycode, void *param)
{
	t_map		*map;

	map = (t_map *)param;
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	else
	{
		mlx_destroy_image(map->mlx, map->img);
		map->img = mlx_new_image(map->mlx, map->width, map->height);
		map->img_chars = mlx_get_data_addr(map->img, \
				&(map->bpp), &(map->s_l), &(map->endian));
		ft_key_move(keycode, map);
		ft_key_colors(keycode, map);
		ft_draw(*map);
		mlx_put_image_to_window(map->mlx, map->win, map->img, 0, 0);
	}
	map->col.color = map->col.color2;
	return (0);
}

int				ft_fdf(t_map map)
{
	map.col.color1 = 0x00FFFFFF;
	map.col.color2 = 0x00FFFF00;
	map.col.color = map.col.color2;
	map.omega = -45;
	map.alpha = -100;
	map.zoom = (map.height) / (sqrt(pow(map.y_max, 2) + pow(map.x_max, 2)));
	map.x0 = (map.width) / 2;
	map.y0 = (map.height) / ((map.height) / 10);
	map.img = mlx_new_image(map.mlx, map.width, map.height);
	map.img_chars = mlx_get_data_addr(map.img, &(map.bpp), \
			&(map.s_l), &(map.endian));
	ft_draw(map);
	mlx_put_image_to_window(map.mlx, map.win, map.img, 0, 0);
	mlx_key_hook(map.win, ft_key_read, (void *)&map);
	return (0);
}
