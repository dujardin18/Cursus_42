/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_termcps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 17:12:56 by fherbine          #+#    #+#             */
/*   Updated: 2018/03/14 15:26:06 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

struct termios	init_trmcps(char **envp)
{
	char		*term_name;

	if (!(term_name = ftsh_search_envar(envp, "TERM")))
		term_name_not_found();
	if (tgetent(NULL, &term_name) == ERR)
		cannot_get_termcaps();
	free(term_name);
}
