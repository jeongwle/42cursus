/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 01:05:25 by jeongwle          #+#    #+#             */
/*   Updated: 2020/10/07 00:27:37 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dst_temp;
	unsigned char	*src_temp;
	int				i;

	if (!dst && !src)
		return (NULL);
	dst_temp = (unsigned char *)dst;
	src_temp = (unsigned char *)src;
	i = 0;
	while (n--)
	{
		dst_temp[i] = src_temp[i];
		i++;
	}
	return (dst);
}
