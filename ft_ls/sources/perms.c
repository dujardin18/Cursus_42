/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 15:45:17 by fherbine          #+#    #+#             */
/*   Updated: 2018/02/05 20:07:16 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static char		prm_type(struct stat buf)
{
	char		ret;

	if ((buf.st_mode & S_IFMT) == S_IFDIR)
		ret = 'd';
	else if ((buf.st_mode & S_IFMT) == S_IFBLK)
		ret = 'b';
	else if ((buf.st_mode & S_IFMT) == S_IFCHR)
		ret = 'c';
	else if ((buf.st_mode & S_IFMT) == S_IFLNK)
		ret = 'l';
	else if ((buf.st_mode & S_IFMT) == S_IFSOCK)
		ret = 's';
	else if ((buf.st_mode & S_IFMT) == S_IFIFO)
		ret = 'p';
	else
		ret = '-';
	return (ret);
}

static char		prm_attr(char *path)
{
	char		ret;

	if (listxattr(path, NULL, 0, XATTR_NOFOLLOW) > 0)
		ret = '@';
	else
		ret = ' ';
	return (ret);
}

char			*lf_perms(char *path, struct stat buffer)
{
	char		*ret;

	if (!(ret = (char *)malloc(sizeof(char) * 13)))
		exit(EXIT_FAILURE);
	ret[0] = prm_type(buffer);
	ret[1] = (buffer.st_mode & S_IRUSR) ? 'r' : '-';
	ret[2] = (buffer.st_mode & S_IWUSR) ? 'w' : '-';
	ret[3] = (buffer.st_mode & S_IXUSR) ? 'x' : '-';
	ret[4] = (buffer.st_mode & S_IRGRP) ? 'r' : '-';
	ret[5] = (buffer.st_mode & S_IWGRP) ? 'w' : '-';
	ret[6] = (buffer.st_mode & S_IXGRP) ? 'x' : '-';
	ret[7] = (buffer.st_mode & S_IROTH) ? 'r' : '-';
	ret[8] = (buffer.st_mode & S_IWOTH) ? 'w' : '-';
	ret[9] = (buffer.st_mode & S_IXOTH) ? 'x' : '-';
	ret[10] = prm_attr(path);
	ret[11] = '\0';
	ret[12] = '\0';
	return (ret);
}
