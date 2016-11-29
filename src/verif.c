/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 19:39:24 by gmelek            #+#    #+#             */
/*   Updated: 2016/11/29 20:04:05 by gmelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include"../includes/libft.h"

int		get_nb_term(int fd, char *file)
{
	int		i;
	int		j;
	int		nb_term;
	char	nb_lines[BUFF_SIZE + 1];

	nb_term = 1;
	j = 1;
	if ((fd = open(file, O_RDONLY)) == -1)
	{
		ft_putstr("not oppen");
		return (-1);
	}
	while ((i = read(fd,&nb_lines,1)))
	{
			//verifier caractere valide
			if(ft_strcmp(&nb_lines[0], ".") != 0 && ft_strcmp(&nb_lines[0], "#") != 0 && ft_strcmp(&nb_lines[0], "\n") != 0)
			{
				ft_putstr("error");
					return(-1);
			}
			ft_putstr(nb_lines);
			if (ft_strcmp(&nb_lines[0], "\n") == 0)
			{
				j++;
				nb_term++;
			}
			//verifier retour chqriot entre tetriminos
			if(ft_strcmp(&nb_lines[0],"\n") != 0 && j % 5 == 0)
			{
				return(-1);
			}
	}
	//compte nombre tetriminos
	if (nb_term /4 - 1 > 3)
	{
		close(fd);
		return((nb_term / 4) - 1);
	}
	if(nb_term > 1 )
	{
		close(fd);
		return(nb_term / 4);
	}
		close(fd);
	return (-1);
}

int		main(int argc, char **argv)
{
	int fd;

	fd = 0;
	if (argc == 2)
	{
		printf("%d", get_nb_term(fd,argv[1]));
	}
	else 
	{
		ft_putstr("usage: cp [-R [-H | -L | -P]] [-fi | -n] [-apvX] source_file target_file \n");
		ft_putstr("       cp [-R [-H | -L | -P]] [-fi | -n] [-apvX] source_file ... target_directory");
	}
	return (0);
}
