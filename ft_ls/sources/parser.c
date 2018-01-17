/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 17:13:14 by fherbine          #+#    #+#             */
/*   Updated: 2018/01/17 17:43:37 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static int	ft_flags_checker(int argc, char **argv)
{
	int		i;
	int		i2;

	i = 1;
	while (i < argc)
	{
		i2 = 1;
		if (argv[i][0] == '-')
		{
			while (argv[i][i2])
			{
				if (!ft_strchr("alrRt", argv[i][i2]))
					ft_illegal_optn(argv[i][i2]);
				i2++;
			}
		}
		else
			break ;
		i++;
	}
	return (1);
}

t_params		*ft_parser(int argc, char **argv)
{
	t_params	*params = NULL;

	if (ft_flags_checker(argc, argv))
	{
		ft_prints("okok");
	}
	return (params);
}
