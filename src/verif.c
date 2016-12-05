/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 19:39:24 by gmelek            #+#    #+#             */
/*   Updated: 2016/12/05 18:18:30 by gmelek           ###   ########.fr       */
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
	int		k;
	int		l;
	int		m;
	int		n;
	int		nb_term;
	char	nb_lines[BUFF_SIZE + 1];
	int		mat[4][7];

	n = 0;
	m = 0;
	k = 0;
	l = 0;
	nb_term = 1;
	j = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
	{
		ft_putstr("not oppen");
		return (-1);
	}
	//alloocation matrice 5 * 130
//	mat = (int**)malloc(sizeof(int*)*5);
	while (j < 5)
	{
//		mat[j] = (int*)malloc(sizeof(int*)*130);
		j++;
	}
		j = 0;
		mat[0][0] = 0;
		while ((i = read(fd,&nb_lines,1)))
	{
		   printf("%d", mat[m][n]);
			//verifier caractere valide
			if(ft_strcmp(&nb_lines[0], ".") != 0 && ft_strcmp(&nb_lines[0], "#") != 0 && ft_strcmp(&nb_lines[0], "\n") != 0)
			{
				ft_putstr("error");
					return(-1);
			}
			if (ft_strcmp(&nb_lines[0], "#") == 0)
			{
				mat[m][n] = 1;
				k++;
				n++;
			}
			if (ft_strcmp(&nb_lines[0], ".") == 0)
			{
				mat[m][n] = 0;
				n++;
			}
			if (k > 4)
			{
				close(fd);
				return (-1);
			}
			//ft_putstr(nb_lines);
			printf("%d", mat[m][n]);
			j++;
			//compte les retour chariot
			if (ft_strcmp(&nb_lines[0], "\n") == 0)
			{
				nb_term++;
				m++;
				n = 0;
				//verivication 4 caractere pou chaque ligne 
				if (j != 5 && ((nb_term - 1) % 5 != 0) )
					return(-1);
				j = 0;
			}
				
			//verifier retour chariot entre tetriminos
			if(ft_strcmp(&nb_lines[0],"\n") != 0 && nb_term % 5 == 0)
			{
				ft_putstr("error");
				return(-1);
			}
			if (nb_term % 5 == 0)
			{
				if(k == 4)
					{
						k = 0;
						m++;
					}
				else
				{
					close(fd);
					return(-1);
				}
			}
	}
	//compte nombre tetriminos mais je ne sais pas porquoi il devient unitile
	if (nb_term /4 - 1 > 3)
	{
		/*if(!(1  ==  5 - (1 / (nb_term / 4 - 1))))
			{
				ft_putstr("error 1 ");
				return(-1);
			}*/
		close(fd);
		return((nb_term / 4) - 1);
	}
	//compte nombre tetriminos
	if(nb_term > 4 )
	{
		if(!(nb_term   == (nb_term / 4) * 4 + (nb_term / 4)))
		{
			ft_putstr("error ");
			return(-1);
		}
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
