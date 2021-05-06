/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 02:54:40 by jeongwle          #+#    #+#             */
/*   Updated: 2021/04/27 11:49:29 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*ft_calloc(size_t count, size_t size)
{
	int		i;
	void	*res;

	i = 0;
	res = malloc(size * count);
	if (!res)
		return (NULL);
	count *= size;
	while (count--)
	{
		*((unsigned char *)res + i) = 0;
		i++;
	}
	return (res);
}
