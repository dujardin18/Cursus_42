/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reading_format.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 11:42:30 by fherbine          #+#    #+#             */
/*   Updated: 2018/01/02 17:52:03 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_reading_non_spe(char *format, int *n)
{
	int			i;

	i = 0;
	while (format[i] && format[i] != '%')
	{
		ft_putchar(format[i]);
		i++;
	}
	*n += i;
	return (i);
}

t_length		ft_length(char *str)
{
	int			i;
	t_length	ret;

	i = 0;
	if (str[i] == 'h')
		ret = (str[i + 1] == 'h') ? hh : h;
	else if (str[i] == 'l')
		ret = (str[i + 1] == 'l') ? ll : l;
	else if (str[i] == 'j')
		ret = j;
	else if (str[i] == 'z')
		ret = z;
	else if (str[i] == 't')
		ret = t;
	else
		ret = none;
	return (ret);
}

void			ft_printing_spe(t_flags flags, va_list ap, int *n)
{
	if (flags.specifier == 'c')
		ft_printing_char(flags, va_arg(ap, int), n);
	else if (flags.specifier == 's')
		ft_printing_string(flags, va_arg(ap, char *), n);
	else if (flags.specifier == 'x' || flags.specifier == 'X')
		ft_printing_hex(flags, va_arg(ap, uintmax_t), n);
	else if (flags.specifier == 'O' || flags.specifier == 'o')
		ft_printing_oct(flags, va_arg(ap, uintmax_t), n);
	else if (flags.specifier == 'p')
		ft_printing_ptr(flags, va_arg(ap, void *), n);
	else if (ft_strchr("dDi", flags.specifier))
		ft_printing_dec(flags, va_arg(ap, intmax_t), n);
	else if (flags.specifier == 'u' || flags.specifier == 'U')
		ft_printing_udec(flags, va_arg(ap, uintmax_t), n);
	else if (flags.specifier == '%')
		ft_printing_prct(flags, n);
	else if (flags.specifier == 'C')
		ft_printing_char(flags, va_arg(ap, wint_t), n);
	else if (flags.specifier == 'S')
		ft_printing_string(flags, (char *)va_arg(ap, wchar_t *), n);
	else if (flags.specifier == 'Q')
		return ;
}

int				ft_reading_format(char *format, va_list ap)
{
	int			i;
	int			n;

	i = 0;
	n = 0;
	while (format[i])
	{
		i += ft_reading_non_spe(&(format[i]), &n);
		if (format[i] == '\0')
			break ;
		i++;
		i += ft_reading_spe(&(format[i]), &n, ap);
		if (format[i] == '\0')
			break ;
		i++;
	}
	return (n);
}
