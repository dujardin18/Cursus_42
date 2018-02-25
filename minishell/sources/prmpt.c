/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prmpt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 16:15:47 by fherbine          #+#    #+#             */
/*   Updated: 2018/02/25 19:06:55 by fherbine         ###   ########.fr       */
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

char		*ms_get_prompt(char **envp)
{
	char	*prmpt;
	char	*n_cwd;
	char	*user;
	char	*git;
	char	buf[1024];

	getcwd(buf, 1024);
	n_cwd = ftsh_get_np(buf);
	n_cwd = add_color_to_elem(n_cwd, GREEN);
	git = (ftsh_cwdgit(buf) == 1) ? ft_strdup("git") : ft_strdup("");
//	git = add_color_to_elem(git, RED); /// err 
	user = ftsh_getuser(envp);
	user = add_color_to_elem(user, YELLOW);
	prmpt = ft_strdup("$ ");
	prmpt = ft_strjoin(prmpt, user);
	prmpt = ft_strjoin(prmpt, " # ");
	prmpt = ft_strjoin(prmpt, n_cwd);
	prmpt = ft_strjoin(prmpt, (ft_strlen(git) == 0) ? "" : " > ");
	prmpt = ft_strjoin(prmpt, git);
	free(n_cwd);
	free(git);
	free(user);
	return (prmpt);
}
