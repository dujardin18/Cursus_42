/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shvar_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 15:00:34 by fherbine          #+#    #+#             */
/*   Updated: 2018/02/27 15:05:07 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char			*get_var_name(char *cmd)
{
	int			i;
	char		*ret;

	i = 0;
	if (!(ret = (char *)malloc(sizeof(char) * (ft_strlen(cmd) + 1))))
		exit(EXIT_FAILURE);
	while (cmd[i] && cmd[i] != '=')
	{
		ret[i] = cmd[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char			*get_var_val(char *cmd)
{
	int			i;
	int			i2;
	char		*ret;

	i = 0;
	i2 = 0;
	if (!(ret = (char *)malloc(sizeof(char) * (ft_strlen(cmd) + 1))))
		exit(EXIT_FAILURE);
	while (cmd[i] && cmd[i] != '=')
		i++;
	i += (cmd[i] == '=') ? 1 : 0;
	while (cmd[i])
	{
		ret[i2] = cmd[i];
		i++;
		i2++;
	}
	ret[i2] = '\0';
	return (ret);
}

static	t_shvar	*new_shvar_lst(char *name, char *value)
{
	t_shvar		*new;

	if (!(new = (t_shvar *)malloc(sizeof(t_shvar))))
		exit(EXIT_FAILURE);
	new->name = ft_strdup(name);
	new->value = ft_strdup(value);
	new->next = NULL;
	return (new);
}

t_shvar			*add_shvar_elem(t_shvar *first, char *cmd)
{
	char		*value;
	char		*name;
	t_shvar		*new;

	name = get_var_name(cmd);
	value = get_var_val(cmd);
	if (first)
	{
		if (!(new = (t_shvar *)malloc(sizeof(t_shvar))))
			exit(EXIT_FAILURE);
		new->value = ft_strdup(value);
		new->name = ft_strdup(name);
		new->next = first;
		first = new;
	}
	else
		first = new_shvar_lst(name, value);
	free(value);
	free(name);
	return (first);
}

void			free_shvar(t_shvar *shv_lst)
{
	t_shvar		*cp;

	cp = shv_lst;
	while (shv_lst)
	{
		free(shv_lst->name);
		free(shv_lst->value);
		shv_lst = shv_lst->next;
		free(cp);
		cp = shv_lst;
	}
}
