/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 11:56:40 by fherbine          #+#    #+#             */
/*   Updated: 2018/01/09 14:42:49 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ch_includes/checker.h"

static int	ft_checker(int argc, char **argv)
{
	int i;
	int i2;

	i = 1;
	if (argc <= 1)
		ft_error();
	while (argv[i])
	{
		i2 = 0;
		while (argv[i][i2])
		{
			if (i2 == 0)
			{
				if (argv[i][0] != 45 && (argv[i][0] < 48 || argv[i][0] > 57))
					ft_error();
			}
			if ((argv[i][i2] < 48 || argv[i][i2] > 57) && i2 != 0)
				ft_error();
			i2++;
		}
		i++;
	}
	return (1);
}

t_pile		*ft_parser(int argc, char **argv)
{
	t_pile	*pile_a;
	int		i;

	pile_a = NULL;
	i = 2;
	if (ft_checker(argc, argv))
	{
		pile_a = ft_new_pile(ft_atoi(argv[1]));
		while (argv[i])
		{
			pile_a = ft_add_in_pile(ft_atoi(argv[i]), pile_a);
			i++;
		}
	}
	return (pile_a);
}
