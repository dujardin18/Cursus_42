/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 15:39:45 by fherbine          #+#    #+#             */
/*   Updated: 2018/02/19 15:43:36 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	bi_env(int argc, char **argv, char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		ft_prints("%s\n", envp[i]);
		i++;
	}
}
