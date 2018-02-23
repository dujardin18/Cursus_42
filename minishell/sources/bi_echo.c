#include "../includes/minishell.h"

int		fake_var(char *arg, t_shvar *shvar)
{
	t_shvar	*cp;

	cp = shvar;
	if (arg[0] != '$' || !arg[1])
		return (0);
	while (cp)
	{
		if (ft_strcmp((&arg[1]), cp->name) == 0)
			return (0);
		cp = cp->next;
	}
	return (1);
}

char	*looking_for_val(char *word, t_shvar *shvar)
{
	t_shvar	*cp;
	char	*tmp;

	cp = shvar;
	tmp = ft_strdup(&(word[1]));
	while (cp)
	{
		if (ft_strcmp(tmp, cp->name) == 0)
		{
			free(tmp);
			return (ft_strdup(cp->value));
		}
		cp = cp->next;
	}
	free(tmp);
	return (ft_strdup(""));
}

void	print_var(char *word, t_shvar *shvar, int sp)
{
	char	*tmp;

	if (word[0] != '$' || !word[1])
		tmp = ft_strdup(word);
	else
		tmp = looking_for_val(word, shvar);
	ft_prints("%c%s", (sp == 1) ? ' ' : 0, tmp);
	free(tmp);
}

void	bi_echo(char **argv, t_shvar *shvar)
{
	int	i;
	int nl;
	int	sp;

	i = 1;
	nl = 1;
	sp = 0;
	while (argv[i] && fake_var(argv[i], shvar))
		i++;
	if (argv[i] && ft_strcmp(argv[i], "-n") == 0)
	{
		nl = 0;
		if (!argv[i + 1])
			return ;
	}
	i += (!nl) ? 1 : 0;
	while (argv[i])
	{
		print_var(argv[i], shvar, sp);
		sp = 1;
		i++;
	}
	ft_prints("%s", (nl == 1) ? "\n": "\033[7mX\033[0m\n");
}
