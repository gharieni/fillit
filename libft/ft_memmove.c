/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvromman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 16:09:13 by hvromman          #+#    #+#             */
/*   Updated: 2018/10/03 16:09:15 by hvromman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memrcpy(void *dst, const void *src, size_t n)
{
	while (n-- > 0)
		*(unsigned char*)&dst[n] = *(unsigned char*)&src[n];
	return (dst);
}

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	if (len > 0)
	{
		if (dst - src < (long)len && dst - src >= 0)
			ft_memrcpy(dst, src, len);
		else
			ft_memcpy(dst, src, len);
	}
	return (dst);
}
