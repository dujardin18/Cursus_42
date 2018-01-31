/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rparser.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 11:14:41 by fherbine          #+#    #+#             */
/*   Updated: 2018/01/29 19:30:14 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static t_rfile		*new_rf_lst(t_rfile *first, char *path, char *name)
{
	if (!(first = (t_rfile *)malloc(sizeof(t_rfile))))
		exit(EXIT_FAILURE);
	first->path = ft_strdup(path);
	first->name = ft_strdup(name);
	first->next = NULL;
	return (first);
}

static t_rfile		*add_rf_elem(t_rfile *first, char *path, char *name)
{
	t_rfile *new;

	if (first)
	{
		if (!(new = (t_rfile *)malloc(sizeof(t_rfile))))
			exit(EXIT_FAILURE);
		ft_prints("\033[0;33;40m%s\033[0m\n", path);
		new->path = ft_strdup(path);
		new->name = ft_strdup(name);
		new->next = first;
		first = new;
	}
	else
		first = new_rf_lst(first, path, name);
	return (first);
}

static t_rfile		*add_rf_elem_rev(t_rfile *first, char *path, char *name)
{
	t_rfile *new;
	t_rfile *tmp;

	tmp = first;
	if (first)
	{
		while (tmp->next)
			tmp = tmp->next;
		if (!(new = (t_rfile *)malloc(sizeof(t_rfile))))
			exit(EXIT_FAILURE);
		new->path = ft_strdup(path);
		new->name = ft_strdup(name);
		new->next = NULL;
		tmp->next = new;
	}
	else
		first = new_rf_lst(first, path, name);
	return (first);
}

void		ft_debug_rfile(t_rfile *rfile, char *path)
{
	t_rfile *cp;
		ft_prints("\033[0;32;40mP:%s\033[0m\n",path);
	while (cp)
	{
		ft_prints("\033[0;32;40mP:%s %s\033[0m\n",path , cp->path);
	}
}

void		ft_debug_pdir(char **pdir, char *path)
{
	int i = 0;
	ft_putendl("\033[0;35;40m");
	ft_prints("%s\n", path);
	while (pdir[i])
	{
		ft_prints("%s\t", pdir[i]);
		i++;
	}
	ft_putendl("\033[0m");
}

t_rfile		*new_rfile(char *path, t_params *params)
{
	char **pdir;
	char *tmp;
	int i;
	t_rfile *first;

	first = NULL;
	i = 0;
	//ft_prints("\033[0;31;40m%s\033[0m\n", ft_strdup(path));
	if (!(pdir = sort_pdir(new_pdir(path), params, path)))
		return (NULL);
	ft_putendl("not NULL");
	ft_debug_pdir(pdir, path);
	while (pdir[i])
	{
		tmp = ft_strdup(path);
		tmp = ft_strjoin(tmp, "/");
		tmp = ft_strjoin(tmp, pdir[i]);
		if (ft_strchr(params->options, 'r'))
			first = add_rf_elem(first, tmp, pdir[i]);
		else
			first = add_rf_elem_rev(first, tmp, pdir[i]);
		i++;
		free(tmp);
	}
	close_tab(pdir);
	free(pdir);
	ft_debug_rfile(first, path);
	return (first);
}
