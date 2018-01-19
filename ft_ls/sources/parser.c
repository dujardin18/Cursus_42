/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 17:13:14 by fherbine          #+#    #+#             */
/*   Updated: 2018/01/19 17:34:36 by fherbine         ###   ########.fr       */
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

static t_path	*ft_add_path(char *new_content, t_path *current)
{
	t_path		*tmp;
	t_path		*new;

	if (current)
	{
		tmp = current;
		while (tmp->next)
			tmp = tmp->next;
		if (!(new = (t_path *)malloc(sizeof(t_path))))
			exit(EXIT_FAILURE);
		new->name = ft_strdup(new_content);
		new->next = NULL;
		tmp->next = new;
	}
	else
	{
		if (!(new = (t_path *)malloc(sizeof(t_path))))
			exit(EXIT_FAILURE);
		new->name = ft_strdup(new_content);
		new->next = NULL;
		current = new;
	}
	//free new ?
	return (current);
}

static t_path	*current_dir()
{
	t_path		*ret;

	if (!(ret = (t_path *)malloc(sizeof(t_path))))
		exit(EXIT_FAILURE);
	if (!(ret->name = ft_strdup(".")))
		exit(EXIT_FAILURE);
	ret->next = NULL;
	return (ret);
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
		while (i < argc)
		{
			params->files = ft_add_path(argv[i], params->files);
			i++;
		}
	}
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
	return (params);
}
