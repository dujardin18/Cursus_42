/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 15:45:17 by fherbine          #+#    #+#             */
/*   Updated: 2018/02/08 12:29:50 by fherbine         ###   ########.fr       */
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

static char		ft_sticky(struct stat buf, int param)
{
	if (param == 0 && !(buf.st_mode & S_IXUSR) && (buf.st_mode & S_ISUID))
		return ('S');
	else if (param == 0 && (buf.st_mode & S_IXUSR) && (buf.st_mode & S_ISUID))
		return ('s');
	else if (param == 1 && (buf.st_mode & S_IXGRP) && (buf.st_mode & S_ISGID))
		return ('s');
	else if (param == 1 && !(buf.st_mode & S_IXGRP) && (buf.st_mode & S_ISGID))
		return ('S');
	else if (param == 0 && (buf.st_mode & S_IXUSR))
		return ('x');
	else if (param == 1 && (buf.st_mode & S_IXGRP))
		return ('x');
	else
		return ('-');
}

static char		ft_sticky2(struct stat buf)
{
	if (!(buf.st_mode & S_IXOTH) && (buf.st_mode & S_ISVTX))
		return ('T');
	else if ((buf.st_mode & S_IXOTH) && (buf.st_mode & S_ISVTX))
		return ('t');
	else if ((buf.st_mode & S_IXOTH))
		return ('x');
	else
		return ('-');
}

char			*lf_perms(char *path, struct stat buffer)
{
	char		*ret;

	if (!(ret = (char *)malloc(sizeof(char) * 13)))
		exit(EXIT_FAILURE);
	ret[0] = prm_type(buffer);
	ret[1] = (buffer.st_mode & S_IRUSR) ? 'r' : '-';
	ret[2] = (buffer.st_mode & S_IWUSR) ? 'w' : '-';
	ret[3] = ft_sticky(buffer, 0);
	ret[4] = (buffer.st_mode & S_IRGRP) ? 'r' : '-';
	ret[5] = (buffer.st_mode & S_IWGRP) ? 'w' : '-';
	ret[6] = ft_sticky(buffer, 1);
	ret[7] = (buffer.st_mode & S_IROTH) ? 'r' : '-';
	ret[8] = (buffer.st_mode & S_IWOTH) ? 'w' : '-';
	ret[9] = ft_sticky2(buffer);
	ret[10] = prm_attr(path);
	ret[11] = '\0';
	ret[12] = '\0';
	return (ret);
}
