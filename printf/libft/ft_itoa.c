/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <jeongwle@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 17:35:41 by jeongwle          #+#    #+#             */
/*   Updated: 2020/10/12 18:45:40 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		len_count(int n)
{
	size_t			count;
	long long int	num;

	count = 1;
	if (n < 0)
		num = -1 * (long long int)n;
	if (n >= 0)
		num = n;
	while (num / 10)
	{
		count++;
		num /= 10;
	}
	return (count);
}

static char			*if_plus(int n)
{
	char	*res;
	size_t	size;

	size = len_count(n);
	if (!(res = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	res[size] = 0;
	while (size >= 1)
	{
		size--;
		res[size] = n % 10 + '0';
		n /= 10;
	}
	return (res);
}

static char			*if_minus(int n)
{
	char			*res;
	size_t			size;
	long long int	num;

	size = len_count(n);
	num = -1 * (long long int)n;
	if (!(res = (char *)malloc(sizeof(char) * (size + 2))))
		return (NULL);
	res[size + 1] = 0;
	while (size >= 1)
	{
		res[size] = num % 10 + '0';
		num /= 10;
		size--;
	}
	res[size] = '-';
	return (res);
}

char				*ft_itoa(int n)
{
	char			*res;

	if (n >= 0)
		res = if_plus(n);
	else
		res = if_minus(n);
	return (res);
}
