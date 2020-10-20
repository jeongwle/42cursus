/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 05:15:04 by jeongwle          #+#    #+#             */
/*   Updated: 2020/10/18 03:13:43 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*s_temp;
	int				i;

	s_temp = (unsigned char *)s;
	i = 0;
	while (s_temp[i])
		i++;
	while (i >= 0)
	{
		if (s_temp[i] == (unsigned char)c)
			return ((char *)&s_temp[i]);
		i--;
	}
	return (NULL);
}
