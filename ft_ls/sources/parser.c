/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 17:13:14 by fherbine          #+#    #+#             */
/*   Updated: 2018/01/26 16:18:49 by fherbine         ###   ########.fr       */
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

static t_params *put_all_params(int argc, char **argv, t_params *params, int i)
{
	while (i < argc)
	{
		if (ft_strchr(params->options, 'r') && !(ft_strchr(params->options, 't')))
			params->files = ft_add_path_rev(argv[i], params->files);
		else
			params->files = ft_add_path(argv[i], params->files);
		i++;
	}
	return (params);
}

static t_params	*put_params(int argc, char **argv, t_params *params)
{
	int			i;

	i = 1;
	if (argc > 1)
	{
		if (argv[1][0] == '-')
		{
			while (argv[1][i])
			{
				params->options[i - 1] = argv[1][i];
				i++;
			}
			params->options[i - 1] = '\0';
			i = 2;
		}
	}
	if ((argc > 1 && argv[1][0] != '-') || argc > 2)
		argv = sort_argvs(argc, argv, params->options);
	if ((argc > 1 && argv[1][0] != '-') || argc > 2)
		ft_check_path(argc, argv);
	if (argc > 1)
		params = put_all_params(argc, argv, params, i);
	if (!(params->files))
		params->files = current_dir();
	return (params);
}

t_params		*ft_parser(int argc, char **argv)
{
	t_params	*params = NULL;

	if (!(params = (t_params *)malloc(sizeof(t_params))))
		exit(EXIT_FAILURE);
	params->files = NULL;
	params->options[0] = '\0';
	if (ft_flags_checker(argc, argv))
		params = put_params(argc, argv, params);
	if ((argc > 1 && argv[1][0] != '-') || argc > 2)
		close_tab(argv);
	return (params);
}
