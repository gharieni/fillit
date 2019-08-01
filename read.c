/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvromman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 11:27:49 by hvromman          #+#    #+#             */
/*   Updated: 2018/10/19 11:27:51 by hvromman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		fill_tab(char *buf, char *to_fill, int line, int cursor)
{
	char	x;
	char	y;

	y = line % 4;
	x = 0;
	while (buf[(int)x])
	{
		if (x == 4 && buf[(int)x] == '\n')
			return (cursor);
		else if (buf[(int)x] == FILLED_CHAR && cursor < 8)
		{
			to_fill[cursor++] = x;
			to_fill[cursor++] = y;
		}
		else if (buf[(int)x] == FILLED_CHAR || buf[(int)x] != EMPTY_CHAR)
			return (-2);
		x++;
	}
	if (x != 5)
		return (-2);
	return (cursor);
}

int		read_all(int fd, char ***tab)
{
	int		i;
	char	buf[BUFF_SIZE + 1];
	int		line;
	int		ret;
	int		cursor;

	if (!(*tab = (char**)malloc(sizeof(char*) * (26 + 1))))
		return (0);
	i = 0;
	line = 0;
	cursor = 0;
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if (!(line % 4) && (!((*tab)[i++] = (char*)malloc(sizeof(char) * 8))))
			return (0);
		buf[ret] = 0;
		if ((((cursor = fill_tab(buf, (*tab)[i - 1], line, cursor)) == -2)
	|| (!((++line) % 4) && read(fd, buf, 1) && ((cursor = 0) + 1)
	&& buf[0] != '\n')) && (((*tab)[i] = NULL) || 1))
			return (0);
	}
	if ((((*tab)[i] = NULL) || 1) && !cursor || line % 4)
		return (0);
	return (verif_tab(*tab) && reduce_tab(tab) ? 1 : 0);
}
