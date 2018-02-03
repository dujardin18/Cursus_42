/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 16:41:50 by fherbine          #+#    #+#             */
/*   Updated: 2018/02/03 16:47:47 by fherbine         ###   ########.fr       */
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
	char *t;

	t = get_grp(buf);
	n = ft_itoa(buf.st_size);
	ret = get_grp(buf);
	ret = make_n_blanks(p->max_g - ft_strlen(t), ret);
	ret = ft_strjoin(ret, "  ");
	ret = make_n_blanks(p->max_s - ft_nlen_10(buf.st_size), ret);
	ret = ft_strjoin(ret, n);
	free(t);
	free(n);
	return (ret);
}

char	*lf_middle(t_params *p, struct stat buf)
{
	char		*ret;
	char		*lnk;
	char		*t;

	ret = ft_strdup("");
	t = get_user(buf);
	ret = make_n_blanks((p->max_l - ft_nlen_10(buf.st_nlink)), ret);
	lnk = ft_itoa(buf.st_nlink);
	ret = ft_strjoin(ret, lnk);
	free(lnk);
	ret = ft_strjoin(ret, " ");
	ret = ft_strjoin(ret, t);
	ret = make_n_blanks(p->max_u - ft_strlen(t), ret);
	free(t);
	return (ret);
}

int		looking_for_max(t_rfile *rfile, int param, t_params *p)
{
	t_rfile *cp;
	int		tmp;
	char	*t;
	int		max;
	struct stat buf;

	cp = rfile;
	tmp = 0;
	max = 0;
	while (cp)
	{
		if ((cp->name[0] == '.' && ft_strchr(p->options, 'a')) || cp->name[0] != '.')
		{
			lstat(cp->path, &buf);
			if (param == 0)
			{
				t = get_user(buf);
				tmp = ft_strlen(t);
				free(t);
			}
			else if (param == 1)
			{
				t = get_grp(buf);
				tmp = ft_strlen(t);
				free(t);
			}
			else if (param == 2)
				tmp = ft_nlen_10(buf.st_nlink);
			else
				tmp = ft_nlen_10(buf.st_size);
			if (tmp > max)
				max = tmp;
		}
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
		params->max_u = looking_for_max(cp, 0, params);
		params->max_g = looking_for_max(cp, 1, params);
		params->max_l = looking_for_max(cp, 2, params);
		params->max_s = looking_for_max(cp, 3, params);
	}
	return (params);
}

void	display_lf_aux(char *path, char *name, t_params *p)
{
	struct stat buf;

	lstat(path, &buf);
	if (name[0] != '.' || ft_strchr(p->options, 'a'))
		display_lf(p, buf, name, path);
}
