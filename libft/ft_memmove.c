/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 02:19:31 by jeongwle          #+#    #+#             */
/*   Updated: 2020/10/06 04:14:37 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_temp;
	unsigned char	*src_temp;
	int				i;

	dst_temp = (unsigned char *)dst;
	src_temp = (unsigned char *)src;
	i = 0;
	while (len--)
	{
		dst_temp[i] = src_temp[i];
		i++;
	}
	return (dst);
}
