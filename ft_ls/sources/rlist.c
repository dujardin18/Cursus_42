/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rlist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 11:25:57 by fherbine          #+#    #+#             */
/*   Updated: 2018/01/29 19:29:27 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static size_t	pdir_len(char *path)
{
	DIR *dire;
	size_t i;

	i = 0;
	if ((dire = opendir(path)))
	{
		while ((readdir(dire)))
			i++;
		closedir(dire);
	}
	return (i);
}

static int		ft_strcmpt(char *s1, char *s2, char *path)
{
	struct stat buf;
	char *p1;
	char *p2;
	int ret;

	ret = 0;
	p1 = ft_strdup(path);
	p2 = ft_strdup(path);
	p1 = ft_strjoin(p1, "/");
	p2 = ft_strjoin(p2, "/");
	p1 = ft_strjoin(p1, s1);
	p2 = ft_strjoin(p2, s2);
	lstat(p1, &buf);
	ret = buf.st_mtimespec.tv_sec;
	lstat(p2, &buf);
	ret -= buf.st_mtimespec.tv_sec;
	free(p1);
	free(p2);
	return (ret);
}

void	get_swap(char **s1, char **s2, char options[5], char *path)
{
	if ((ft_strchr(options, 't') && ft_strcmpt(*s1, *s2, path) < 0) || \
			(!ft_strchr(options, 't') && ft_strcmp(*s1, *s2) > 0))
		swap_tab(s1, s2);
	else if (ft_strchr(options, 't') && ft_strcmpt(*s1, *s2, path) && \
			ft_strcmp(*s1, *s2) == 0)
		swap_tab(s1, s2);
}

char	**sort_pdir(char **tab, t_params *params, char *path)
{
	int i;
	int i2;

	i = 0;
	if (!tab)
		return (NULL);
	while (tab[i])
	{
		i2 = i;
		while (tab[i2])
		{
			get_swap(&(tab[i]), &(tab[i2]), params->options, path);
			i2++;
		}
		i++;
	}
	return (tab);
}

char	**new_pdir(char *path)
{
	char **pdir;
	DIR *dire;
	struct dirent *new;
	int i;

	i = 0;
	pdir = NULL;
	if ((dire = opendir(path)))
	{
		if (!(pdir = (char **)malloc(sizeof(char *) * (pdir_len(path) + 1))))
			exit(EXIT_FAILURE);
		new = readdir(dire);
		while (new)
		{
			pdir[i] = ft_strdup(new->d_name);
			i++;
			new = readdir(dire);
		}
		pdir[i] = 0;
	}
	return (pdir);
}
