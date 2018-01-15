/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:07:08 by fherbine          #+#    #+#             */
/*   Updated: 2018/01/15 17:06:24 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
#define CHECKER_H

# include "../libft/libft.h"
# include <stdlib.h>
# define DEBUG 1

typedef struct		s_pile
{
	int				nb;
	struct s_pile	*next;
}					t_pile;

typedef enum		e_instruction
{
	sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr, none
}					t_instruction;

typedef	struct		s_order
{
	t_instruction	inst;
	struct s_order	*next;
}					t_order;

void				ft_kill(int param);
void				ft_error(void);
t_pile				*ft_malloc_secure(t_pile *to_alloc);

t_pile				*ft_new_pile(int first_nb);
t_pile				*ft_add_in_pile(int nb_to_add, t_pile *first);
int					ft_pile_len(t_pile *pile);
int					ft_pile_is_sorted(t_pile *pile);

t_pile				*ft_parser(int argc, char **argv);

t_order				*ft_instructions(void);

void				ft_do_actions(t_order *orders, t_pile **pile_a, t_pile **pile_b);

int					ft_check_piles(t_pile *pile_a, t_pile *pile_b);

////////////////////////////////////// DEBUG
void				ft_display_list(t_pile *pile);
void 				ft_display_list2(t_order *order);
void				ft_debug(t_pile *pile_a, t_pile *pile_b);
////////////////////////////////////// EOD
#endif
