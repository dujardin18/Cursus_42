/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 11:05:41 by fherbine          #+#    #+#             */
/*   Updated: 2018/01/02 12:00:42 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flags		ft_putflags(t_flags flags, char *format, int *i)
{
	if (ft_strchr("-+#0 ", format[*i]) != NULL)
	{
		while (format[*i] && ft_strchr("-+#0 ", format[*i]) != NULL && *i < 5)
		{
			flags.flag[*i] = format[*i];
			(*i)++;
		}
	}
	flags.flag[*i] = '\0';
	return (flags);
}

static t_flags		ft_putwidth(t_flags flags, char *format, int *i)
{
	flags.width = 0;
	if (format[*i] >= 48 && format[*i] <= 57)
	{
		flags.width = ft_atoi(&(format[*i]));
		while (format[*i] >= 48 && format[*i] <= 57)
			(*i)++;
	}
	return (flags);
}

static t_flags		ft_putprecision(t_flags flags, char *format, int *i)
{
	flags.precision = -1;
	if (format[*i] == '.')
	{
		(*i)++;
		flags.precision = ft_atoi(&(format[*i]));
		while (format[*i] >= 48 && format[*i] <= 57)
			(*i)++;
	}
	return (flags);
}

static t_flags		ft_putspec(t_flags flags, char *format, int *i, int *n)
{
	if (format[*i] && ft_strchr("dDiuUoOxXcCsSp%", format[*i]))
		flags.specifier = format[*i];
	else
	{
		if (ft_strchr(flags.flag, '-'))
		{
			ft_putchar(format[*i]);
			ft_print_nc(flags.width - 1, ' ');
			(*n) += (flags.width == 0 && format[*i]) ? 1 : flags.width;
		}
		else
		{
			if (ft_strchr(flags.flag, '0'))
				ft_print_nc(flags.width - 1, '0');
			else
				ft_print_nc(flags.width - 1, ' ');
			ft_putchar(format[*i]);
			(*n) += (flags.width == 0 && format[*i]) ? 1 : flags.width;
		}
		flags.specifier = 'Q';
	}
	return (flags);
}

int					ft_reading_spe(char *format, int *n, va_list ap)
{
	int				i;
	t_flags			flags;

	flags.to_put = ' ';
	i = 0;
	flags = ft_putflags(flags, format, &i);
	flags = ft_putwidth(flags, format, &i);
	flags = ft_putprecision(flags, format, &i);
	flags.length = ft_length(&(format[i]));
	if (ft_strchr("lhjz", format[i]))
	{
		while (ft_strchr("lhjz", format[i]) && format[i])
			i++;
	}
	flags = ft_putspec(flags, format, &i, n);
	ft_printing_spe(flags, ap, n);
	return (i);
}
