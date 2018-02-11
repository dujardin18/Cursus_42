/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_verif.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 16:14:43 by fherbine          #+#    #+#             */
/*   Updated: 2018/02/11 18:19:55 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int				file_is_dir(char *path)
{
	struct stat	buf;

	lstat(path, &buf);
	if ((buf.st_mode & S_IFMT) == S_IFDIR)
		return (1);
	else if ((buf.st_mode & S_IFMT) == S_IFLNK)
		return (1);
	return (0);
}

int				file_is_lnk(char *path, t_params *params)
{
	struct stat	buf;
	t_rfile		*t;

	lstat(path, &buf);
	if ((buf.st_mode & S_IFMT) == S_IFLNK)
	{
		t = new_rfile(path, params);
		if (!t)
			return (1);
		free(t);
	}
	return (0);
}

int				file_is_dir2(char *path, t_params *p)
{
	struct stat	buf;
	t_rfile		*tmp;

	tmp = NULL;
	lstat(path, &buf);
	if ((buf.st_mode & S_IFMT) == S_IFDIR)
		return (1);
	else if (!(buf.st_mode & S_IFMT))
		return (0);
	else if ((buf.st_mode & S_IFMT) == S_IFLNK)
	{
		tmp = new_rfile(path, p);
		if (tmp)
		{
			free_rfile(tmp);
			return (1);
		}
	}
	return (0);
}

int				file_is_olnk(char *path, t_params *p)
{
	struct stat	buf;

	if ((ft_strchr(p->options, 'o') || ft_strchr(p->options, 'l') || \
			ft_strchr(p->options, 'p')) && path[ft_strlen(path) - 1] != '/')
	{
		lstat(path, &buf);
		if ((buf.st_mode & S_IFMT) == S_IFLNK)
			return (1);
	}
	return (0);
}
