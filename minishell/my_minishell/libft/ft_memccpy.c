/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 01:44:07 by jeongwle          #+#    #+#             */
/*   Updated: 2020/10/06 23:55:47 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dst_temp;
	unsigned char	*src_temp;
	int				i;

	dst_temp = (unsigned char *)dst;
	src_temp = (unsigned char *)src;
	i = 0;
	while (n--)
	{
		dst_temp[i] = src_temp[i];
		if (src_temp[i] == (unsigned char)c)
			return (&dst[i + 1]);
		i++;
	}
	return (NULL);
}
