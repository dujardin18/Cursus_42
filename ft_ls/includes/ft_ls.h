/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 17:11:02 by fherbine          #+#    #+#             */
/*   Updated: 2018/01/25 18:55:15 by fherbine         ###   ########.fr       */
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

void					ft_ls(t_params *params);

int						max_u_g(DIR *dire, char *path, int user_grp);
char					*lf_usr_grp(char *path, t_params *p);
char					*lf_size(off_t size, t_params *p);
#endif
