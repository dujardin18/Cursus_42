/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 18:47:32 by fherbine          #+#    #+#             */
/*   Updated: 2018/02/27 20:01:48 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char		**get_ordir(char **envp, t_shvar **shvar)
{
	char	*tmp;
	char	*tst;
	char	buf[1024];

	tst = ftsh_search_envar(envp, "ORDIR");
	tmp = ft_strdup("ORDIR=");
	getcwd(buf, 1024);
	tmp = ft_strjoin(tmp, buf);
	if (!tst)
	{
		envp = ft_add_tab_elem(envp, tmp);
		*shvar = add_shvar_elem(*shvar, tmp);
	}
	free(tmp);
	free(tst);
	return (envp);
}

char		*get_history_path(char **envp)
{
	char	*ret;

	ret = ftsh_search_envar(envp, "ORDIR");
	ret = ft_strjoin(ret, "/.history");
	return (ret);
}
