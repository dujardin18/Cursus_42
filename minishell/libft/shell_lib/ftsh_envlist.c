/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftsh_envlist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 16:34:10 by fherbine          #+#    #+#             */
/*   Updated: 2018/02/19 18:21:41 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static t_envlist	*new_envl(char *value)
{
	t_envlist		*first;

	if (!(first = (t_envlist *)malloc(sizeof(t_envlist))))
		exit(EXIT_FAILURE);
	first->value = ft_strdup(value);
	first->next = NULL;
	return (first);
}

static t_envlist	*add_envl_elem(t_envlist *first, char *value)
{
	t_envlist		*new;
	t_envlist		*tmp;

	if (first)
	{
		tmp = first;
		while (tmp->next)
			tmp = tmp->next;
		if (!(new = (t_envlist *)malloc(sizeof(t_envlist))))
			exit(EXIT_FAILURE);
		new->value = ft_strdup(value);
		new->next = NULL;
		tmp->next = new;
	}
	else
		first = new_envl(value);
	return (first);
}

char				*take_only_value(char *value)
{
	char			*ret;
	int				i;

	i = 0;
	if (!(ret = (char *)malloc(sizeof(char) * (ft_strlen(value) + 1))))
		exit(EXIT_FAILURE);
	while (value[i] && value[i] != ':')
	{
		ret[i] = value[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

t_envlist			*get_envlist(char **envp, char *name)
{
	char			*value;
	char			*tmp;
	t_envlist		*ret;
	int				i;

	ret = NULL;
	i = 0;
	value = ftsh_search_envar(envp, name);
	while (value[i])
	{
		tmp = take_only_value(&(value[i]));
		ret = add_envl_elem(ret, tmp);
		free(tmp);
		while (value[i] && value[i] != ':')
			i++;
		i += (value[i] == ':') ? 1 : 0;
	}
	free(value);
	return (ret);
}
