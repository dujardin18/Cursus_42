/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 16:41:50 by fherbine          #+#    #+#             */
/*   Updated: 2018/01/29 16:48:54 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void		make_n_blanks(int n, char **line)
{
	char *tmp;
	int i;

	i = 0;
	if (!(tmp = (char *)malloc(sizeof(char) * (n + 1))))
		exit(EXIT_FAILURE);
	while (i < n)
	{
		tmp[i] = ' ';
		i++;
	}
	tmp[i] = '\0';
	*line = ft_strjoin(*line, tmp);
	free(tmp);
}

static char	*lf_middle(t_params *p, char *path)
{
	struct stat	buf;
	char		*ret;

	ret = ft_strdup("");
	lstat(path, &buf);
	make_n_blanks((p->max_l - ft_nlen_10(buf.st_nlink)), &ret);
	ret = ft_strjoin(ret, ft_itoa(buf.st_nlink));
	ret = ft_strjoin(ret, " ");
	ret = ft_strjoin(ret, getpwuid(buf.st_uid)->pw_name);
	make_n_blanks(p->max_u - ft_strlen(getpwuid(buf.st_uid)->pw_name), &ret);
	ft_strjoin(ret, getgrgid(buf.st_gid)->gr_name);
	make_n_blanks(p->max_g - ft_strlen(getgrgid(buf.st_gid)->gr_name), &ret);
	make_n_blanks(p->max_s - ft_nlen_10(buf.st_size), &ret);
	ret = ft_strjoin(ret, ft_itoa(buf.st_size));
	return (ret);
}

int		looking_for_max(t_rfile *rfile, int param)
{
	t_rfile *cp;
	int		tmp;
	int		max;
	struct stat buf;

	cp = rfile;
	tmp = 0;
	max = 0;
	while (cp)
	{
		lstat(cp->path, &buf);
		if (param == 0)
			tmp = ft_strlen(getpwuid(buf.st_uid)->pw_name);
		else if (param == 1)
			tmp = ft_strlen(getgrgid(buf.st_gid)->gr_name);
		else if (param == 2)
			tmp = ft_nlen_10(buf.st_nlink);
		else
			tmp = ft_nlen_10(buf.st_size);
		if (tmp > max)
			max = tmp;
		cp = cp->next;
	}
	return (max);
}

t_params *max_disp(t_params *params, t_rfile *rfile)
{
		params->max_u = 0;
		params->max_g = 0;
		params->max_l = 0;
		params->max_s = 0;
	if (ft_strchr(params->options, 'l'))
	{
		params->max_u = looking_for_max(rfile, 0);
		params->max_g = looking_for_max(rfile, 1);
		params->max_l = looking_for_max(rfile, 2);
		params->max_s = looking_for_max(rfile, 3);
	}
	return (params);
}

void	display_lf_aux(char *path, char *name, t_params *p)
{
	char 	*date;
	char	*perms;
	char	*middle;
	struct stat buf;

	lstat(path, &buf);
	if (ft_strchr(p->options, 'l'))
	{
		date = lf_date(buf);
		perms = lf_perms(path);
		middle = lf_middle(p, path);
	}
	if (ft_strchr(p->options, 'l') && (name[0] != '.' || ft_strchr(p->options, 'a')))
		ft_prints("%s %s %s %s\n", perms, middle, date, name);
	else if (name[0] != '.' || ft_strchr(p->options, 'a'))
		ft_putendl(name);
	if (ft_strchr(p->options, 'l'))
	{
		free(date);
		free(perms);
		free(middle);
	}
}
