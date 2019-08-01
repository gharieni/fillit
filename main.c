/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvromman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 13:14:05 by hvromman          #+#    #+#             */
/*   Updated: 2018/10/24 13:14:07 by hvromman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_tab(char **to_fill, int max)
{
	int		count;
	int		count2;

	count = 0;
	while ((to_fill)[count])
	{
		count2 = 0;
		while (count2 < max)
			if (!to_fill[count][count2++])
				to_fill[count][count2 - 1] = '.';
		ft_putendl((to_fill)[count++]);
	}
}

int		upgrade(char ***to_fill, int count)
{
	int	i;

	ft_free_tab((void***)(to_fill));
	if (!(*to_fill = (char**)malloc(sizeof(char*) * (++count + 1))))
		return (0);
	i = 0;
	while (i < count)
		if (!((*to_fill)[i++] = ft_strnew(count)))
		{
			ft_free_tab((void***)(to_fill));
			return (0);
		}
	(*to_fill)[i] = NULL;
	return (count);
}

char	**new_tab(int count)
{
	char	**tab;
	int		i;

	if (!(tab = (char**)malloc(sizeof(char*) * (count + 1))))
		return (NULL);
	i = 0;
	while (i < count)
		if (!((tab)[i++] = ft_strnew(count)))
		{
			ft_free_tab((void***)(&tab));
			return (0);
		}
	(tab)[i] = NULL;
	return (tab);
}

int		sqrt_of_next_square(int nbr)
{
	int		to_return;

	to_return = 0;
	while (to_return * to_return < nbr)
		to_return++;
	return (to_return);
}

int		main(int ac, char **av)
{
	int		fd;
	char	**tab;
	char	**to_fill;
	int		count;

	tab = NULL;
	to_fill = NULL;
	if (ac != 2)
	{
		usage();
		exit_func("succes", (void**)tab, (void**)to_fill);
	}
	if ((fd = open(av[1], O_RDONLY)) == -1)
		exit_func("open error", (void**)tab, (void**)to_fill);
	else if (!read_all(fd, &tab))
		exit_func("read error", (void**)tab, (void**)to_fill);
	count = sqrt_of_next_square(ft_tablen((void**)tab) * 4);
	to_fill = new_tab(count);
	while (!backtracking(tab, &to_fill, count))
		count = upgrade(&to_fill, count);
	print_tab(to_fill, count);
	exit_func("succes", (void**)tab, (void**)to_fill);
}
