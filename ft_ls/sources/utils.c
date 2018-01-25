/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 11:18:30 by fherbine          #+#    #+#             */
/*   Updated: 2018/01/25 20:46:20 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		max_u_g(DIR *dire, char *path, int user_grp)
{
	char  *tmpc;
	struct dirent *new;
	struct stat buf;
	int max;
	int tmp;

	new = readdir(dire);
	max = 0;
	while (new)
	{
		tmpc = ft_strdup(path);
		tmpc = ft_strjoin(tmpc, new->d_name);
		lstat(tmpc, &buf);
		if (user_grp == 0)
			tmp = ft_strlen(getpwuid(buf.st_uid)->pw_name);
		else if (user_grp == 1)
			tmp = ft_strlen(getgrgid(buf.st_gid)->gr_name);
		else if (user_grp == 2)
			tmp = ft_strlen(ft_itoa(buf.st_nlink));
		else
			tmp = ft_strlen(ft_itoa(buf.st_size));
		if (tmp > max)
			max = tmp;
		new = readdir(dire);
		free(tmpc);
	}
	return (max);
}

static char	*make_n_spaces(int n)
{
	char *ret;
	int i;

	i = 0;
	if (!(ret = (char *)malloc(sizeof(char) * (n + 1))))
		exit(EXIT_FAILURE);
	while (i < n)
	{
		ret[i] = ' ';
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*lf_usr_grp(char *path, t_params *p)
{
	char *ret;
	struct stat buf;
	char *tmp;

	ret = ft_strdup("");
	lstat(path, &buf);
	if (ft_strlen(ft_itoa(buf.st_nlink)) < (size_t)p->max_l)
		ret = make_n_spaces(p->max_l - ft_strlen(ft_itoa(buf.st_nlink)));
	ret = ft_strjoin(ret, ft_itoa(buf.st_nlink));
	ret = ft_strjoin(ret, " ");
	ret = ft_strjoin(ret, getpwuid(buf.st_uid)->pw_name);
	//if (ft_strlen(getpwuid(buf.st_uid)->pw_name) < (size_t)p->max_u)
	//{
		tmp = make_n_spaces(p->max_u - ft_strlen(getpwuid(buf.st_uid)->pw_name + 1));
		ret = ft_strjoin(ret, tmp);
		free(tmp);
	//}
	ret = ft_strjoin(ret, " ");
	ret = ft_strjoin(ret, getgrgid(buf.st_gid)->gr_name);
//	if (ft_strlen(getgrgid(buf.st_gid)->gr_name) < (size_t)p->max_g)
//	{
		tmp = make_n_spaces(p->max_g - ft_strlen(getgrgid(buf.st_gid)->gr_name));
		ft_prints(":%s:\n", tmp);
		ret = ft_strjoin(ret, tmp);
		free(tmp);
//	}
	//ret = ft_strjoin(ret, " ");
	tmp = lf_size(buf.st_size, p);
	ret = ft_strjoin(ret, tmp);
	free(tmp);
	return (ret);
}

char	*lf_size(off_t size, t_params *p)
{
	char *ret;
	int 	n_b;

	n_b = ft_nlen_10(size);
	n_b = p->max_s - n_b;
//	ft_prints("%d, %d - %d\n", size, p->max_s, n_b);
	ret = make_n_spaces(n_b);
	ret = ft_strjoin(ret, ft_itoa(size));
	ret = ft_strjoin(ret, " ");
	return (ret);
}
