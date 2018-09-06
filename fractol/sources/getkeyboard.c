/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getkeyboard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 23:36:40 by fherbine          #+#    #+#             */
/*   Updated: 2018/09/07 00:29:33 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int				ft_key_read(int keycode, void *param)
{
	t_container *map;

	map = (t_container *)param;
	if (keycode == MLX_ESC)
		close_prgm(map, NULL, 0);
//	else
//		ft_prints("|%d|\n", keycode);
	return (0);
}
