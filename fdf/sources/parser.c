/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 17:18:29 by fherbine          #+#    #+#             */
/*   Updated: 2017/12/22 13:50:19 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fdf.h"

static int		ft_checker(char *str)
{
	int			i;
	int			ret;
	int			tmp;

	i = 0;
	tmp = 0;
	ret = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i] == '\0')
			break ;
		else if ((str[i] < 48 || str[i] > 57) && str[i] != 45)
			ft_kill_parse();
		tmp = i;
		if ((str[i] >= 48 && str[i] <= 57) || str[i] == 45)
			ret++;
		while ((str[i] >= 48 && str[i] <= 57) || str[i] == 45)
			i++;
		if (tmp == i)
			ft_kill_parse();
	}
	return (ret);
}

static int		**ft_make_empty_square(int x, int y)
{
	int			i;
	int			i2;
	int			**tab;

	i = 0;
	i2 = 0;
	if (!(tab = (int **)ft_memalloc(sizeof(int *) * y)))
		ft_kill_parse();
	while (i < y)
	{
		if (!(tab[i] = (int *)ft_memalloc(sizeof(int) * (x + 1))))
			ft_kill_parse();
		i++;
	}
	return (tab);
}

static t_map	ft_make_tab_aux(t_parsing parse, t_map map, \
		char *line, int c[2])
{
	while (parse.m > 0 && parse.y < c[1])
	{
		parse.m = get_next_line(parse.fd, &line);
		while (line[parse.i] && parse.m > 0 && parse.x < c[0])
		{
			while ((line[parse.i] < 48 || line[parse.i] > 57) && \
					line[parse.i] != 45 && line[parse.i])
				(parse.i)++;
			map.map_tab[parse.y][parse.x] = ft_natoi(&(line[parse.i]));
			if (map.map_tab[parse.y][parse.x] <= map.col.dif[0])
				map.col.dif[0] = map.map_tab[parse.y][parse.x];
			if (map.map_tab[parse.y][parse.x] >= map.col.dif[1])
				map.col.dif[1] = map.map_tab[parse.y][parse.x];
			while ((line[parse.i] >= 48 && line[parse.i] <= 57) || \
					line[parse.i] == 45)
				(parse.i)++;
			(parse.i)++;
			(parse.x)++;
		}
		(parse.i) = 0;
		(parse.x) = 0;
		(parse.y)++;
		free(line);
	}
	return (map);
}

static t_map	ft_make_tab(t_parsing parse)
{
	char		*line;
	t_map		map;
	int			coord[2];

	coord[0] = parse.x;
	coord[1] = parse.y;
	line = NULL;
	parse.m = 1;
	parse.i = 0;
	map.map_tab = ft_make_empty_square(parse.x, parse.y);
	parse.y = 0;
	parse.x = 0;
	map.col.dif[0] = 2147483647;
	map.col.dif[1] = -2147483648;
	if (parse.fd == -1)
		ft_kill_parse();
	map = ft_make_tab_aux(parse, map, line, coord);
	close(parse.fd);
	return (map);
}

t_map			ft_parser(char *path, int *x, int *y)
{
	t_parsing	parse;

	parse.n = 1;
	parse.y = 0;
	parse.tmp = -1;
	parse.fd = open(path, O_RDONLY);
	if (parse.fd == -1)
		ft_kill_parse();
	while (parse.n > 0)
	{
		parse.n = get_next_line(parse.fd, &(parse.line));
		if (parse.n > 0)
			parse.x = ft_checker(parse.line);
		if (parse.x != parse.tmp && parse.tmp != -1)
			ft_kill_parse();
		else if (parse.tmp == -1)
			parse.tmp = parse.x;
		free(parse.line);
		parse.y = (parse.n > 0) ? parse.y + 1 : parse.y;
	}
	close(parse.fd);
	parse.fd = open(path, O_RDONLY);
	*x = parse.x;
	*y = parse.y;
	return (ft_make_tab(parse));
}
