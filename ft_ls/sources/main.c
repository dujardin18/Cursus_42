/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 17:08:40 by fherbine          #+#    #+#             */
/*   Updated: 2018/01/19 17:36:23 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void			ft_debug_params(t_params *params)
{
	int i = 1;

	if (params->files)
		ft_prints("liste chainee de fichier a analyser :\n");
	while (params->files)
	{
		ft_prints("\t%d. |%s|\n",i, params->files->name);
		params->files = params->files->next;
		i++;
	}
	if (params->options[0])
		ft_prints("\nFlags a appliquer (par ordre d'arrivee) :\n");
	i = 0;
	while ((params->options)[i])
	{
		ft_prints("\t-%c\n", (params->options)[i]);
		i++;
	}
	ft_prints("\n");
}

int				main(int argc, char **argv)
{
	t_params	*params;

	params = ft_parser(argc, argv);
	if (DEBUG)
		ft_debug_params(params);
	return (0);
}
