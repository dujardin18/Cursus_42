/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 16:30:45 by fherbine          #+#    #+#             */
/*   Updated: 2018/02/13 19:58:48 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# define MINISHELL_H

# include "../libft/libft.h"
# include <sys/wait.h>

# define DEBUG 0

typedef struct	s_cm
{
	char		*cmd;
	int			argc;
	char		**argv;
	struct s_cm	*next;
}				t_commands;

t_commands		*cmd_add_elem(t_commands *first, char *cmd);
size_t			cmd_add_cmd(char *all_cmd, t_commands *first);

t_commands		*get_all_cmds(char *all_cmd);
t_commands		*cmd_getargs(t_commands *elem);

void			free_cmds(t_commands *cmds);
#endif
