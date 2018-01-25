/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 18:27:49 by fherbine          #+#    #+#             */
/*   Updated: 2018/01/25 20:46:28 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ls_display_lf(char *path, char *name, t_params *params)
{
	struct stat buf;
	struct stat buf2;

	if (ft_strchr(params->options, 'l'))
	{
		lstat(path, &buf);
		stat(path, &buf2);
		ft_prints("%s %s%s %s\n", perms(path), lf_usr_grp(path, params), \
				lf_date(buf.st_mtimespec.tv_sec), name);
	}
	else
		ft_prints("%s\n", name);
	free(path);
}

void	ls_classic(DIR *dire, t_params *params, char *path)
{
	struct 	dirent *new;
	char 	*tmp;

	new = readdir(dire);
	while (new)
	{
		tmp = ft_strdup(path);
		tmp = ft_strjoin(tmp, new->d_name);
		if (new->d_name[0] == '.' && ft_strchr(params->options, 'a'))
			ls_display_lf(tmp, new->d_name, params);
		else if (new->d_name[0] != '.')
			ls_display_lf(tmp, new->d_name, params);
		new = readdir(dire);
		//free(tmp);
	}
}

void	ft_ls(t_params *params)
{
	DIR *dire;
	t_path *cp;
	char *path;

	dire = NULL;
	cp = params->files;
	while (cp)
	{
		if ((dire = opendir(cp->name)))
		{
			path = ft_strdup(cp->name);
			path = ft_strjoin(path, "/");
			ft_prints("path : |%s|\n", path);
			params->max_u = max_u_g(dire, path, 0);
			closedir(dire);
			dire = opendir(cp->name);
			params->max_g = max_u_g(dire, path, 1);
			closedir(dire);
			dire = opendir(cp->name);
			params->max_l = max_u_g(dire, path, 2);
			closedir(dire);
			dire = opendir(cp->name);
			params->max_s = max_u_g(dire, path, 3);
			closedir(dire);
			dire = opendir(cp->name);
			if (!ft_strchr(params->options, 't') && !ft_strchr(params->options, 'R'))
				ls_classic(dire, params, path);
			closedir(dire);
			free(path);
		}
		cp = cp->next;
	}
}
