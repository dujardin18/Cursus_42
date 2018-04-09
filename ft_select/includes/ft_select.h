/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 17:13:59 by fherbine          #+#    #+#             */
/*   Updated: 2018/04/09 15:41:40 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H

# define FT_SELECT_H

# include "../libft/libft.h"
# include "sl_key.h"
# include "sl_term.h"
# include <term.h>
# include <termios.h>
# include <sys/ioctl.h> 

typedef struct	s_slp
{
	struct winsize	sz;
}				t_slp;

void			term_name_not_found(void);
void			cannot_get_termcaps(void);
void			other_err(void);
void			def_err(void);

void			modif_trm(void);

void			default_trm(void);

void			init_cursor(void);
t_slp			init_slp(void);

void			goto_cursor(int x, int y);

#endif
