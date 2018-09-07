/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_routine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 20:50:11 by fherbine          #+#    #+#             */
/*   Updated: 2018/09/07 09:04:00 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		init_window(t_container *map)
{
	map->win_x = WIN_X;
	map->win_y = WIN_Y;
	map->wheel_x = WIN_X / 2;
	map->wheel_y = WIN_Y / 2;
	if (!(map->mlx = mlx_init()))
		map->regs.err_reg |= (0x1 << 0);
	if (!(map->win = mlx_new_window(map->mlx, map->win_x, map->win_y, WIN_TITLE)))
		map->regs.err_reg |= (0x1 << 0);
	if (!(map->regs.err_reg & (0x1 << 0)))
		map->regs.st_reg |= (0x1 << 0);
}

void		close_prgm(t_container *map, char *msg, short ext)
{
	if (map->regs.st_reg & (0x1 << 1))
		close_imgs(map);
	if (map->regs.st_reg & (0x1 << 0))
		mlx_destroy_window(map->mlx, map->win);
	if (ext == -1)
		msg_exit(msg);
	else
		exit(EXIT_SUCCESS);
}
