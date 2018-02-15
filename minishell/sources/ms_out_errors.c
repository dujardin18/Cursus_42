/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_out_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 13:32:43 by fherbine          #+#    #+#             */
/*   Updated: 2018/02/15 20:27:12 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ms_too_much_params(int argc, char **argv)
{
	ft_prints_fd(2, "%s: Too much params, %d params, while 0 needed.\n", \
			argv[0], argc - 1);
	exit(EXIT_FAILURE);
}
