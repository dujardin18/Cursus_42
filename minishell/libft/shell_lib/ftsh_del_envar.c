#include "../libft.h"

static	char	*get_name_aux(char *value)
{
	char		*ret;
	int			i;

	i = 0;
	if (!(ret = (char *)malloc(sizeof(char) * (ft_strlen(value) + 1))))
		exit(EXIT_FAILURE);
	while (value[i] && value[i] != '=')
	{
		ret[i] = value[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	**ftsh_del_envar(t_shvar **first, char *name, char **envp)
{
	t_shvar	*cp;
	char	*tmp;
	int		i;

	cp = *first;
	i = 0;
	while (envp[i])
	{
		tmp = get_name_aux(envp[i]);
		if (ft_strcmp(tmp, name) == 0)
		{
			envp[i][0] = '\0';
			break ;
		}
		free(tmp);
		i++;
	}
	while (cp && ft_strcmp(name, cp->name) != 0)
		cp = cp->next;
	if (cp)
	{
		cp->name[0] = 0;
		cp->value[0] = 0;
	}
	return (envp);
}
