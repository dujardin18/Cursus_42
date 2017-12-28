/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:10:06 by fherbine          #+#    #+#             */
/*   Updated: 2017/11/25 20:00:51 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "babab.h"

static	void		ft_printing(char **tab)
{
	size_t			i;

	i = 0;
	while (tab[i])
	{
		ft_putendl(tab[i]);
		i++;
	}
}

static	t_tt_list	*ft_reading_auxiliary(char *path)
{
	t_tt_list		*list;
	int				fd;

	if ((fd = open(path, O_RDONLY)) <= 0)
	{
		ft_putendl("error");
		exit(EXIT_FAILURE);
	}
	if (!(list = ft_tetri(fd)))
	{
		ft_putendl("error");
		exit(EXIT_FAILURE);
	}
	close(fd);
	return (list);
}

int					main(int argc, char **argv)
{
	t_tt_list		*list;
	char			**square;
	size_t			n;

	if (argc == 2)
	{
		list = ft_reading_auxiliary(argv[1]);
		n = ft_square_min(list);
		square = ft_make_square(n);
		while (1)
		{
			if (ft_fillit_backtrack(list, &square, 0) == 1)
				break ;
			free(square);
			square = ft_make_square(n);
			n++;
		}
		ft_printing(square);
	}
	else
	{
		ft_putendl("usage: ./fillit fillit_map_file");
		exit(EXIT_FAILURE);
	}
	return (0);
}
