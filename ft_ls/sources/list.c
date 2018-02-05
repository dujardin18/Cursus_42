/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 13:51:36 by fherbine          #+#    #+#             */
/*   Updated: 2018/02/05 19:33:14 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static t_path	*first_elem(char *new_content)
{
	t_path		*new;

	if (!(new = (t_path *)malloc(sizeof(t_path))))
		exit(EXIT_FAILURE);
	new->name = ft_strdup(new_content);
	new->next = NULL;
	return (new);
}

t_path			*ft_add_path(char *new_content, t_path *current)
{
	t_path		*tmp;
	t_path		*new;

	if (new_content)
	{
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
			current = first_elem(new_content);
	}
	return (current);
}

t_path			*ft_add_path_rev(char *new_content, t_path *current)
{
	t_path		*new;

	if (new_content)
	{
		if (current)
		{
			if (!(new = (t_path *)malloc(sizeof(t_path))))
				exit(EXIT_FAILURE);
			new->name = ft_strdup(new_content);
			new->next = current;
			current = new;
		}
		else
			current = first_elem(new_content);
	}
	return (current);
}

t_path			*current_dir(void)
{
	t_path		*ret;

	if (!(ret = (t_path *)malloc(sizeof(t_path))))
		exit(EXIT_FAILURE);
	if (!(ret->name = ft_strdup(".")))
		exit(EXIT_FAILURE);
	ret->next = NULL;
	return (ret);
}
