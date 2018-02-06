/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 14:32:20 by fherbine          #+#    #+#             */
/*   Updated: 2018/02/06 17:24:45 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

long long			tt_aux(struct stat buf, char *name, int *a, int param)
{
	if (name[0] == '.' && param != 1)
		return (0);
	else
	{
		*a = 1;
		return (buf.st_blocks);
	}
}

int					lf_tt_aux(char *path, long long ret, DIR *rep, int *a)
{
	struct stat		buf;
	struct dirent	*tmp;
	char			*tmp_path;

	tmp_path = ft_strdup(path);
	tmp = readdir(rep);
	while (tmp)
	{
		path = ft_strjoin(path, tmp->d_name);
		lstat(path, &buf);
		ret += tt_aux(buf, tmp->d_name, a, 0);
		tmp = readdir(rep);
		free(path);
		path = ft_strdup(tmp_path);
	}
	free(tmp_path);
	free(path);
	return (ret);
}

int					lf_tt_aux2(char *path, long long ret, DIR *rep, int *a)
{
	struct stat		buf;
	struct dirent	*tmp;
	char			*tmp_path;

	tmp_path = ft_strdup(path);
	tmp = readdir(rep);
	while (tmp)
	{
		path = ft_strjoin(path, tmp->d_name);
		lstat(path, &buf);
		ret += tt_aux(buf, tmp->d_name, a, 1);
		tmp = readdir(rep);
		free(path);
		path = ft_strdup(tmp_path);
	}
	free(tmp_path);
	free(path);
	return (ret);
}
