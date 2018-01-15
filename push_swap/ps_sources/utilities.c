/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 11:20:13 by fherbine          #+#    #+#             */
/*   Updated: 2018/01/10 13:53:25 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ch_includes/checker.h"

void	ft_kill(int param)
{
	if (param == EXIT_SUCCESS)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 2);
	exit(param);
}

void	ft_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}

t_pile	*ft_malloc_secure(t_pile *to_alloc)
{
	if (!(to_alloc = (t_pile *)malloc(sizeof(t_pile))))
		ft_kill(EXIT_FAILURE);
	return (to_alloc);
}
