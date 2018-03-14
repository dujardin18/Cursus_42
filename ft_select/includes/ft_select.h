/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 17:13:59 by fherbine          #+#    #+#             */
/*   Updated: 2018/03/14 15:44:54 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H

# define FT_SELECT_H

# include "../libft/libft.h"
# include <term.h>
# include <termios.h>

void			term_name_not_found(void);
void			cannot_get_termcaps(void);
void			other_err(void);

struct termios	init_trmcps(char **envp);

#endif
