/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   babab.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 19:55:44 by fherbine          #+#    #+#             */
/*   Updated: 2017/11/27 10:25:39 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BABAB_H
# define BABAB_H
# include "./libft/libft.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef	struct				s_tetri_list
{
	char					**tetrimino;
	size_t					i;
	struct s_tetri_list		*next;
}							t_tt_list;

size_t						ft_square_min(t_tt_list *list);
char						**ft_make_square(size_t n);
char						**ft_malloc_square(char **tab, int size);
size_t						ft_nline(char *str);
int							ft_fillit_backtrack(t_tt_list *list, \
		char ***square, size_t position);
t_tt_list					*ft_tetri(int fd);
char						**ft_new_tab(char *str);
t_tt_list					*ft_add_tts(t_tt_list *alst, char **tab, \
		size_t index);

#endif
