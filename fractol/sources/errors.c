/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 23:41:20 by fherbine          #+#    #+#             */
/*   Updated: 2018/09/08 04:26:34 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		msg_exit(char *msg)
{
	ft_prints_fd(STDERR, "%sERROR: %s%s\n", RED, REGULAR, msg);
	exit(EXIT_FAILURE);
}

static void	disp_usage(void)
{
	ft_prints_fd(STDERR, "\t%s* USAGE *%s\t\n", GREEN, REGULAR);
	ft_prints_fd(STDERR, "\t./fractol %s<arg>%s\n", BLUE, REGULAR);
	ft_prints_fd(STDERR, "Valid arguments are:\n");
	ft_prints_fd(STDERR, "%smandel%s : The mandelbrot fractal.\t", BLUE, REGULAR);
	ft_prints_fd(STDERR, "%sjulia%s : The julia fractal.\n", BLUE, REGULAR);
	ft_putendl("");
}

void		few_param_ex(void)
{
	disp_usage();
	msg_exit("too few parameters. You should enter at least one param.");
}

void		inv_param_ex(void)
{
	disp_usage();
	msg_exit("Invalid parameter !");
}
