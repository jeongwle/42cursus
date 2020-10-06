/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 04:53:25 by jeongwle          #+#    #+#             */
/*   Updated: 2020/10/06 23:56:11 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*s_temp;
	int				i;

	s_temp = (unsigned char *)s;
	i = 0;
	while (s_temp[i])
	{
		if (s_temp[i] == (unsigned char)c)
			return ((char *)&s_temp[i]);
		i++;
	}
	if (s_temp[i] == (unsigned char)c)
		return ((char *)&s_temp[i]);
	return (NULL);
}
