/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 00:23:46 by fherbine          #+#    #+#             */
/*   Updated: 2018/09/07 00:36:50 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int				ft_mouse_read(int button, int x, int y, void *param)
{
	t_container	*map;

	map = (t_container *)param;
	ft_prints("b: %d | x: %d, y: %d\n", button, x, y);
	return (0);
}
