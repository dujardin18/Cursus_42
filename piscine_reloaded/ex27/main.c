/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 13:18:02 by fherbine          #+#    #+#             */
/*   Updated: 2017/11/07 14:53:26 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int		main(int argc, char **argv)
{
	int fd;

	if (argc != 2)
		ft_write_error(argc);
	else
	{
		fd = open(argv[1], O_RDONLY);
		ft_read_file(fd);
		close(fd);
	}
	return (0);
}
