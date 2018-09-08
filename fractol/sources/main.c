/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 20:52:18 by fherbine          #+#    #+#             */
/*   Updated: 2018/09/08 04:27:03 by fherbine         ###   ########.fr       */
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
#define YREL(x) x + WIN_Y / 2.0
#define XREL(x) x + WIN_X / 2.0
void			test(t_container *map)
{
	double x = 0.0, y = 0.0, y1 = -1.2, x1 = -2.1, x2 = 1.5, y2 = 1.2, tmp, ci, cr, zr, zi;
	int col = 0x00FFFFFF, i = 0, imax = 40, zoom = 300;
	double img_x = (x2 - x1) * zoom, img_y = (y2 - y1) * zoom;

	while (x < img_x)
	{
		y = 0.0;
		while (y < img_y)
		{
			i = 0;
			zr = 0;
			zi = 0;
			cr = x / zoom + x1;
			ci = y / zoom + y1;
			while (zr*zr+zi*zi < 4.0 && i < imax)
			{
				tmp = zr;
				zr = pow(zr, 2) - pow(zi, 2) + cr;
				zi = 2*tmp*zi + ci;
				i++;
			//	ft_prints("%d\n", i);
			}
			if ((int)XREL(x) - img_x / 2 >= WIN_X || (int)XREL(x) - img_x / 2 <= 0 || (int)YREL(y) - img_y / 2 >= WIN_Y || (int)YREL(y) - img_y / 2 <= 0)
			{
				if ((int)XREL(x) - img_x / 2 >= WIN_X)
					return;
				y += 1.0;
			}
			else{
			if (i == imax)
				put_img_pix(map, MAIN_IMG, (int)XREL(x) - img_x / 2, (int)YREL(y) - img_y / 2, 255/4);
			else
				put_img_pix(map, MAIN_IMG, (int)XREL(x) - img_x / 2, (int)YREL(y) - img_y / 2, i*255/imax);
			y += 1.0;
			}
		}
		x += 1.0;
	}
}
void			test2(t_container *map)
{
	double x = 0.0, y = 0.0, y1 = -1.2, x1 = -1.8, x2 = 1.8, y2 = 1.2, tmp, ci, cr, zr, zi;
	int col = 0x00FFFFFF, i = 0, imax = 40, zoom = 300;
	double img_x = (x2 - x1) * zoom, img_y = (y2 - y1) * zoom;


	while (x < img_x)
	{
		y = 0.0;
		while (y < img_y)
		{
			i = 0;
			cr = 0.285;
			ci = 0.01;
			zr = x / zoom + x1;
			zi = y / zoom + y1;
			while (zr*zr+zi*zi < 4.0 && i < imax)
			{
				tmp = zr;
				zr = pow(zr, 2) - pow(zi, 2) + cr;
				zi = 2*tmp*zi + ci;
				i++;
			}
			if ((int)XREL(x) - img_x / 2 >= WIN_X || (int)XREL(x) - img_x / 2 <= 0 || (int)YREL(y) - img_y / 2 >= WIN_Y || (int)YREL(y) - img_y / 2 <= 0)
			{
				if ((int)XREL(x) - img_x / 2 >= WIN_X)
					return;
				y += 1.0;
			}
			else{
			if (i == imax)
				put_img_pix(map, MAIN_IMG, (int)XREL(x) - img_x / 2, (int)YREL(y) - img_y / 2, col);
			else
				put_img_pix(map, MAIN_IMG, (int)XREL(x) - img_x / 2, (int)YREL(y) - img_y / 2, i*255/imax);
			y += 1.0;
			}
		}
		x += 1.0;
	}
}

void			fractol(t_container *map)
{
	create_img(map, WIN_X, WIN_Y);
	init_fract(map, MAIN_IMG, map->f_typ);
	draw_fract(map, MAIN_IMG, map->f_typ);
	//test(map);
	//ft_prints("REG %s%x%s\n", RED, map->regs.st_reg, REGULAR);
	//mlx_put_image_to_window(map->mlx, map->win, map->imgs[MAIN_IMG].img, 0, 0);
	mlx_key_hook(map->win, ft_key_read, (void *)map);
	mlx_mouse_hook(map->win, ft_mouse_read, (void *)map);
}

void			frac_init(int argc, char **argv, t_container *map)
{
	if (argc < 2)
		few_param_ex();
	ft_capitalize(&(argv[1]));
	if (!ft_strcmp(argv[1], "JULIA"))
		map->f_typ = JULIA;
	else if (!ft_strcmp(argv[1], "MANDEL"))
		map->f_typ = MANDEL;
	else
		inv_param_ex();
	init_regs(map);
	init_window(map);
	if (map->regs.err_reg)
		close_prgm(map, "An error occurred during initialization !", -1);
}

int				main(int argc, char **argv)
{
	t_container	map;

	frac_init(argc, argv, &map);
	fractol(&map);
	mlx_loop(map.mlx);
	return (0);
}
