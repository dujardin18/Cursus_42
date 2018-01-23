/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 17:11:02 by fherbine          #+#    #+#             */
/*   Updated: 2018/01/22 20:12:18 by fherbine         ###   ########.fr       */
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

typedef struct 			s_path
{
	char 				*name;
	struct s_path		*next;
}						t_path;

typedef struct			s_params
{
	char				options[5];
	t_path				*files;
	int					long_format;
	int					all_files;

}						t_params;

void					ft_not_found(char *elem);
void					ft_illegal_optn(char i_optn);

t_params				*ft_parser(int argc, char **argv);

t_path					*ft_add_path(char *new_content, t_path *current);
t_path					*ft_add_path_rev(char *new_content, t_path *current);
t_path					*current_dir();

void					lf_total(char options[5], char *file, long long ret);
char					*lf_date(time_t date_to_add);

#endif