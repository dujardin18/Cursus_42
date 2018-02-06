/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 18:27:49 by fherbine          #+#    #+#             */
/*   Updated: 2018/02/06 17:33:45 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char		*new_path(char *path, char *name)
{
	char	*ret;

	ret = ft_strdup(path);
	ret = ft_strjoin(ret, name);
	return (ret);
}

void		ft_display_dir(t_rfile *rfile, t_params *params)
{
	t_rfile	*cp;

	cp = rfile;
	while (cp)
	{
		display_lf_aux(cp->path, cp->name, params);
		cp = cp->next;
	}
}

void		ls_r(t_params *p, char *path, char *first)
{
	t_rfile	*new;
	t_rfile	*tmp;

	new = new_rfile(path, p);
	tmp = new;
	if (ft_strcmp(path, first) != 0 && file_is_dir2(path, new))
		ft_prints("\n%s:\n", path);
	if (new == NULL)
		return ;
	if (ft_strchr(p->options, 'l') || ft_strchr(p->options, 'o'))
		lf_total(p->options, path, 0, 0);
	p = (ft_strchr(p->options, 'l') || \
				ft_strchr(p->options, 'o')) ? max_disp(p, new) : p;
	ft_display_dir(new, p);
	while (new)
	{
		if (ft_strcmp(new->name, ".") != 0 && ft_strcmp(new->name, "..") != 0)
		{
			if (ft_strchr(p->options, 'a') || new->name[0] != '.')
				ls_r(p, new->path, first);
		}
		new = new->next;
	}
	free_rfile(tmp);
	return ;
}

void		ft_ls(t_params *params)
{
	t_rfile	*rfile;
	t_path	*cp;
	t_path	*tmp;

	rfile = NULL;
	cp = params->files;
	tmp = cp;
	ft_ls_aux(params, cp);
	cp = params->files;
	ft_ls_aux2(cp, rfile, tmp, params);
}
