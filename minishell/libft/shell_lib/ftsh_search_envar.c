/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftsh_search_envar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 13:53:57 by fherbine          #+#    #+#             */
/*   Updated: 2018/02/15 20:51:10 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	get_name_in_line(char *line, char *name)
{
	char	*tmp;
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	if (!(tmp = (char *)malloc(sizeof(char) * (ft_strlen(line) + 1))))
		exit(EXIT_FAILURE);
	while (line[i] && line[i] != '=')
	{
		tmp[i] = line[i];
		i++;
	}
	tmp[i] = '\0';
	if (ft_strcmp(tmp, name) == 0)
		ret = 1;
	free(tmp);
	return (ret);
}

static int	spec_len_env(char *line)
{
	int		tmp;
	int		i;

	tmp = ft_strlen(line);
	i = 0;
	while (line[i] && line[i] != '=')
		i++;
	return ((tmp - i >= 0) ? tmp - i : 0);
}

static char		*get_value(char *line)
{
	char		*ret;
	int			i;
	int			i2;

	i = 0;
	i2 = 0;
	if (!(ret = (char *)malloc(sizeof(char) * (spec_len_env(line)))))
		exit(EXIT_FAILURE);
	while (line[i] && line[i] != '=')
		i++;
	i += (line[i] == '=') ? 1 : 0;
	while (line[i])
	{
		ret[i2] = line[i];
		i++;
		i2++;
	}
	ret[i2] = '\0';
	return (ret);
}

char		*ftsh_search_envar(char **envp, char *name)
{
	int		i;

	i = 0;
	while (envp[i])
	{
		if (get_name_in_line(envp[i], name))
			return (get_value(envp[i]));
		i++;
	}
	return (NULL);
}
