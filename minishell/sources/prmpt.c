/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prmpt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 16:15:47 by fherbine          #+#    #+#             */
/*   Updated: 2018/02/15 20:35:40 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char		*ms_get_prompt(char **envp)
{
	char	*prmpt;
	char	*n_cwd;
	char	*user;
	char	*git;
	char	buf[1024];

	getcwd(buf, 1024);
	n_cwd = ftsh_get_np(buf);
	git = (ftsh_cwdgit(buf) == 1) ? ft_strdup("git") : ft_strdup("");
	user = ftsh_getuser(envp);
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
