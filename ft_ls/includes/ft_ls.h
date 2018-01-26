/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 17:11:02 by fherbine          #+#    #+#             */
/*   Updated: 2018/01/26 16:31:48 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <sys/xattr.h>
# include <time.h>
# define DEBUG 1

typedef struct			s_rfile
{
	char				*name;
	char				*path;
	struct s_rfile		*next;
}						t_rfile;

typedef struct 			s_path
{
	char 				*name;
	struct s_path		*next;
}						t_path;

typedef struct			s_params
{
	char				options[5];
	t_path				*files;
	int					max_u;
	int					max_g;
	int					max_l;
	int					max_s;
}						t_params;

void					ft_not_found(char *elem);
void					ft_illegal_optn(char i_optn);
void					ft_check_path(int argc, char **argv);

t_params				*ft_parser(int argc, char **argv);

t_path					*ft_add_path(char *new_content, t_path *current);
t_path					*ft_add_path_rev(char *new_content, t_path *current);
t_path					*current_dir();

int						lf_total(char options[5], char *file, long long ret);
char					*lf_date(time_t date_to_add);

char					*perms(char *path);


char					**sort_pdir(char **tab, t_params *params, char *path);
char					**new_pdir(char *path);

t_rfile					*new_rfile(char *path, t_params *params);

void					close_tab(char **tab);
char					**sort_argvs(int argc, char **argv, char options[5]);
void					swap_tab(char **s1, char **s2);
#endif
