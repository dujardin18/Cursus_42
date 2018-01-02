/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 15:30:29 by fherbine          #+#    #+#             */
/*   Updated: 2018/01/02 17:55:42 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_char_new_size(char *str, int end)
{
	int			i;

	i = 0;
	while (i < end)
		i++;
	str[i] = '\0';
	return (str);
}

static int		ft_putstr_n(char *str)
{
	ft_putstr(str);
	return ((ft_strlen(str) > 0) ? ft_strlen(str) - 1 : ft_strlen(str));
}

void			ft_modif_str(t_flags flags, char *str2, int *n, int tmp)
{
	int			i;

	i = 0;
	if (ft_strchr(flags.flag, '0'))
		flags.to_put = '0';
	if (ft_strchr(flags.flag, '-'))
	{
		tmp = 0;
		if (!(str2[0]))
		{
			flags.width++;
			(*n)--;
		}
	}
	while (i < flags.width)
	{
		if (tmp == i)
			i += ft_putstr_n(str2);
		else
			ft_putchar(flags.to_put);
		i++;
	}
	free(str2);
	(*n) += i;
}

void			ft_printing_stringnu(t_flags flags, char *str, int *n)
{
	int			tmp;
	char		*str2;

	str2 = (str == NULL) ? ft_strdup("(null)") : ft_strdup(str);
	if (flags.precision >= 0 && flags.precision <= (int)ft_strlen(str))
		str2 = ft_char_new_size(str2, flags.precision);
	if (flags.width > (int)ft_strlen(str2))
		tmp = flags.width - ft_strlen(str2);
	else
	{
		flags.width = (int)ft_strlen(str2);
		tmp = 0;
	}
	ft_modif_str(flags, str2, n, tmp);
}

void			ft_printing_string(t_flags flags, char *str, int *n)
{
	if (flags.specifier == 's')
		ft_printing_stringnu(flags, str, n);
}
