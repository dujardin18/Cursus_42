/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 16:30:45 by fherbine          #+#    #+#             */
/*   Updated: 2018/02/22 19:40:48 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# define MINISHELL_H

# include "../libft/libft.h"
# include <sys/wait.h>
# include <signal.h>

# define DEBUG 0

# define DEFAULT "\033[0m"
# define RED "\033[0;31;40m"
# define GREEN "\033[0;32;40m"
# define YELLOW "\033[0;33;40m"
# define BLUE "\033[0;34;40m"
# define MAGENTA "\033[0;35;40m"
# define CYAN "\033[0;36;40m"
# define WHITE "\033[0;37;40m"

typedef struct	s_cm
{
	char		*cmd;
	int			argc;
	char		**argv;
	struct s_cm	*next;
}				t_commands;

typedef struct	s_shvar
{
	char		*name;
	char		*value;
	struct s_shvar	*next;
}				t_shvar;

void			ftsh_debug_t_cmd(t_commands *c, char *msg);

t_commands		*cmd_add_elem(t_commands *first, char *cmd);
size_t			cmd_add_cmd(char *all_cmd, t_commands **first);

t_commands		*get_all_cmds(char *all_cmd);
t_commands		*cmd_getargs(t_commands *elem);

t_commands		*parse_cmds(char *line);

void			free_cmds(t_commands *cmds);

void			ms_too_much_params(int argc, char **argv);

char			*ms_get_prompt(char **envp);

void			prompt_get_cmd_line(char **envp, t_shvar *shvar);

int				cmd_is_builtin(char *cmd);
void			launch_builtin(int argc, char **argv, char **envp, t_shvar *shvar);
void			launch_other(t_envlist *paths, char **argv, char **envp);
t_envlist		*new_envpath(char **envp);
int				bin_path(char *name, t_envlist *path);

void			command_unknown(char *unknown);

void			bi_env(char **envp);

void			bi_exit(void);

int				ms_isvar(char *cmd);
void			exec_or_var(char **argv, char **envp, t_shvar *shvar);

char			*get_var_name(char *cmd);
char			*get_var_val(char *cmd);
t_shvar			*add_shvar_elem(t_shvar *first, char *cmd);
void			free_shvar(t_shvar *shv_lst);
#endif
