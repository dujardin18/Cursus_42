/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 16:41:50 by fherbine          #+#    #+#             */
/*   Updated: 2018/02/01 17:26:35 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static char	*make_nb(int n)
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
	return (tmp);
}

static char	*make_n_blanks(int n, char *ret)
{
	char *tmp;

	if (n > 0)
	{
	tmp = make_nb(n);
		ret = ft_strjoin(ret, tmp);
		free(tmp);
	}
	return (ret);
}

char *lf_middle2(t_params *p, struct stat buf)
{
	char *ret;
	char *n;

	n = ft_itoa(buf.st_size);
	ret = ft_strdup(getgrgid(buf.st_gid)->gr_name);
	ret = make_n_blanks(p->max_g - ft_strlen(getgrgid(buf.st_gid)->gr_name), ret);
	ret = ft_strjoin(ret, "  ");
	ret = make_n_blanks(p->max_s - ft_nlen_10(buf.st_size), ret);
	ret = ft_strjoin(ret, n);
	free(n);
	return (ret);
}

static char	*lf_middle(t_params *p, char *path)
{
	struct stat	buf;
	char		*ret;
	char		*grp;

	ret = ft_strdup("");
	lstat(path, &buf);
	ret = make_n_blanks((p->max_l - ft_nlen_10(buf.st_nlink)), ret);
	ret = ft_strjoin(ret, ft_itoa(buf.st_nlink));
	ret = ft_strjoin(ret, " ");
	ret = ft_strjoin(ret, getpwuid(buf.st_uid)->pw_name);
	ret = make_n_blanks(p->max_u - ft_strlen(getpwuid(buf.st_uid)->pw_name), ret);
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
	t_rfile *cp;

	cp = rfile;
		params->max_u = 0;
		params->max_g = 0;
		params->max_l = 0;
		params->max_s = 0;
	if (ft_strchr(params->options, 'l'))
	{
		params->max_u = looking_for_max(cp, 0);
		params->max_g = looking_for_max(cp, 1);
		params->max_l = looking_for_max(cp, 2);
		params->max_s = looking_for_max(cp, 3);
	}
	return (params);
}

void	display_lf_aux(char *path, char *name, t_params *p)
{
	char 	*date;
	char	*perms;
	char	*middle;
	char	*middle_2;
	struct stat buf;

	if (ft_strchr(p->options, 'l'))
	{
		lstat(path, &buf);
		date = lf_date(buf);
		perms = lf_perms(path, buf);
		middle = lf_middle(p, path);
		middle_2 = lf_middle2(p, buf);
	}
	if (ft_strchr(p->options, 'l') && (name[0] != '.' || ft_strchr(p->options, 'a')))
		ft_prints("%s %s  %s %s %s\n", perms, middle, middle_2, date, name);
	else if (name[0] != '.' || ft_strchr(p->options, 'a'))
		ft_putendl(name);
	if (ft_strchr(p->options, 'l'))
	{
		free(date);
		free(perms);
		free(middle);
		free(middle_2);
	}
}
