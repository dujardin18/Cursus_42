/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:08:04 by fherbine          #+#    #+#             */
/*   Updated: 2018/01/15 19:59:06 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct		s_pile
{
	int				nb;
	struct s_pile	*next;
}					t_pile;

typedef struct		s_instruction
{
	t_order			order;
	struct s_instruction
}					t_inst;
t_pile				*ft_new_pile(int first_nb);
t_pile				*ft_add_in_pile(int nb_to_add, t_pile *first);
int					ft_pile_len(t_pile *pile);
int					ft_pile_is_sorted(t_pile *pile);

t_pile				*ft_parser(int argc, char **argv);

void				ft_kill(int param);
void				ft_error(void);
t_pile				*ft_malloc_secure(t_pile *to_alloc);

#endif
