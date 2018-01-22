/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 13:51:36 by fherbine          #+#    #+#             */
/*   Updated: 2018/01/22 15:34:06 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_path	*ft_add_path(char *new_content, t_path *current)
{
	t_path		*tmp;
	t_path		*new;

	if (current)
	{
		tmp = current;
		while (tmp->next)
			tmp = tmp->next;
		if (!(new = (t_path *)malloc(sizeof(t_path))))
			exit(EXIT_FAILURE);
		new->name = ft_strdup(new_content);
		new->next = NULL;
		tmp->next = new;
	}
	else
	{
		if (!(new = (t_path *)malloc(sizeof(t_path))))
			exit(EXIT_FAILURE);
		new->name = ft_strdup(new_content);
		new->next = NULL;
		current = new;
	}
	//free new ?
	return (current);
}

t_path	*ft_add_path_rev(char *new_content, t_path *current)
{
	t_path	*new;

	if (current)
	{
		if (!(new = (t_path *)malloc(sizeof(t_path))))
			exit(EXIT_FAILURE);
		new->name = new_content;
		new->next = current;
		current = new;
	}
	else
	{
		if (!(new = (t_path	*)malloc(sizeof(t_path))))
			exit(EXIT_FAILURE);
		new->next = NULL;
		new->name = new_content;
		current = new;
	}
	return (current);
}

t_path	*current_dir()
{
	t_path		*ret;

	if (!(ret = (t_path *)malloc(sizeof(t_path))))
		exit(EXIT_FAILURE);
	if (!(ret->name = ft_strdup(".")))
		exit(EXIT_FAILURE);
	ret->next = NULL;
	return (ret);
}
