/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:33:07 by fherbine          #+#    #+#             */
/*   Updated: 2018/02/06 17:25:27 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void			ft_not_found(char *elem)
{
	ft_prints_fd(2, "./ft_ls: %s: No such file or directory\n", elem);
}

static char		*get_name_from_path(char *path, char *name)
{
	int			last;
	int			first;
	int			i;

	i = 0;
	last = ft_strlen(path) - 1;
	first = last;
	while (path[first] != '/' && first > 0)
		first--;
	if (!(name = (char *)malloc(sizeof(char) * (last - first + 1))))
		exit(EXIT_FAILURE);
	first += (path[first] == '/') ? 1 : 0;
	while (first <= last)
	{
		name[i] = path[first];
		i++;
		first++;
	}
	name[i] = '\0';
	return (name);
}

void			ft_permission_denied(char *path)
{
	struct stat	buf;
	char		*name;

	name = NULL;
	if (lstat(path, &buf) == 0)
	{
		if ((buf.st_mode & S_IFMT) == S_IFDIR)
		{
			name = get_name_from_path(path, name);
			ft_prints_fd(2, "./ft_ls: %s: Permission denied\n", name);
			free(name);
		}
	}
}

void			ft_check_path(int argc, char **argv)
{
	int			i;
	DIR			*dire;
	struct stat	buf;

	i = 1;
	while (argv[i] && argv[i][0] == '-' && argv[i][1] && \
			ft_strchr("-alrRot1Gp", argv[i][1]))
		i++;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "") == 0)
			ft_not_found("fts_open");
		if (ft_strcmp(argv[i], "") == 0)
			exit(EXIT_FAILURE);
		if ((dire = opendir(argv[i])))
			closedir(dire);
		else
		{
			if (lstat(argv[i], &buf) == -1)
				argv[i] = nf_free(argv[i]);
		}
		i++;
	}
}

void			ft_illegal_optn(char i_optn)
{
	ft_prints_fd(2, "./ft_ls: illegal option -- %c\n", i_optn);
	ft_prints_fd(2, "usage: ft_ls [-GRaloprt1] [file ...]\n");
	exit(EXIT_FAILURE);
}
