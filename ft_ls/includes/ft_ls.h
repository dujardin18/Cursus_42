/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 17:11:02 by fherbine          #+#    #+#             */
/*   Updated: 2018/01/17 19:41:03 by fherbine         ###   ########.fr       */
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

typedef struct 			s_path
{
	char 				*name;
	struct s_pfiles		*next;
}						t_path;

typedef struct			s_params
{
	char				options[5];
	t_path				*files;
}						t_params;

void					ft_not_found(char *elem);
void					ft_illegal_optn(char i_optn);

t_params				*ft_parser(int argc, char **argv);
#endif
