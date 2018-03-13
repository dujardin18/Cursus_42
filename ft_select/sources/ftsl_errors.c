/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftsl_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 17:23:02 by fherbine          #+#    #+#             */
/*   Updated: 2018/03/13 17:27:33 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void	term_name_not_found(void)
{
	ft_prints_fd(2, "ft_select: Cannot find terminal name (TERM var) in your\
		   	environnement");
	exit(EXIT_FAILURE);
}
