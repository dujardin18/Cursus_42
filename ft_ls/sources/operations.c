/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 15:36:46 by fherbine          #+#    #+#             */
/*   Updated: 2018/02/11 18:07:41 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int				lf_total(char options[12], char *file, long long ret, int a)
{
	DIR			*rep;
	char		*path;

	path = ft_strdup(file);
	rep = NULL;
	if (!(rep = opendir(file)))
	{
		free(path);
		return (0);
	}
	path = ft_strjoin(path, "/");
	if (rep)
	{
		if (ft_strchr(options, 'a'))
			ret = lf_tt_aux2(path, ret, rep, &a);
		else
			ret = lf_tt_aux(path, ret, rep, &a);
		if (a)
			ft_prints("total %d\n", (intmax_t)ret);
		closedir(rep);
	}
	return (1);
}

static char		*lf_month_day(char *ret, time_t date_to_add, char **tmp)
{
	int			i;

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

static char		*da_aux(int i, char *ret, char *tim_ct)
{
	i = 11;
	while (i <= 15)
	{
		ret[i - 4] = tim_ct[i];
		i++;
	}
	return (ret);
}

char			*date_aux(long long tmp, time_t time_to_add, \
		long long current, char *ret)
{
	int			i;
	int			i2;
	char		*tim_ct;

	i2 = 0;
	i = 20;
	ret = lf_month_day(ret, time_to_add, &tim_ct);
	ret[7] = ' ';
	if (tmp - 5 > current || tmp + 5 < current)
	{
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
		ret = da_aux(i, ret, tim_ct);
	ret[(i2 != 0) ? 13 : 12] = '\0';
	return (ret);
}

char			*lf_date(struct stat buf)
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
