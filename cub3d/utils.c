/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 09:06:09 by jeongwle          #+#    #+#             */
/*   Updated: 2021/04/05 20:15:34 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		word_count(char const *s, char c)
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
	return (count);
}

char	is_space(char c)
{
	return (c == ' ' || (9 <= c && c <= 13));
}

int		ft_atoi(const char *str)
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

int		ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

int		ft_isalpha(int c)
{
	if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'))
		return (1);
	return (0);
}
