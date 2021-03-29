/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <jeongwle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 13:53:52 by jeongwle          #+#    #+#             */
/*   Updated: 2021/03/29 19:54:51 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int			ft_atoi(const char *str)
{
	int				sign;
	long long int	res;

	res = 0;
	sign = 1;
	while (is_space(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		res = res * 10 + *str - '0';
		if (sign == 1 && res > 2147483647)
			return (-1);
		if (sign == -1 && res > 2147483648)
			return (0);
		str++;
	}
	return (sign * res);
}
