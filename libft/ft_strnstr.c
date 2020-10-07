/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 06:15:18 by jeongwle          #+#    #+#             */
/*   Updated: 2020/10/07 15:19:01 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	n_len;
	int		j;

	i = 0;
	j = 0;
	n_len = ft_strlen(needle);
	if (!*needle)
		return ((char *)haystack);
	if (len < n_len)
		return (NULL);
	while (i < len - n_len + 1)
	{
		if (haystack[i] == needle[j])
		{
			if (ft_strncmp(&haystack[i], needle, n_len) == 0)
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}

int	main(void)
{
	printf("%s \n", ft_strnstr(((void *)0), "fake", 3));
}
