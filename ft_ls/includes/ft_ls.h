/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 17:11:02 by fherbine          #+#    #+#             */
/*   Updated: 2018/02/05 16:47:33 by fherbine         ###   ########.fr       */
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

# define DEBUG 0

# define DEFAULT "\033[0m"
# define YELLOW "\033[0;33;40m"
# define GREEN "\033[0;32;40m"
# define CYAN "\033[0;36;40m"
# define UNDEF "\033[3;30;43m"

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
	char				options[8];
	t_path				*files;
	int					max_u;
	int					max_g;
	int					max_l;
	int					max_s;
	int					multi;
	int					first;
}						t_params;

void					ft_not_found(char *elem);
void					ft_illegal_optn(char i_optn);
void					ft_check_path(int argc, char **argv);
void					ft_permission_denied(char *path);

t_params				*ft_parser(int argc, char **argv);

t_path					*ft_add_path(char *new_content, t_path *current);
t_path					*ft_add_path_rev(char *new_content, t_path *current);
t_path					*current_dir();

int						lf_total(char options[5], char *file, long long ret, int a);
char					*lf_date(struct stat buf);

char					*lf_perms(char *path, struct stat buffer);


char					**sort_pdir(char **tab, t_params *params, char *path);
char					**new_pdir(char *path);

t_rfile					*new_rfile(char *path, t_params *params);

void					close_tab(char **tab);
char					**sort_argvs(int argc, char **argv, t_params *p);
void					swap_tab(char **s1, char **s2);

void					display_lf_aux(char *path, char *name, t_params *p);
char					*lf_middle(t_params *p, struct stat buf);
char					*lf_middle2(t_params *p, struct stat buf);
t_params				*max_disp(t_params *params, t_rfile *rfile);

void					ft_ls(t_params *params);

void					free_rfile(t_rfile *rfile);
void					free_tpath(t_path *tpath);

void					display_lf(t_params *p, struct stat buf,char *name, char *perms);

char					*get_user(struct stat buf);
char					*get_grp(struct stat buf);
#endif
