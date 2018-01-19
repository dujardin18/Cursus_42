/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 17:11:02 by fherbine          #+#    #+#             */
/*   Updated: 2018/01/19 19:42:15 by fherbine         ###   ########.fr       */
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

typedef struct			s_ldisplay
{
	char				*elem_to_display;
	char				mode[12];
	int					hard_links;
	char				*user_name;
	char				*group_name;
	int					size;
	char				date[13];
	struct s_ldisplay	*next;
}						t_ldisplay;

typedef struct 			s_path
{
	char 				*name;
	t_ldisplay			*diplay;
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

#endif
