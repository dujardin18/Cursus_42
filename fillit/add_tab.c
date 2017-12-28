/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_tab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 21:34:55 by fherbine          #+#    #+#             */
/*   Updated: 2017/11/28 16:27:45 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "babab.h"

static char		**ft_new_tab_aux(char *str, char **tab, int i, int i3)
{
	int			i2;

	while (i < 21)
	{
		i2 = 0;
		if (!(tab[i3] = (char *)malloc(sizeof(char) * 5)))
			return (NULL);
		while (str[i] != '\n' && str[i])
		{
			tab[i3][i2] = str[i];
			i++;
			i2++;
		}
		(i != 20) ? tab[i3][i2] = '\0' : i3--;
		i++;
		i3++;
		if (i2 != 4 && i < 21)
			return (NULL);
	}
	if ((str[i - 1] != '\n' && str[i - 1] != '\0') || str[i - 2] != '\n')
		return (NULL);
	tab[i3] = 0;
	return (tab);
}

char			**ft_new_tab(char *str)
{
	size_t		i;
	size_t		i3;
	char		**tab;

	i = 0;
	i3 = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * (ft_nline(str) + 1))))
		return (NULL);
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\0' || i != 4)
		return (NULL);
	i = 0;
	if (!(tab = ft_new_tab_aux(str, tab, i, i3)))
		return (NULL);
	return (tab);
}

t_tt_list		*ft_add_tts(t_tt_list *alst, char **tab, size_t index)
{
	t_tt_list	*new;
	t_tt_list	*tmp;

	if (!(new = (t_tt_list *)malloc(sizeof(t_tt_list))))
		return (NULL);
	new->tetrimino = tab;
	new->i = index;
	new->next = NULL;
	tmp = alst;
	if (tmp)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
	}
	else
		return (new);
	tmp->next = new;
	return (alst);
}
