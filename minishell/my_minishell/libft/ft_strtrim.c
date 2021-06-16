/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 18:14:35 by mki               #+#    #+#             */
/*   Updated: 2020/10/11 20:45:43 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char c, char const *set)
{
	size_t	i;

	i = -1;
	while (set[++i])
		if (c == set[i])
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	end = ft_strlen(s1);
	start = 0;
	while (s1[start] && ft_isset(s1[start], set))
		start++;
	if (start != end)
	{
		end -= 1;
		while (s1[end] && ft_isset(s1[end], set))
			end--;
	}
	ret = (char *)malloc(sizeof(char) * end - start + 2);
	if (!ret)
		return (NULL);
	s1 += start;
	ft_strlcpy(ret, s1, end - start + 2);
	return (ret);
}
