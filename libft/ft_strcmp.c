/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvromman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 15:42:30 by hvromman          #+#    #+#             */
/*   Updated: 2018/10/03 15:42:34 by hvromman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	if (*s1 || *s2)
		return ((*(unsigned char*)s1 - *(unsigned char*)s2) ?
	(*(unsigned char*)s1 - *(unsigned char*)s2) : ft_strcmp(s1 + 1, s2 + 1));
		return (0);
}
