/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 11:28:09 by fherbine          #+#    #+#             */
/*   Updated: 2018/04/09 15:53:08 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

int     voir_touche()
{
	char     *buffer;

	init_cursor();
	while (1)
	{
	//	ft_prints("\033[2J");
		ft_prints("\033[u");
		buffer = ft_memalloc(4);
		read(0, buffer, 3);
		ft_prints("%c %c %c\n", buffer[0], buffer[1], buffer[2]);
		if (buffer[0] == 27)
			ft_prints("C'est une fleche !\n");
		else if (buffer[0] == 4)
		{
			ft_prints("Ctlr+d, on quitte !\n");
			return (0);
		}
		if (ft_strcmp(A_DOWN, buffer) == 0)
		{
			ft_prints("\033[1B");
		}
		sleep(1);
		free(buffer);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_slp	sl_params;

	sl_params = init_slp();
	modif_trm();
	voir_touche();
	ft_prints("l: %d\n", sl_params.sz.ws_row);
	ft_prints("c: %d\n", sl_params.sz.ws_col);
	default_trm();
	return (0);
}
