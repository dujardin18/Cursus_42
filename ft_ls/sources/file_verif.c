/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_verif.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 16:14:43 by fherbine          #+#    #+#             */
/*   Updated: 2018/02/08 12:35:12 by fherbine         ###   ########.fr       */
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

int				file_is_dir2(char *path, t_rfile *rfile)
{
	struct stat	buf;

	lstat(path, &buf);
	if ((buf.st_mode & S_IFMT) == S_IFDIR)
		return (1);
	else if ((buf.st_mode & S_IFMT) == S_IFLNK && rfile)
		return (1);
	return (0);
}
