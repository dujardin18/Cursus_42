/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 15:49:31 by fherbine          #+#    #+#             */
/*   Updated: 2017/11/06 15:56:24 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_factorial(int nb)
{
	if (nb < 0 || nb > 12)
		return (0);
	else
	{
		if (nb == 0 || nb == 1)
			return (1);
		else
		{
			return (ft_recursive_factorial(nb - 1) * nb);
		}
	}
}
