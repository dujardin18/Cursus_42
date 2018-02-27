/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_history.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 18:06:40 by fherbine          #+#    #+#             */
/*   Updated: 2018/02/27 19:15:00 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int		get_n_cmd(char **envp)
{
	int			fd;
	int			n;
	int			i;
	char		*ln;
	char		*pth;

	i = 1;
	pth = get_history_path(envp);
	fd = open(pth, O_RDONLY);
	n = get_next_line(fd, &ln);
	if (fd >= 0)
	{
		while (n > 0)
		{
			i++;
			free(ln);
			n = get_next_line(fd, &ln);
		}
		close(fd);
	}
	free(pth);
	return (i);
}

static char		*ms_mnb(int n)
{
	int			len;
	int			blks;
	int			i;
	char		*ret;

	i = 0;
	len = ft_nlen_10(n);
	blks = 5 - len;
	if (blks <= 0)
		return (ft_strdup(""));
	if (!(ret = (char *)malloc(sizeof(char) * (blks + 1))))
		exit(EXIT_FAILURE);
	while (i < blks)
	{
		ret[i] = ' ';
		i++;
	}
	ret[i] = 0;
	return (ret);
}

static void		add_hist(char *cmd, char **envp)
{
	int			n;
	char		*nb;
	char		*prev;
	int			fd;
	char		*pth;

	pth = get_history_path(envp);
	n = get_n_cmd(envp);
	prev = ms_mnb(n);
	nb = ft_itoa(n);
	prev = ft_strjoin(prev, nb);
	free(nb);
	prev = ft_strjoin(prev, "  ");
	prev = ft_strjoin(prev, cmd);
	fd = open(pth, O_WRONLY | O_APPEND);
	if (fd >= 0)
	{
		ft_prints_fd(fd, "%s\n", prev);
		close(fd);
	}
	free(prev);
	free(pth);
}

void			add_hist_raw(t_commands *cmds, char **envp)
{
	t_commands	*cp;

	cp = cmds;
	while (cp)
	{
		add_hist(cp->cmd, envp);
		cp = cp->next;
	}
}

void			bi_history(char **envp)
{
	int			fd;
	int			n;
	char		*ln;
	char		*pth;

	pth = get_history_path(envp);
	fd = open(pth, O_RDONLY);
	n = get_next_line(fd, &ln);
	if (fd > -1)
	{
		while (n > 0)
		{
			ft_prints("%s\n", ln);
			free(ln);
			n = get_next_line(fd, &ln);
		}
		close(fd);
	}
	else
		exit(EXIT_FAILURE);
	free(pth);
}
