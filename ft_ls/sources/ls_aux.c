/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 16:06:48 by fherbine          #+#    #+#             */
/*   Updated: 2018/02/11 18:19:25 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		ft_ls_aux(t_params *params, t_path *cp)
{
	int		disp;
	int		ev;
	int		c;

	disp = (params->files->next != NULL) ? 1 : 0;
	ev = 0;
	c = 0;
	while (cp)
	{
		if (!file_is_dir(cp->name) || file_is_lnk(cp->name, params) || \
				file_is_olnk(cp->name, params))
		{
			params->max_u = 0;
			params->max_g = 0;
			params->max_l = 0;
			params->max_s = 0;
			display_lf_aux(cp->name, cp->name, params);
			ev++;
		}
		c++;
		cp = cp->next;
	}
	if (c != ev && ev > 0)
		ft_putendl("");
	cp = params->files;
}

t_params	*ft_ls_aux3(t_rfile *rfile, t_path *cp, t_params *params)
{
	rfile = new_rfile(cp->name, params);
	if (ft_strchr(params->options, 'l') || ft_strchr(params->options, 'o'))
	{
		lf_total(params->options, cp->name, 0, 0);
		params = max_disp(params, rfile);
	}
	ft_display_dir(rfile, params);
	free_rfile(rfile);
	return (params);
}

void		ft_ls_aux2(t_path *cp, t_rfile *rfile, t_path *tmp, \
		t_params *params)
{
	while (cp)
	{
		if (!file_is_olnk(cp->name, params))
		{
			if (params->multi && params->first && file_is_dir2(cp->name, \
						params))
				ft_prints("\n%s:\n", cp->name);
			else if (params->multi && file_is_dir2(cp->name, params))
			{
				ft_prints("%s:\n", cp->name);
				params->first = 1;
			}
			if (ft_strchr(params->options, 'R'))
				ls_r(params, cp->name, cp->name);
			else
				params = ft_ls_aux3(rfile, cp, params);
		}
		cp = cp->next;
	}
	free_tpath(tmp);
}
