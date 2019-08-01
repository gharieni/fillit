/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvromman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 13:17:52 by hvromman          #+#    #+#             */
/*   Updated: 2018/10/24 13:18:02 by hvromman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		fill_to_fill(char *tab, char ***to_fill, int i[2])
{
	int		count;

	count = -1;
	while (++count < 4)
	{
		if (!(*to_fill)[i[0] + tab[2 * count + 1]][i[1] + tab[2 * count]])
			(*to_fill)[i[0] + tab[2 * count + 1]]
						[i[1] + tab[2 * count]] = tab[10];
		else
			return (0);
	}
	return (1);
}

void	delete_pos(char *tab, char ***to_fill, int i[2])
{
	int		count;

	count = -1;
	while (++count < 4)
	{
		if ((*to_fill)[i[0] + tab[2 * count + 1]][i[1] + tab[2 * count]]
						== tab[10])
			(*to_fill)[i[0] + tab[2 * count + 1]][i[1] + tab[2 * count]] = 0;
	}
}

int		backtracking(char **tab, char ***to_fill, int max)
{
	int i[2];

	if (!*to_fill)
		return (0);
	if (!*tab)
		return (1);
	i[0] = -1;
	while (++i[0] < max - (*tab)[9])
	{
		i[1] = -1;
		while (++i[1] < max - (*tab)[8])
			if (fill_to_fill(*tab, to_fill, i)
				&& backtracking(tab + 1, to_fill, max))
				return (1);
			else
				delete_pos(*tab, to_fill, i);
	}
	return (0);
}
