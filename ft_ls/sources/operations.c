/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 15:36:46 by fherbine          #+#    #+#             */
/*   Updated: 2018/01/22 20:14:25 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static long long	tt_aux(char options[5], struct stat buf, char *name)
{
	if (name[0] == '.' && !(ft_strchr(options, 'a')))
		return (0);
	else 
		return (buf.st_blocks);
}

void		lf_total(char options[5], char *file, long long ret)
{
	DIR				*rep;
	struct dirent	*tmp;
	struct stat		buf;
	char 			*path;
	char			*tmp_path;

	rep = NULL;
	path = ft_strdup(file);
	path = ft_strjoin(path, "/");
	tmp_path = ft_strdup(path);
	if (!(rep = opendir(file)))
		exit(EXIT_FAILURE);
	tmp = readdir(rep);
	while (tmp)
	{
		path = ft_strjoin(path, tmp->d_name);
		lstat(path, &buf);
		ret += tt_aux(options, buf, tmp->d_name);
		tmp = readdir(rep);
		free(path);
		path = ft_strdup(tmp_path);
	}
	free(tmp_path);
	free(path);
	ft_prints("total %d\n", (intmax_t)ret);
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
	char *tim_ct;
	
	ret = lf_month_day(ret, time_to_add, &tim_ct);
	ret[7] = ' ';
	if (tmp - 6 > current || tmp + 6 < current)
	{
		i = 18;
		while (tim_ct[i])
		{
			ret[i - 10] = tim_ct[i];
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
	ret[12] = '\0';
	return (ret);
}

char	*lf_date(time_t date_to_add)
{
	long long	tmp;
	long long	current;
	char		*ret;

	if (!(ret = (char *)malloc(sizeof(char) * 13)))
		exit(EXIT_FAILURE);
	tmp = (long long)date_to_add * 10 / 60 / 60 / 24 / 305;
	current = time(NULL) * 10 / 60 / 60 / 24 / 305;
	ret = date_aux(tmp, date_to_add, current, ret);
	return (ret);
}
