/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 02:19:31 by jeongwle          #+#    #+#             */
/*   Updated: 2020/10/07 02:20:42 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_temp;
	unsigned char	*src_temp;
	int				i;

	if (!dst && !src)
		return (NULL);
	dst_temp = (unsigned char *)dst;
	src_temp = (unsigned char *)src;
	i = 0;
	if (dst <= src)
	{
		while (len--)
		{
			dst_temp[i] = src_temp[i];
			i++;
		}
	}
	else
	{
		while (len--)
			dst_temp[len] = src_temp[len];
	}
	return (dst);
}
