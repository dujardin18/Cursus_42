/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 00:23:46 by fherbine          #+#    #+#             */
/*   Updated: 2018/09/19 07:33:02 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int				ft_mouse_read(int button, int x, int y, void *param)
{
	t_container	*map;
	int zm;

	map = (t_container *)param;
	zm = 0;
	if ((button == F_WHEEL || button == B_WHEEL) && (x > 0 && y > 0 && x < WIN_X && y < WIN_Y))
	{
		map->wheel_x = x;
		map->wheel_y = y;
		if (button == B_WHEEL && map->imgs[MAIN_IMG].frac.zoom < 200)
			zm -= 10;
		else if (button == F_WHEEL)
			zm += 50;
		else
			return (0);
		ft_prints(">>>>>>>>>>>>>> mouse zoom\n");
		update_fract_zoom(map, MAIN_IMG, zm);
		ft_prints(">>>>>>>>>>>>>> mouse zoom\n");
		mlx_update_img(map, MAIN_IMG);
		draw_fract(map, MAIN_IMG, map->f_typ);
	//	mlx_put_image_to_window(map->mlx, map->win, map->imgs[MAIN_IMG].img, 0, 0);
	}
	else
		ft_prints("b: %d | x: %d, y: %d\n", button, x, y);
	return (0);
}
