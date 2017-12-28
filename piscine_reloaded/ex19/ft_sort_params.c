/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:22:01 by fherbine          #+#    #+#             */
/*   Updated: 2017/11/06 17:41:27 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_puttab(int len, char **tab)
{
	int		i;

	i = 1;
	while (i < len)
	{
		ft_putstr(tab[i]);
		ft_putchar('\n');
		i++;
	}
}

int		ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int		main(int argc, char **argv)
{
	int		i;
	int		i2;
	char	*tmp;

	i = 1;
	i2 = 1;
	while (i < argc)
	{
		while (i2 < argc)
		{
			if (ft_strcmp(argv[i], argv[i2]) < 0 && i != i2)
			{
				tmp = argv[i];
				argv[i] = argv[i2];
				argv[i2] = tmp;
			}
			i2++;
		}
		i++;
		i2 = 1;
	}
	ft_puttab(argc, argv);
	return (0);
}
