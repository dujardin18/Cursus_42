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

static char lf_month_day(char *month_day[7], time_t date_to_add)[7]
{
	char *tmp;
	int i;

	i = 4;
	tmp = ctime(&(date_to_add));
	while (i <= 9)
	{
		month_day[i - 4] = tmp[i];
		i++;
	}
	month_day[i - 4] = '\0';
	free(tmp);
	return (month_day);
}

char	date_aux(long long tmp, time_t time_to_add, long long current)[6]
{
	char final[6];
	int i;
	i = 0;
	
	if (tmp - 6 > current || tmp + 6 < current)
	{
		i = 20;
		while (ctime(time_to_add)[i])
		{
			final[i - 20] = ctime(time_to_add)[i];
			i++;
		}
	}
	else
	{
		i = 11;
		while (i <= 15)
		{
			final[i - 11] = ctime(time_to_add)[i];
			i++;
		}
	}
	return (final);
}

char	lf_date(time_t date_to_add)[13]
{
	long long tmp;
	long long current;
	char ret[13];
	char month_day[7];
	int i;

	//if (!(ret = (char *)malloc(sizeof(char) * 13)))
	//	exit(EXIT_FAILURE);
	i = 0;
	tmp = (long long)date_to_add * 10 / 60 / 60 / 24 / 305;
	current = time(NULL) * 10 / 60 / 60 / 24 / 305;

}
