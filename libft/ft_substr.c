/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <jeongwle@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 15:36:22 by jeongwle          #+#    #+#             */
/*   Updated: 2020/10/16 05:03:42 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*res;
	unsigned int	start_len;
	unsigned int	end;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s) || len == 0 ||
			(start_len = ft_strlen((s + start))) == 0)
		return (ft_strdup(""));
	if (start_len < len)
		end = ft_strlen(s) - 1;
	if (start_len >= len)
		end = start + len - 1;
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (start <= end)
	{
		res[i] = s[start];
		start++;
		i++;
	}
	res[i] = 0;
	return (res);
}
