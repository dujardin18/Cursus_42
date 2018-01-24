/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 15:45:17 by fherbine          #+#    #+#             */
/*   Updated: 2018/01/24 18:17:59 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static char	prm_type(struct stat buf)
{
	char		ret;

	if ((buf.st_mode & S_IFMT) ==  S_IFDIR)
		ret = 'd';
	else if ((buf.st_mode & S_IFMT) ==  S_IFBLK)
		ret = 'b';
	else if ((buf.st_mode & S_IFMT) ==  S_IFCHR)
		ret = 'c';
	else if ((buf.st_mode & S_IFMT) ==  S_IFLNK)
		ret = 'l';
	else if ((buf.st_mode & S_IFMT) ==  S_IFSOCK)
		ret = 's';
	else if ((buf.st_mode & S_IFMT) ==  S_IFIFO)
		ret = 'p';
	else
		ret = '-';
	return (ret);
}

static int	at_srch(char *path)
{
	DIR *rep;
	struct dirent *to_check;
	char *tmp;
	char *tmp2;

	rep = NULL;
	tmp = ft_strdup(path);
	tmp = ft_strjoin(tmp, "/");
	if ((rep = opendir(path)))
	{
		to_check = readdir(rep);
		while (to_check)
		{
			tmp2 = ft_strdup(tmp);
			tmp2 = ft_strjoin(tmp2, to_check->d_name);
			if (listxattr(tmp2, NULL, 0, XATTR_NOFOLLOW) > 0)
				return (1);
			to_check = readdir(rep);
			free(tmp2);
		}
		closedir(rep);
	}
	return (0);
}

static char prm_attr(char *path, struct stat b)
{
	char		ret;

	if (listxattr(path, NULL, 0, XATTR_NOFOLLOW) > 0)
		ret = '@';
	else if (((b.st_mode & S_IFDIR) || (b.st_mode & S_IFLNK)) && at_srch(path))
		ret = '+';
	else
		ret = ' ';
	return (ret);
}

char	*perms(char *path)
{
	struct stat	buffer;
	char		*ret;

	if (!(ret = (char *)malloc(sizeof(char) * 13)))
		exit(EXIT_FAILURE);
	lstat(path, &buffer);
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
	ret[10] = prm_attr(path, buffer);
	ret[11] = ' ';
	ret[12] = '\0';
	return (ret);
}
