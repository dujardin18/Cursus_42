/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftsh_get_np.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:30:40 by fherbine          #+#    #+#             */
/*   Updated: 2018/02/15 20:52:58 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	get_alloc_sz(char *str)
{
	int		i;
	int		len;

	i = ft_strlen(str) - 1;
	len = ft_strlen(str);
	while (i > 0 && str[i] != '/')
		i--;
	return (len - i);
}

char		*ftsh_get_np(char *path)
{
	char	*ret;
	int		i;
	int		i2;

	if (!(ret = (char *)malloc(sizeof(char) * (get_alloc_sz(path) + 1))))
		exit(EXIT_FAILURE);
	i = ft_strlen(path) - 1;
	i2 = 0;
	while (i > 0 && path[i] != '/')
		i--;
	i += (path[i] == '/') ? 1 : 0;
	while (path[i])
	{
		ret[i2] = path[i];
		i++;
		i2++;
	}
	ret[i2] = '\0';
	return (ret);
}
