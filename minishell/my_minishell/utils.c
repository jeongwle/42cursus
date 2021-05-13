/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 12:53:08 by jeongwle          #+#    #+#             */
/*   Updated: 2021/05/13 18:47:31 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strndup(const char *s, int n)
{
	int		i;
	char	*res;

	i = 0;
	res = (char *)malloc(sizeof(char) * (n + 1));
	if (!res)
		return (NULL);
	while (i < n)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = 0;
	return (res);
}

void	ft_free(char **s)
{
	free(*s);
	*s = NULL;
}