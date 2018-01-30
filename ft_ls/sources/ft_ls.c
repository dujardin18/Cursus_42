/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 18:27:49 by fherbine          #+#    #+#             */
/*   Updated: 2018/01/30 13:27:22 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char	*new_path(char *path, char *name)
{
	char *ret;

	ret = ft_strdup(path);
	ret = ft_strjoin(ret, name);
	return (ret);
}

void ft_display_dir(t_rfile *rfile, t_params *params)
{
	t_rfile *cp;
	cp = rfile;
	while (cp)
	{
		display_lf_aux(cp->path, cp->name, params);
	//	if (ft_strchr(params->options, 'l') && (ft_strchr(params->options, 'a') && cp->name[0] == '.') || cp->name[0] != '.')
	//	else if ((ft_strchr(params->options, 'a') && cp->name[0] == '.') || cp->name[0] != '.')
	//		ft_putendl(cp->name);
		cp = cp->next;
	}
}

int		file_is_dir(char *path) ///// opti ?
{
	struct stat buf;

	lstat(path, &buf);
	if ((buf.st_mode & S_IFMT) == S_IFDIR)
		return (1);
	else if ((buf.st_mode & S_IFMT) == S_IFLNK)
		return (1);
	return (0);
}

void	ls_r(t_params *params, char *path, t_rfile *rfile, char *first)
{
	if (rfile == NULL)
		return ;
	if (ft_strcmp(path, first) != 0)
		ft_prints("\n%s:\n", path);
	if (ft_strchr(params->options, 'l'))
		params = max_disp(params, rfile);
	ft_display_dir(rfile, params);
	while (rfile)
	{
		if (ft_strcmp(rfile->name, ".") != 0 && ft_strcmp(rfile->name, "..") != 0)
		{
			if ((ft_strchr(params->options, 'a') && rfile->name[0] == '.') || rfile->name[0] != '.')
				ls_r(params, rfile->path, new_rfile(rfile->path, params), first);
		}
		rfile = rfile->next;
	}
}

void	ft_ls(t_params *params)
{
	t_rfile *rfile;
	t_path *cp;

	cp = params->files;
	while (cp)
	{
		rfile = new_rfile(cp->name, params);
		if (ft_strchr(params->options, 'R'))
			ls_r(params, cp->name, rfile, cp->name);
		cp = cp->next;
	}
}
