/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 07:46:05 by fherbine          #+#    #+#             */
/*   Updated: 2018/09/08 03:45:17 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	update_fract_zoom(t_container *map, int im_idx, int add)
{
	map->imgs[im_idx].frac.zoom += add;
	map->imgs[im_idx].frac.frac_x = (map->imgs[im_idx].frac.x2 - map->imgs[im_idx].frac.x1) * (map->imgs[im_idx].frac.zoom);
	map->imgs[im_idx].frac.frac_y = (map->imgs[im_idx].frac.y2 - map->imgs[im_idx].frac.y1) * (map->imgs[im_idx].frac.zoom);
	map->imgs[im_idx].frac.win_ofx = map->wheel_x - (int)((map->imgs[im_idx].frac.frac_x) / 2);
	map->imgs[im_idx].frac.win_ofy = map->wheel_y - (int)((map->imgs[im_idx].frac.frac_y) / 2);
	ft_prints("vvvv%d\n", map->imgs[im_idx].frac.win_ofy);
}

void	init_fract(t_container *map, int im_idx, int f_typ)
{
	map->imgs[im_idx].frac.x = 0.0;
	map->imgs[im_idx].frac.zoom = 300;
	map->imgs[im_idx].frac.col = 255;
	map->imgs[im_idx].frac.x1 = (!f_typ) ? -1.8 : -2.1;
	map->imgs[im_idx].frac.x2 = (!f_typ) ? 1.8 : 1.5;
	map->imgs[im_idx].frac.y1 = -1.2;
	map->imgs[im_idx].frac.y2 = 1.2;
	map->imgs[im_idx].frac.cr = 0.0;
	map->imgs[im_idx].frac.ci = 0.0;
	map->imgs[im_idx].frac.zr = 0.0;
	map->imgs[im_idx].frac.zi = 0.0;
	map->imgs[im_idx].frac.imax = 40;
	update_fract_zoom(map, im_idx, 0);
}

static int	suit_loop(t_fractal *frac)
{
	int		i;
	double	tmp;

	i = 0;
	while (pow(frac->zr, 2) + pow(frac->zi, 2) < 4.0 && i < frac->imax)
	{
		tmp = frac->zr;
		frac->zr = pow(frac->zr, 2) - pow(frac->zi, 2) + frac->cr;
		frac->zi = 2 * tmp * frac->zi + frac->ci;
		i++;
	}
	return (i);
}

static int get_pos_frac(t_fractal *frac, t_container *map, int im_idx)
{
	int i;
	
	i = suit_loop(frac);
	if (!(frac->x + frac->win_ofx <= 0 || frac->x + frac->win_ofx >= WIN_X || frac->y + frac->win_ofy <= 0 || frac->y + frac->win_ofy >= WIN_Y))
	{
		if (i == frac->imax)
			put_img_pix(map, im_idx, (int)frac->x + frac->win_ofx, frac->y + frac->win_ofy, frac->col / 4);
		else
			put_img_pix(map, im_idx, (int)frac->x + frac->win_ofx, frac->y + frac->win_ofy, i * frac->col / frac->imax);
	}
	else if ((int)frac->x + frac->win_ofx >= WIN_X)
		return (0);
	frac->y += 1.0;
	return (1);
}

void		draw_fract(t_container *map, int im_idx, int f_typ)
{
	int			run;
	t_fractal	*frac;

	frac = &(map->imgs[im_idx].frac);
	frac->x = 0;
	while (frac->x < frac->frac_x)
	{
		frac->y = 0.0;
		while (frac->y < frac->frac_y)
		{
			frac->cr = (!f_typ) ? 0.285 : frac->x / frac->zoom + frac->x1;
			frac->ci = (!f_typ) ? 0.01 : frac->y / frac->zoom + frac->y1;
			frac->zr = (f_typ) ? 0.0 : frac->x / frac->zoom + frac->x1;
			frac->zi = (f_typ) ? 0.0 : frac->y / frac->zoom + frac->y1;
			run = get_pos_frac(frac, map, im_idx);
			if (!run)
				return ;
		}
		if ((int)(frac->x + frac->win_ofx) % 10 == 0)
		{
			//mlx_update_img(map, MAIN_IMG);
			mlx_put_image_to_window(map->mlx, map->win, map->imgs[MAIN_IMG].img, 0, 0);
		}
		frac->x += 1.0;
	}
}
