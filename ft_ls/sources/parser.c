/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 17:13:14 by fherbine          #+#    #+#             */
/*   Updated: 2018/02/07 18:50:20 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static int		ft_flags_checker(int argc, char **argv)
{
	int			i;
	int			i2;

	i = 1;
	while (i < argc)
	{
		i2 = 1;
		if (argv[i][0] == '-')
		{
			if (argv[i][1] == '-' && !argv[i][2])
				return (1);
			while (argv[i][i2])
			{
				if (!ft_strchr("1alrAfpoRtG", argv[i][i2]))
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

static t_params	*put_all_params(int argc, char **argv, t_params *params, int i)
{
	while (i < argc)
	{
		if (ft_strchr(params->options, 'r') && \
				!(ft_strchr(params->options, 't')))
			params->files = ft_add_path_rev(argv[i], params->files);
		else
			params->files = ft_add_path(argv[i], params->files);
		i++;
	}
	return (params);
}

static t_params	*pp_aux(int *i, int argc, char **argv, t_params *params)
{
	int			tmp;
	int			i2;

	tmp = 0;
	i2 = 1;
	while (*i < argc && argv[*i][0] == '-')
	{
		if ((argv[*i][1] == '-' && !argv[*i][2]) || !argv[*i][1] || \
				!ft_strchr("alAorRfptG1", argv[*i][1]))
		{
			(*i) += (argv[*i][1] == '-') ? 1 : 0;
			break ;
		}
		while (argv[*i][i2])
		{
			params->options[tmp] = argv[*i][i2];
			i2++;
			tmp++;
		}
		(*i)++;
		i2 = 1;
	}
	params->options[tmp] = '\0';
	return (params);
}

static t_params	*put_params(int argc, char **argv, t_params *params)
{
	int			i;
	int			i2;
	int			tmp;

	i = 1;
	i2 = 1;
	tmp = 0;
	if (argc > 1)
		params = pp_aux(&i, argc, argv, params);
	argv = sort_argvs(argc, argv, params);
	ft_check_path(argc, argv);
	params = (argc > 1) ? put_all_params(argc, argv, params, i) : params;
	params->multi = (!(params->files)) ? 0 : params->multi;
	params->files = (!(params->files)) ? current_dir() : params->files;
	return (params);
}

t_params		*ft_parser(int argc, char **argv)
{
	t_params	*params;

	params = NULL;
	if (!(params = (t_params *)malloc(sizeof(t_params))))
		exit(EXIT_FAILURE);
	params->files = NULL;
	params->multi = 0;
	params->first = 0;
	params->options[0] = '\0';
	if (ft_flags_checker(argc, argv))
		params = put_params(argc, argv, params);
	close_tab(argv);
	return (params);
}
