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

char	**only_repl_opwd(char **envp, t_shvar **shvar)
{
	char	*tmp;
	char	new_opwd[1024];

	getcwd(new_opwd, 1024);
	tmp = ft_strdup("OLDPWD=");
	tmp = ft_strjoin(tmp, new_opwd);
	envp = ftsh_del_envar(shvar, "OLDPWD", envp);
	envp = ft_add_tab_elem(envp, tmp);
	*shvar = add_shvar_elem(*shvar, tmp);
	free(tmp);
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

char	**bi_cd(t_shvar **shvar, char **argv, char **envp)
{
	char	*var_p;
	char tmp[1024];

	var_p = NULL;
	if (ft_strcmp(argv[1], "-") == 0)
	{
		if (!(var_p = get_path_f_shvar(*shvar, "OLDPWD")))
			no_opwd();
	}
	else if (argv[1][0] == '$')
		var_p = get_path_f_shvar(*shvar, &(argv[1][1]));
	else
		var_p = ft_strdup(argv[1]);
	if (!var_p)
		var_p = ft_strdup(".");
	var_p = ft_append_slash(var_p);
	envp = only_repl_opwd(envp, shvar);
	if (chdir(var_p) != 0)
		no_fod(argv[1]);
	free(var_p);
	return (envp);
}
