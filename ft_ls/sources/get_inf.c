/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_inf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 14:21:52 by fherbine          #+#    #+#             */
/*   Updated: 2018/02/03 16:48:01 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char *get_user(struct stat buf)
{
	if (getpwuid(buf.st_uid))
		return (ft_strdup(getpwuid(buf.st_uid)->pw_name));
	else
		return (ft_itoa(buf.st_uid));
}

char *get_grp(struct stat buf)
{
	if (getgrgid(buf.st_gid))
		return (ft_strdup(getgrgid(buf.st_gid)->gr_name));
	else
		return (ft_itoa(buf.st_gid));
}
