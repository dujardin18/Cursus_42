/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 14:23:02 by fherbine          #+#    #+#             */
/*   Updated: 2018/02/27 14:51:18 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*get_path_f_shvar(t_shvar *shvar, char *name)
{
	t_shvar	*cp;

	cp = shvar;
	while (cp)
	{
		if (ft_strcmp(name, cp->name) == 0)
			return (ft_strdup(cp->value));
		cp = cp->next;
	}
	return (NULL);
}

char	**only_repl_pwd(char **envp, t_shvar **shvar, char *name)
{
	char	*tmp;
	char	new_opwd[1024];
	char	*tmp2;

	tmp2 = ft_strdup(name);
	tmp2 = ft_strjoin(tmp2, "=");
	getcwd(new_opwd, 1024);
	tmp = ft_strdup(tmp2);
	tmp = ft_strjoin(tmp, new_opwd);
	envp = ftsh_del_envar(shvar, name, envp);
	envp = ft_add_tab_elem(envp, tmp);
	*shvar = add_shvar_elem(*shvar, tmp);
	free(tmp);
	free(tmp2);
	return (envp);
}

void	no_fod(char *disp)
{
	ft_prints_fd(2, "minishell: cd: %s: No such file or directory\n", disp);
}

void	no_opwd(void)
{
	ft_prints_fd(2, "minishell: cd: OLDPWD not set\n");
}

static char	*get_varp(char **argv, int argc, char **envp, t_shvar **shvar)
{
	char	*var_p;

	var_p = NULL;
	if (argc == 1 || ft_strcmp(argv[1], "~") == 0)
		var_p = ftsh_search_envar(envp, "HOME");
	else if (ft_strcmp(argv[1], "-") == 0)
	{
		if (!(var_p = get_path_f_shvar(*shvar, "OLDPWD")))
			no_opwd();
	}
	else if (argv[1][0] == '$')
		var_p = get_path_f_shvar(*shvar, &(argv[1][1]));
	else
		var_p = ft_strdup(argv[1]);
	return (var_p);
}

char	**bi_cd(t_shvar **shvar, char **argv, char **envp, int argc)
{
	char	*var_p;

	var_p = NULL;
	var_p = get_varp(argv, argc, envp, shvar);
	if (!var_p)
		var_p = ft_strdup(".");
	var_p = ft_append_slash(var_p);
	envp = only_repl_pwd(envp, shvar, "OLDPWD");
	if (chdir(var_p) != 0)
		no_fod(argv[1]);
	envp = only_repl_pwd(envp, shvar, "PWD");
	free(var_p);
	return (envp);
}
