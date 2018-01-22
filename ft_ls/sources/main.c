/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 17:08:40 by fherbine          #+#    #+#             */
/*   Updated: 2018/01/22 16:06:55 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void			ft_debug_params(t_params *params)
{
	int i = 1;

	if (params->files)
		ft_prints("liste chainee de fichier a analyser :\n");
	while (params->files)
	{
		ft_prints("\t%d. |%s|\n",i, params->files->name);
		lf_total(params->options, params->files->name, 0);
		params->files = params->files->next;
		i++;
	}
	if (params->options[0])
		ft_prints("\nFlags a appliquer (par ordre d'arrivee) :\n");
	i = 0;
	while ((params->options)[i])
	{
		ft_prints("\t-%c\n", (params->options)[i]);
		i++;
	}
	ft_prints("\n");
}

void ft_debug_date(char *path)
{
	char 	*date;
	struct stat buf;

	stat(path, &buf);
	date = lf_date(buf.st_mtimespec.tv_sec); // date test >> 42
	ft_prints("(%s) - date : |%s|\n", path, date);
}

int				main(int argc, char **argv)
{
	t_params	*params;

	params = ft_parser(argc, argv);
	if (DEBUG)
	{
		ft_debug_params(params);
		ft_debug_date("/Applications");
	}
	return (0);
}
