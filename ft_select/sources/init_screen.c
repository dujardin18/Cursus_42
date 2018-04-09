/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 14:42:16 by fherbine          #+#    #+#             */
/*   Updated: 2018/04/09 15:52:44 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void		init_cursor(void)
{
	ft_prints("%s%s%s", ERASE_DISP, ORIGIN_POS, SAVE_POS);
}

t_slp		init_slp(void)
{
	t_slp	sl_params;
	ioctl(0, TIOCGWINSZ, &(sl_params.sz));
	return (sl_params);
}
