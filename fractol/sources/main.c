/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 20:52:18 by fherbine          #+#    #+#             */
/*   Updated: 2018/09/07 00:29:37 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

// tmp func
void			init_regs(t_container *map)
{
	map->regs.st_reg = 0;
	map->regs.err_reg = 0;
	map->regs.imgs_used = 0;
}

void			fractol(t_container *map)
{
	mlx_key_hook(map->win, ft_key_read, (void *)map);
	mlx_mouse_hook(map->win, ft_mouse_read, (void *)map);
}

int				main(int argc, char **argv)
{
	t_container	map;

	init_regs(&map);
	init_window(&map);
	if (map.regs.err_reg)
		close_prgm(&map, "An error occurred during initialization !", -1);
	fractol(&map);
	mlx_loop(map.mlx);
	return (0);
}
