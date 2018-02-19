/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 16:34:00 by fherbine          #+#    #+#             */
/*   Updated: 2018/02/15 20:19:56 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		main(int argc, char **argv, char **envp)
{
	int	end;

	end = 0;
	if (argc == 1)
		prompt_get_cmd_line(envp);
	else
		ms_too_much_params(argc, argv);
	return (0);
}