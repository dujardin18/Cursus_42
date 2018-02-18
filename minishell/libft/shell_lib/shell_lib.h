/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_lib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 16:15:52 by fherbine          #+#    #+#             */
/*   Updated: 2018/02/18 16:17:42 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_LIB_H
# define SHELL_LIB_H

typedef struct			s_envlist
{
	char				*value;
	struct s_envlist	*next;
}						t_envlist;

#endif
