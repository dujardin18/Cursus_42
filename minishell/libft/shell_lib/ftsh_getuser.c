/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftsh_getuser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 13:52:14 by fherbine          #+#    #+#             */
/*   Updated: 2018/02/27 17:43:41 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char		*ftsh_getuser(char **envp)
{
	char	*tmp;

	tmp = ftsh_search_envar(envp, "USER");
	if (!tmp)
		return (ft_strdup("NULL"));
	return (tmp);
}
