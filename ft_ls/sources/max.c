/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 19:46:45 by fherbine          #+#    #+#             */
/*   Updated: 2018/02/06 17:04:40 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void			lfm_aux(t_rfile *cp, int param, int *max)
{
	char			*t;
	int				tmp;
	struct stat		buf;

	lstat(cp->path, &buf);
	if (param == 0)
	{
		t = get_user(buf);
		tmp = ft_strlen(t);
		free(t);
	}
	else if (param == 1)
	{
		t = get_grp(buf);
		tmp = ft_strlen(t);
		free(t);
	}
	else if (param == 2)
		tmp = ft_nlen_10(buf.st_nlink);
	else
		tmp = ft_nlen_10(buf.st_size);
	if (tmp > *max)
		*max = tmp;
}

static int			looking_for_max(t_rfile *rfile, int param, t_params *p)
{
	t_rfile			*cp;
	int				max;

	cp = rfile;
	max = 0;
	while (cp)
	{
		if ((cp->name[0] == '.' && ft_strchr(p->options, 'a')) || \
				cp->name[0] != '.')
			lfm_aux(cp, param, &max);
		cp = cp->next;
	}
	return (max);
}

t_params			*max_disp(t_params *params, t_rfile *rfile)
{
	t_rfile			*cp;

	cp = rfile;
	params->max_u = 0;
	params->max_g = 0;
	params->max_l = 0;
	params->max_s = 0;
	if (ft_strchr(params->options, 'l') || ft_strchr(params->options, 'o'))
	{
		params->max_u = looking_for_max(cp, 0, params);
		params->max_g = looking_for_max(cp, 1, params);
		params->max_l = looking_for_max(cp, 2, params);
		params->max_s = looking_for_max(cp, 3, params);
	}
	return (params);
}
