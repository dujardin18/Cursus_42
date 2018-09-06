/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 23:41:20 by fherbine          #+#    #+#             */
/*   Updated: 2018/09/06 23:58:11 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	msg_exit(char *msg)
{
	ft_prints_fd(STDERR, "%sERROR: %s%s\n", RED, REGULAR, msg);
	exit(EXIT_FAILURE);
}
