/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_aux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 15:13:45 by fherbine          #+#    #+#             */
/*   Updated: 2018/02/02 16:09:09 by fherbine         ###   ########.fr       */
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
		else
			return (ft_strdup(name));
		xname = ft_strdup(tmp);
		free(tmp);
		xname = ft_strjoin(xname, name);
		xname = ft_strjoin(xname, DEFAULT);
		return (xname);
	}
	return (ft_strdup(name));
}

void	display_lf(t_params *p, struct stat buf, char *name, char *perms)
{
	char *date;
	char *middle;
	char *middle_2;
	char *xname;

	xname = NULL;
	xname = get_color(name, p, buf);
	if (ft_strchr(p->options, 'l'))
	{
		date = lf_date(buf);
		middle = lf_middle(p, buf);
		middle_2 = lf_middle2(p, buf);
		ft_prints("%s %s  %s %s %s\n", perms, middle, middle_2, date, xname);
		free(date);
		free(middle);
		free(middle_2);
	}
	else
		ft_putendl(xname);
}
