/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 21:36:07 by jeongwle          #+#    #+#             */
/*   Updated: 2021/04/05 20:53:06 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

size_t	ft_strlen(const char *s)
{
	size_t			i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

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

char	*ft_strdup(const char *s1)
{
	int				s1_len;
	int				i;
	char			*res;

	i = 0;
	s1_len = ft_strlen(s1);
	res = (char *)malloc(sizeof(char) * (s1_len + 1));
	if (!res)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*res;
	size_t			len;
	int				i;
	int				j;

	i = -1;
	j = -1;
	if (!s1 && s2)
		return (ft_strdup(s2));
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && !s2)
		return (NULL);
	if ((len = ft_strlen(s1) + ft_strlen(s2)) == 0)
		return (ft_strdup(""));
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s1[++i])
		res[i] = s1[i];
	while (s2[++j])
		res[i++] = s2[j];
	res[i] = 0;
	return (res);
}

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n && s1[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i == n)
		i -= 1;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
