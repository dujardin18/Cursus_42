/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_aux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 15:13:45 by fherbine          #+#    #+#             */
/*   Updated: 2018/02/03 15:53:44 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char	*get_color(char *name, t_params *p, struct stat buf)
{
	char *tmp;
	char *xname;

	if (ft_strchr(p->options, 'G'))
	{
		if ((buf.st_mode & S_IFMT) == S_IFREG)
			tmp = ft_strdup(YELLOW);
		else if ((buf.st_mode & S_IFMT) == S_IFDIR)
			tmp = ft_strdup(GREEN);
		else if ((buf.st_mode & S_IFMT) == S_IFLNK)
			tmp = ft_strdup(CYAN);
		else
			tmp = ft_strdup(UNDEF);
		xname = ft_strdup(tmp);
		free(tmp);
		xname = ft_strjoin(xname, name);
		xname = ft_strjoin(xname, DEFAULT);
		return (xname);
	}
	return (ft_strdup(name));
}

char	*get_lnk(char *xname, struct stat buf, char *path, t_params *p)
{
	char *buf_str;
	int r;

	if (ft_strchr(p->options, 'l'))
	{
		buf_str = NULL;
		if (!(buf_str = malloc(buf.st_size + 1)))
			exit(EXIT_FAILURE);
		r = readlink(path, buf_str, buf.st_size + 1);
		if (r <= buf.st_size && r > 0)
		{
			buf_str[buf.st_size] = '\0';
			xname = ft_strjoin(xname, " -> ");
			xname = ft_strjoin(xname, buf_str);
		}
		free(buf_str);
	}
	return (xname);
}

void	display_lf(t_params *p, struct stat buf, char *name, char *path)
{
	char *date;
	char *middle;
	char *middle_2;
	char *xname;
	char *perms;

	xname = NULL;
	xname = get_color(name, p, buf);
	xname = get_lnk(xname, buf, path, p);
	if (ft_strchr(p->options, 'l'))
	{
		date = lf_date(buf);
		middle = lf_middle(p, buf);
		middle_2 = lf_middle2(p, buf);
		perms = lf_perms(path, buf);
		ft_prints("%s %s  %s %s %s\n", perms, middle, middle_2, date, xname);
		free(date);
		free(perms);
		free(middle);
		free(middle_2);
	}
	else
		ft_putendl(xname);
	free(xname);
}
