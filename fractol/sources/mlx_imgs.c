/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_imgs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 22:23:48 by fherbine          #+#    #+#             */
/*   Updated: 2018/09/07 00:05:09 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	create_img(t_container *map, int win_x, int win_y)
{
	int	idx;

	idx = (int)(map->regs.imgs_used);
	map->imgs[idx].width = win_x;
	map->imgs[idx].height = win_y;
	if (!(map->imgs[idx].img = mlx_new_image(map->mlx, win_x, win_y)))
		map->regs.err_reg |= (0x1 << 1);
	map->imgs[idx].encode = ft_strdup(mlx_get_data_addr(map->imgs[idx].img, \
				&(map->bpp), &(map->sl), &(map->endian)));
	if (!(map->regs.err_reg & (0x1 << 1)))
	{
		map->regs.st_reg |= (0x1 << 1);
		map->regs.imgs_used += 1;
	}
}

void	put_img_pix(t_container *map, int img_idx, int x, int y, int col)
{
	if (x >= 0 && x <= map->imgs[img_idx].width && y >= 0 && y <= map->imgs[img_idx].height)
	{
		(map->imgs[img_idx].encode)[y * map->sl + x * 4 + 0] = (char)(col >> 0);
		(map->imgs[img_idx].encode)[y * map->sl + x * 4 + 1] = (char)(col >> 8);
		(map->imgs[img_idx].encode)[y * map->sl + x * 4 + 2] = (char)(col >> 16);
		(map->imgs[img_idx].encode)[y * map->sl + x * 4 + 3] = (char)(col >> 24);
	}
	else
		map->regs.err_reg |= (0x1 << 2);
}

void	close_imgs(t_container *map)
{
	int	i;

	i = 0;
	while (i < map->regs.imgs_used)
	{
		free(map->imgs[i].encode);
		mlx_destroy_image(map->mlx, map->imgs[i].img);
		i++;
	}
}
