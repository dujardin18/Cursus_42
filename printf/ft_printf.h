/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 11:00:02 by fherbine          #+#    #+#             */
/*   Updated: 2018/01/02 18:01:42 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "./libft/libft.h"
# include <stdarg.h>
# include <inttypes.h>
# include <wchar.h>

typedef enum	e_length
{
	h, hh, l, ll, j, z, t, none
}				t_length;

typedef struct	s_flags
{
	char		flag[6];
	int			width;
	int			precision;
	t_length	length;
	char		specifier;
	char		to_put;
}				t_flags;

t_length		ft_length(char *str);
void			ft_printing_spe(t_flags flags, va_list ap, int *n);
int				ft_reading_spe(char *format, int *n, va_list ap);
uintmax_t		ft_ucast_length(uintmax_t n, t_flags flags);
intmax_t		ft_cast_length(intmax_t n, t_flags flags);
int				ft_put_n_chars(int n, char c);
int				ft_put_nz(int n);
void			ft_print_nc(int n, char c);
int				ft_reading_format(char *format, va_list ap);
int				ft_printf(const char *format, ...);
void			ft_printing_char(t_flags flags, int c, int *n);
void			ft_printing_string(t_flags flags, char *str, int *n);
void			ft_printing_hex(t_flags flags, uintmax_t n, int *a);
void			ft_printing_oct(t_flags flags, uintmax_t n, int *a);
void			ft_printing_ptr(t_flags flags, void *p, int *n);
void			ft_printing_prct(t_flags flags, int *n);
void			ft_printing_dec(t_flags flags, intmax_t n, int *a);
void			ft_printing_udec(t_flags flags, uintmax_t n, int *a);
#endif
