/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvromman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 11:32:34 by hvromman          #+#    #+#             */
/*   Updated: 2018/10/19 11:32:38 by hvromman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		max_of_tab(char *tab)
{
	int count;
	int max;

	count = 2;
	max = tab[0];
	while (count < 8)
	{
		max = ft_max(max, tab[count]);
		count += 2;
	}
	return (max);
}

int		verif_one(char *str, int (*ok)[8], int next)
{
	int		sub_x;
	int		sub_y;
	int		count;

	count = 0;
	while (++count < 4)
		if (!(*ok)[(next + count) % 4])
		{
			sub_x = str[2 * next] - str[2 * (next + count) % 8];
			sub_y = str[2 * next + 1] - str[2 * (next + count) % 8 + 1];
			sub_x = sub_x > 0 ? sub_x : -sub_x;
			sub_y = sub_y > 0 ? sub_y : -sub_y;
			if (sub_x < 2 && sub_y < 2 && sub_x - sub_y)
				(*ok)[(next + count) % 4] = 1;
		}
	count = 0;
	while (++count < 4)
	{
		if ((*ok)[count] && !(*ok)[count + 4])
		{
			(*ok)[count + 4] = 1;
			return (count);
		}
	}
	return (-1);
}

int		verif_tab(char **tab)
{
	int		ok[8];
	int		next;
	int		count;

	while (*tab)
	{
		count = -1;
		while (++count < 8)
			ok[count] = (count % 4 < 1) ? 1 : 0;
		count = 0;
		next = 0;
		while (count < 3 && (next = verif_one(*tab, &ok, next)) > -1)
			count++;
		if (next == -1)
			break ;
		tab++;
	}
	if (!ok[0] || !ok[1] || !ok[2] || !ok[3])
		return (0);
	return (1);
}

int		reduce_one(char *str)
{
	int		check;

	check = 0;
	while (check < 7 && str[check])
		check += 2;
	if (check == 8)
	{
		check = 0;
		while (check < 7)
		{
			str[check]--;
			check += 2;
		}
		return (1);
	}
	return (0);
}

int		reduce_tab(char ***tab)
{
	int		count;
	char	*tmp;

	count = 0;
	while ((*tab)[count])
		if (reduce_one(&(*tab)[count][0]))
			continue ;
		else if (reduce_one(&(*tab)[count][1]))
			continue ;
		else
			count++;
	count = -1;
	while ((*tab)[++count])
	{
		tmp = (*tab)[count];
		if (!((*tab)[count] = ft_strnew(11))
			&& ((*tab)[count] = tmp))
			return (0);
		ft_memcpy((*tab)[count], tmp, 8);
		(*tab)[count][8] = max_of_tab((*tab)[count]);
		(*tab)[count][9] = max_of_tab((*tab)[count] + 1);
		(*tab)[count][10] = 'A' + count;
		free(tmp);
	}
	return (1);
}
