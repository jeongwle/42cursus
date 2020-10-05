/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 03:35:24 by jeongwle          #+#    #+#             */
/*   Updated: 2020/10/06 04:43:28 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_temp;
	unsigned char	*s2_temp;
	int				i;

	s1_temp = (unsigned char *)s1;
	s2_temp = (unsigned char *)s2;
	i = 0;
	if ((!s1 && !s2) || n == 0)
		return (0);
	while (n--)
	{
		if (s1_temp[i] != s2_temp[i])
			return ((unsigned char)s1_temp[i] - (unsigned char)s2_temp[i]);
		i++;
	}
	return (0);
}
