/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 15:36:07 by fherbine          #+#    #+#             */
/*   Updated: 2017/11/06 15:47:18 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int n;
	int res;

	n = 1;
	res = 1;
	if (nb < 0 || nb > 12)
		return (0);
	else
	{
		if (nb == 0)
			return (1);
		else
		{
			while (n <= nb)
			{
				res *= n;
				n++;
			}
			return (res);
		}
	}
}
