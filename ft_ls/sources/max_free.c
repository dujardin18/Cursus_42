/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 17:45:43 by fherbine          #+#    #+#             */
/*   Updated: 2018/02/01 18:02:16 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void free_rfile(t_rfile *rfile)
{
	t_rfile *tmp;

	tmp = NULL;
	while (rfile)
	{
		free(rfile->name);
		free(rfile->path);
		tmp = rfile->next;
		free(rfile);
		rfile = tmp;
		tmp = NULL;
	}
}

void	free_tpath(t_path *tpath)
{
	t_path	*tmp;

	tmp = NULL;
	while (tpath)
	{
		free(tpath->name);
		tmp = tpath->next;
		free(tpath);
		tpath = tmp;
		tmp = NULL;
	}
}
