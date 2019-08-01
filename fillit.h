/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvromman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 13:19:44 by hvromman          #+#    #+#             */
/*   Updated: 2018/10/24 13:19:46 by hvromman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"

# define BUFF_SIZE 5

# define EMPTY_CHAR '.'
# define FILLED_CHAR '#'

int		read_all(int fd, char ***tab);
int		fill_tab(char *buf, char *to_fill, int count_line, int cursor);
int		verif_tab(char **tab);
int		reduce_tab(char ***tab);
int		backtracking(char **tab, char ***to_fill, int max);
void	exit_func(char *str, void **tab, void **to_fill);
void	usage();

#endif
