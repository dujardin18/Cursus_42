/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 18:47:33 by fherbine          #+#    #+#             */
/*   Updated: 2017/12/22 13:54:41 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fdf.h"

int			ft_natoi(char *str)
{
	int		i;
	int		n;
	char	*cpy;

	i = 0;
	if (!(cpy = (char *)ft_memalloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (0);
	while (str[i] && ((str[i] >= 48 && str[i] <= 57) || str[i] == 45))
	{
		cpy[i] = str[i];
		i++;
	}
	n = ft_atoi(cpy);
	free(cpy);
	return (n);
}

int			ft_kill_parse(void)
{
	ft_putendl_fd("Fichier invalide /!\\", 2);
	exit(EXIT_FAILURE);
	return (0);
}
