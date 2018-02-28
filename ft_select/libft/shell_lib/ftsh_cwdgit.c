/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftsh_cwdgit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:17:06 by fherbine          #+#    #+#             */
/*   Updated: 2018/02/14 16:39:55 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int			ftsh_cwdgit(char *p_cwd)
{
	DIR				*dir;
	struct dirent	*new;

	dir = NULL;
	new = NULL;
	if ((dir = opendir(p_cwd)))
	{
		if (!(new = readdir(dir)))
			return (0);
		while (new && new->d_name[0] == '.')
		{
			if (ft_strcmp(new->d_name, ".git") == 0)
				return (1);
			new = readdir(dir);
		}
	}
	return (0);
}
