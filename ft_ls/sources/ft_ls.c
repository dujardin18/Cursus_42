/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 18:27:49 by fherbine          #+#    #+#             */
/*   Updated: 2018/02/01 18:06:48 by fherbine         ###   ########.fr       */
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

void	ls_r(t_params *params, char *path, char *first)
{
	t_rfile *new;
	t_rfile *tmp;
	new = new_rfile(path, params);
	tmp = new;

	if (new == NULL)
		return ;
	if (ft_strcmp(path, first) != 0)
		ft_prints("\n%s:\n", path);
	if (ft_strchr(params->options, 'l'))
	{
		lf_total(params->options, path, 0);
		params = max_disp(params, new);
	}
	ft_display_dir(new, params);
	while (new)
	{
		if (ft_strcmp(new->name, ".") != 0 && ft_strcmp(new->name, "..") != 0)
		{
			if ((ft_strchr(params->options, 'a') && new->name[0] == '.') || new->name[0] != '.')
				ls_r(params, new->path, first);
		}
		new = new->next;
	}
	free_rfile(tmp);
	return ;
}

void	ft_ls(t_params *params)
{
	t_rfile *rfile;
	t_path *cp;
	t_path *tmp;
	int disp;
	struct stat buf;

	disp = (params->files->next != NULL) ? 1 : 0;
	cp = params->files;
	tmp = cp;
	while (cp)
	{
		if (ft_strchr(params->options, 'R'))
			ls_r(params, cp->name, cp->name);
		else
		{
			rfile = new_rfile(cp->name, params);
			if (disp)
				ft_prints("\n%s:\n", cp->name);
			if (ft_strchr(params->options, 'l'))
			{
				lf_total(params->options, cp->name, 0);
				params = max_disp(params, rfile);
			}
			ft_display_dir(rfile, params);
			free_rfile(rfile);
		}
		cp = cp->next;
	}
	free_tpath(tmp);
}
