/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 19:53:33 by jeongwle          #+#    #+#             */
/*   Updated: 2020/11/25 02:44:24 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(char *str, int temp_len)
{
	int	res;
	int	index;
	int len;

	res = 0;
	index = 0;
	len = ft_strlen(str);
	if ((len == 1 && *str == ' ') || (len == 1 && *str == '0'))
	{
		while (index++ < temp_len)
		{
			write(1, str, 1);
			res++;
		}
	}
	else
	{
		while (index < temp_len)
		{
			write(1, &str[index], 1);
			index++;
			res++;
		}
	}
	return (res);
}
