/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rparser.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 11:14:41 by fherbine          #+#    #+#             */
/*   Updated: 2018/02/01 17:34:43 by fherbine         ###   ########.fr       */
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

t_rfile		*new_rfile(char *path, t_params *params)
{
	char **pdir;
	char *tmp;
	int i;
	t_rfile *first;

	first = NULL;
	i = 0;
	if (!(pdir = sort_pdir(new_pdir(path), params, path)))
		return (NULL);
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
	return (first);
}
