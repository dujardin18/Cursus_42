/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 16:41:50 by fherbine          #+#    #+#             */
/*   Updated: 2018/01/26 17:26:45 by fherbine         ###   ########.fr       */
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

static char	*middle(t_params p, char *path)
{
	struct stat	buf;
	char		*ret;

	ret = ft_strdup("");
	lstat(path, &buf);
	make_n_blanks((p->max_l - ft_nlen_10(buf.st_nlink)), ret);
	ret = ft_strjoin(ret, ft_itoa(buf.st_nlink));
	ret = ft_strjoin(ret, " ");
	ret = ft_strjoin(ret, getpwuid(buf.st_uid)->pw_name);
	make_n_blanks(p->max_u - ft_strlen(getpwuid(buf.st_uid)->pw_name), ret);
	ft_strjoin(ret, getgrgid(buf.st_gid)->gr_name);
	make_n_blanks(p->max_g - ft_strlen(getgrgid(buf.st_gid)->gr_name), ret);
	make_n_blanks(p->max_s - ft_nlen_10(buf.st_size), ret);
	ret = ft_strjoin(ret, ft_itoa(buf.st_size));
	return (ret);
}

void	display_lf_aux(char *path, char *name, char options[5])
{
	char 	*date;
	char	*perms;
	char	*middle;

	if (ft_strchr(options, 'l'))
	{
		date = ;
		perms = perms(path);
		middle = lf_middle(params, path);
	}
	if (ft_strchr(options, 'l') && (name[0] != '.' || ft_strchr(options, 'a')))
		ft_prints("%s %s %s %s\n", perms, middle, date, name);
	else if (name[0] != '.' || ft_strchr(options, 'a'))
		ft_putendl(name);
	if (ft_strchr(options, 'l'))
	{
		free(date);
		free(perms);
		free(middle);
	}
}
