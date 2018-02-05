/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 15:36:46 by fherbine          #+#    #+#             */
/*   Updated: 2018/02/05 16:55:08 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static long long	tt_aux(char options[5], struct stat buf, char *name, int *a)
{
	if (name[0] == '.' && !(ft_strchr(options, 'a')))
		return (0);
	else
	{
		*a = 1;
		return (buf.st_blocks);
	}
}

int			lf_total(char options[5], char *file, long long ret, int a)
{
	DIR				*rep;
	struct dirent	*tmp;
	struct stat		buf;
	char 			*path;
	char			*tmp_path;

	path = ft_strdup(file);
	path = ft_strjoin(path, "/");
	tmp_path = ft_strdup(path);
	rep = NULL;
	if (!(rep = opendir(file)))
		return (0);
	if (rep)
	{
		tmp = readdir(rep);
		while (tmp)
		{
			path = ft_strjoin(path, tmp->d_name);
			lstat(path, &buf);
			ret += tt_aux(options, buf, tmp->d_name, &a);
			tmp = readdir(rep);
			free(path);
			path = ft_strdup(tmp_path);
		}
		free(tmp_path);
		free(path);
		if (a)
			ft_prints("total %d\n", (intmax_t)ret);
		closedir(rep);
	}
	return (1);
}

static char *lf_month_day(char *ret, time_t date_to_add, char **tmp)
{
	int i;

	i = 4;
	*tmp = ctime(&(date_to_add));
	while (i <= 9)
	{
		ret[i - 4] = (*tmp)[i];
		i++;
	}
	ret[6] = ' ';
	ret[7] = '\0';
	return (ret);
}

char	*date_aux(long long tmp, time_t time_to_add, long long current, char *ret)
{
	int i;
	int i2;
	char *tim_ct;

	i2 = 0;
	ret = lf_month_day(ret, time_to_add, &tim_ct);
	ret[7] = ' ';
	if (tmp - 6 > current || tmp + 6 < current)
	{
		i = 20;
		while (tim_ct[i] > '9' || tim_ct[i] < '0')
		{
			i++;
			i2++;
		}
		while (tim_ct[i])
		{
			ret[i - i2 - 12] = tim_ct[i];
			i++;
		}
	}
	else
	{
		i = 11;
		while (i <= 15)
		{
			ret[i - 4] = tim_ct[i];
			i++;
		}
	}
	ret[(i2 != 0) ? 13 : 12 ] = '\0';
	return (ret);
}

char	*lf_date(struct stat buf)
{
	long long	tmp;
	long long	current;
	char		*ret;
	time_t		date_to_add;

	date_to_add = buf.st_mtimespec.tv_sec;
	if (!(ret = (char *)malloc(sizeof(char) * 14)))
		exit(EXIT_FAILURE);
	tmp = (long long)date_to_add / 60 / 60 / 24 / 30;
	current = time(NULL) / 60 / 60 / 24 / 30;
	ret = date_aux(tmp, date_to_add, current, ret);
	return (ret);
}
