/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 23:27:44 by fherbine          #+#    #+#             */
/*   Updated: 2018/09/03 02:28:30 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static u8	is_searched_var(s8 *line, s8 *search)
{
	u16		i;

	i = 0;
	if (!line || !search)
		return (0);
	while (line[i] && line[i] != '=')
		i++;
	if (!ft_strncmp(line, search, i))
		return (1);
	return (0);
}

static s8	*get_var_value(s8 *line)
{
	u16		i;
	u16		i2;
	u8		*ret;

	i = 0;
	i2 = 0;
	while (line[i] && line[i] != '=')
		i++;
	if (!line[i] || line[i] != '=')
		return (NULL);
	ret = (s8 *)ft_memaloc(ft_strlen(line - i + 1));
	i++;
	while (line[i])
	{
		ret[i2] = line[i];
		i++;
		i2++;
	}
	return (ret);
}

s8		*ft_getenv(s8 **envp, s8 *search)
{
	u32	i;

	i = 0;
	while (envp[i])
	{
		if (is_searched_var(envp[i], search))
			return (get_var_value(envp[i]));
		i++;
	}
	return (NULL);
}
