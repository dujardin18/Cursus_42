/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftsl_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 17:23:02 by fherbine          #+#    #+#             */
/*   Updated: 2018/04/09 11:22:49 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void	term_name_not_found(void)
{
	ft_prints_fd(2, "ft_select: Cannot find terminal name (TERM var) in your\
		   	environnement\n");
	exit(EXIT_FAILURE);
}

void	cannot_get_termcaps(void)
{
	ft_prints_fd(2, "ft_select: An error occured when the program tried to get \
			terminal capacities\n");
	exit(EXIT_FAILURE);
}

void	other_err(void)
{
	ft_prints_fd(2, "ft_select: An error occured\n");
	exit(EXIT_FAILURE);
}

void	def_err(void)
{
	ft_prints_fd(2, "ft_select: Cannot reset default termcaps\n");
	exit(EXIT_FAILURE);
}
