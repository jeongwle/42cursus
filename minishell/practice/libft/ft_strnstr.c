/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 06:15:18 by jeongwle          #+#    #+#             */
/*   Updated: 2020/10/13 19:26:15 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h_s, const char *n_d, size_t len)
{
	size_t	i;
	size_t	n_len;
	size_t	h_len;
	int		j;

	i = 0;
	j = 0;
	n_len = ft_strlen(n_d);
	h_len = ft_strlen(h_s);
	if (!*n_d)
		return ((char *)h_s);
	if (len < n_len || h_len < n_len)
		return (NULL);
	while (i < len - n_len + 1)
	{
		if (h_s[i] == n_d[j])
		{
			if (ft_strncmp(&h_s[i], n_d, n_len) == 0)
				return ((char *)&h_s[i]);
		}
		i++;
	}
	return (NULL);
}
