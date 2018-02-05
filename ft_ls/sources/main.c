/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 17:08:40 by fherbine          #+#    #+#             */
/*   Updated: 2018/02/05 20:04:09 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void			ft_debug_params(t_params *params)
{
	int			i;
	t_path		*cp;

	i = 1;
	cp = params->files;
	if (cp)
		ft_prints("liste chainee de fichier a analyser :\n");
	while (cp)
	{
		ft_prints("\t%d. |%s|\n", i, cp->name);
		lf_total(params->options, cp->name, 0, 0);
		cp = cp->next;
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

void			ft_debug_date_perms(char *path)
{
	char		*date;
	struct stat	buf;

	lstat(path, &buf);
	date = lf_date(buf);
	ft_prints("(%s) - date : |%s|\n", path, date);
	ft_prints("(%s) - perms : |%s|\n", path, lf_perms(path, buf));
}

void			ft_debug_in_dir(t_rfile *frst)
{
	t_rfile		*cp;

	cp = frst;
	while (cp)
	{
		ft_prints("name : |%s| \tPath : |%s|\n", cp->name, cp->path);
		cp = cp->next;
	}
}

int				main(int argc, char **argv)
{
	t_params	*params;

	params = ft_parser(argc, argv);
	if (DEBUG)
	{
		ft_debug_params(params);
		ft_debug_date_perms("/Applications");
		ft_debug_date_perms("/tmp");
		ft_debug_in_dir(new_rfile(".", params));
	}
	else
		ft_ls(params);
	free(params);
	return (0);
}
