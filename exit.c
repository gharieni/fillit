/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvromman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 13:01:46 by hvromman          #+#    #+#             */
/*   Updated: 2018/10/24 13:02:01 by hvromman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	exit_func(char *str, void **tab, void **to_fill)
{
	if (ft_strcmp(str, "succes"))
		write(1, "error\n", 6);
	ft_free_tab(&tab);
	ft_free_tab(&to_fill);
	exit(0);
}

void	usage(void)
{
	ft_putendl("usage: fillit source_file");
}
