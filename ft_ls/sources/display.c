/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 16:41:50 by fherbine          #+#    #+#             */
/*   Updated: 2018/02/08 12:43:40 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static char			*make_nb(int n)
{
	char			*tmp;
	int				i;

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

static char			*make_n_blanks(int n, char *ret)
{
	char			*tmp;

	if (n > 0)
	{
		tmp = make_nb(n);
		ret = ft_strjoin(ret, tmp);
		free(tmp);
	}
	return (ret);
}

char				*lf_middle2(t_params *p, struct stat buf)
{
	char			*ret;
	char			*n;
	char			*t;

	t = get_grp(buf);
	n = ft_itoa(buf.st_size);
	ret = (!ft_strchr(p->options, 'o')) ? get_grp(buf) : ft_strdup("");
	ret = (!ft_strchr(p->options, 'o')) ? make_n_blanks(p->max_g - \
			ft_strlen(t), ret) : ret;
	ret = (!ft_strchr(p->options, 'o')) ? ft_strjoin(ret, "  ") : ret;
	ret = make_n_blanks(p->max_s - ft_nlen_10(buf.st_size), ret);
	ret = ft_strjoin(ret, n);
	free(t);
	free(n);
	return (ret);
}

char				*lf_middle(t_params *p, struct stat buf)
{
	char			*ret;
	char			*lnk;
	char			*t;

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

void				display_lf_aux(char *path, char *name, t_params *p)
{
	struct stat		buf;

	lstat(path, &buf);
	if (name[0] != '.' || (ft_strchr(p->options, 'A') && \
				ft_strcmp(name, ".") && ft_strcmp(name, "..")) || \
			ft_strchr(p->options, 'a') || ft_strchr(p->options, 'f'))
		display_lf(p, buf, name, path);
}
