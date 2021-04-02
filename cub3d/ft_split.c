/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <jeongwle@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 11:51:51 by jeongwle          #+#    #+#             */
/*   Updated: 2021/04/02 15:55:47 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int			word_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (*(s + i) != c && *(s + i) != 0)
		count++;
	while (*(s + i))
	{
		if (*(s + i) == c)
		{
			if (*(s + i + 1) == '\0')
				break ;
			if (*(s + i + 1) != c)
				count++;
		}
		i++;
	}
//	printf("count = %d\n", count);
	return (count);
}

size_t	word_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*(s + len) != c && *(s + len))
	{
		len++;
	}
//	printf("len =%d\n", len);
	return (len);
}

static void		*ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i++]);
	}
	free(str);
	return (NULL);
}

void		get_mapwidth(t_param *p, size_t size)
{
	if (p->map_width < size)
		p->map_width = size;
}

char			**ft_split(t_param *p, char const *s, char c)
{
	char	**res;
	size_t	size;
	int		i;
	size_t	j;

	i = 0;
	if (!s || !(res = (char **)ft_calloc(word_count(s, c) + 1, sizeof(char *))))
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			size = word_len(s, c);
			if (!(res[i] = (char *)ft_calloc((size + 1), sizeof(char))))
				return (ft_free(res));
			j = 0;
			while (j < size)
				res[i][j++] = *s++;
			i++;
		}
		if (*s == '\0')
			break ;
		s++;
	}
	return (res);
}
