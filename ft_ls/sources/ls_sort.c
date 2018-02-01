/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 15:43:06 by fherbine          #+#    #+#             */
/*   Updated: 2018/01/29 15:30:49 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void 	swap_tab(char **s1, char **s2)
{
	char *tmp;

	tmp = ft_strdup(*s1);
	free(*s1);
	*s1 = ft_strdup(*s2);
	free(*s2);
	*s2 = ft_strdup(tmp);
	free(tmp);
}

static int		ft_strcmp_t(char *s1, char *s2)
{
	struct stat buf;
	int ret;

	ret = 0;
	lstat(s1, &buf);
	ret = buf.st_mtimespec.tv_sec;
	lstat(s2, &buf);
	ret -= buf.st_mtimespec.tv_sec;
	return (ret);
}

void	sort_tab(char **s1, char **s2, char options[5])
{
	if ((ft_strchr(options, 't') && ft_strcmp_t(*s1, *s2) < 0) || \
			(!ft_strchr(options, 't') && ft_strcmp(*s1, *s2) > 0))
		swap_tab(s1, s2);
	else if (ft_strchr(options, 't') && ft_strcmp_t(*s1, *s2) && \
			ft_strcmp(*s1, *s2) == 0)
		swap_tab(s1, s2);
}

char	**sort_argvs(int argc, char **argv, char options[5])
{
	int i;
	int i2;

	i = 0;
	while (i < argc && (argv[i][0] == '-' || i == 0))
	{
		argv[i] = ft_strdup(argv[i]);
		i++;
	}
	i2 = i;
	while (i2 < argc)
	{
		argv[i2] = ft_strdup(argv[i2]);
		i2++;
	}
	i2 = i;
	while (i < argc)
	{
		while (i2 < argc)
		{
			sort_tab(&(argv[i]), &(argv[i2]), options);
			i2++;
		}
		i++;
		i2 = i;
	}
	return (argv);
}

void	close_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
}
