/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 02:38:26 by jeongwle          #+#    #+#             */
/*   Updated: 2020/10/06 04:46:29 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_temp;
	int				i;

	s_temp = (unsigned char *)s;
	i = 0;
	while (n--)
	{
		if (s_temp[i] == (unsigned char)c)
			return (&s_temp[i]);
		i++;
	}
	return (NULL);
}
