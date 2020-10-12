/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <jeongwle@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 17:05:28 by jeongwle          #+#    #+#             */
/*   Updated: 2020/10/12 18:55:01 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	start_point(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	return (i);
}

static size_t	end_point(char const *s1, char const *set)
{
	size_t	i;

	i = ft_strlen(s1) - 1;
	while (s1[i] && ft_strchr(set, s1[i]))
	{
		if (i == 0)
			break ;
		i--;
	}
	return (i);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	start;
	size_t	end;
	size_t	len;
	int		i;

	i = 0;
	if (!s1)
		return (NULL);
	start = start_point(s1, set);
	end = end_point(s1, set);
	if (start >= end)
		return (ft_strdup(""));
	len = end - start + 1;
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (len--)
	{
		res[i] = s1[start];
		i++;
		start++;
	}
	res[i] = 0;
	return (res);
}
