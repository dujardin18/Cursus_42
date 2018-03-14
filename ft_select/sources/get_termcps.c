/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_termcps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 17:12:56 by fherbine          #+#    #+#             */
/*   Updated: 2018/03/14 15:44:58 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

struct termios	init_trmcps(char **envp)
{
	char			*term_name;
	struct termios	term_c;

	if (!(term_name = ftsh_search_envar(envp, "TERM")))
		term_name_not_found();
	if (tgetent(NULL, &term_name) == ERR)
		cannot_get_termcaps();
	if (tcgetattr(0, &term_c) == -1)
		other_err();
	free(term_name);
}
