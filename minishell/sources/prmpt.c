/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prmpt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 16:15:47 by fherbine          #+#    #+#             */
/*   Updated: 2018/02/27 17:43:43 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*add_color_to_elem(char *elem, char *color)
{
	char	*cp;

	cp = ft_strdup(color);
	cp = ft_strjoin(cp, elem);
	cp = ft_strjoin(cp, DEFAULT);
	free(elem);
	return (cp);
}

static char	*get_shl(char **envp)
{
	char	*shl;
	char	*tmp;

	tmp = ft_strdup("[");
	shl = ftsh_search_envar(envp, "SHLVL");
	tmp = ft_strjoin(tmp, shl);
	tmp = ft_strjoin(tmp, "]");
	free(shl);
	tmp = add_color_to_elem(tmp, B_CYAN);
	return (tmp);
}

static char	*get_dir_name(char buf[1024], char **envp)
{
	char	*home_d;
	char	*n_cwd;

	n_cwd = (ft_strcmp(buf, SLSH_D) == 0) ? ft_strdup("/") : ftsh_get_np(buf);
	home_d = ftsh_search_envar(envp, "HOME");
	if (ft_strcmp(buf, home_d) == 0)
	{
		free(n_cwd);
		n_cwd = ft_strdup("~");
	}
	free(home_d);
	return (n_cwd);
}

char		*ms_get_prompt(char **envp)
{
	char	*prmpt;
	char	*n_cwd;
	char	*user;
	char	*shl;
	char	buf[1024];

	getcwd(buf, 1024);
	shl = get_shl(envp);
	n_cwd = get_dir_name(buf, envp);
	n_cwd = add_color_to_elem(n_cwd, GREEN);
	user = ftsh_getuser(envp);
	user = add_color_to_elem(user, YELLOW);
	prmpt = ft_strdup("$ ");
	prmpt = ft_strjoin(prmpt, user);
	prmpt = ft_strjoin(prmpt, " # ");
	prmpt = ft_strjoin(prmpt, n_cwd);
	prmpt = ft_strjoin(prmpt, " ");
	prmpt = ft_strjoin(prmpt, shl);
	free(n_cwd);
	free(shl);
	free(user);
	return (prmpt);
}
