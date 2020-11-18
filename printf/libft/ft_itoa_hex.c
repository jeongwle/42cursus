/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 13:27:15 by jeongwle          #+#    #+#             */
/*   Updated: 2020/11/18 15:48:50 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	len_count(long long int n)
{
	size_t			count;
	long long int	num;

	count = 1;
	if (n < 0)
		num = -1 * n;
	if (n >= 0)
		num = n;
	while (num / 16)
	{
		count++;
		num /= 16;
	}
	return (count);
}

static char		*if_plus(long long int n, char conversion)
{
	char			*res;
	size_t			size;

	size = len_count(n);
	if (!(res = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	res[size] = 0;
	while (size--)
	{
		if (n % 16 >= 10 && conversion == 'x')
			res[size] = n % 16 - 10 + 'a';
		else if (n % 16 >= 10 && conversion == 'X')
			res[size] = n % 16 - 10 + 'A';
		else
			res[size] = n % 16 + '0';
		n /= 16;
	}
	return (res);
}

static char		*if_minus(long long int n, char conversion)
{
	char			*res;
	size_t			size;
	long long int	num;

	size = len_count(n);
	num = -1 * n;
	if (!(res = (char *)malloc(sizeof(char) * (size + 2))))
		return (NULL);
	res[size + 1] = 0;
	while (size >= 1)
	{
		if (num % 16 >= 10 && conversion == 'x')
			res[size] = num % 16 - 10 + 'a';
		else if (num % 16 >= 10 && conversion == 'X')
			res[size] = num % 16 - 10 + 'A';
		else
			res[size] = num % 16 + '0';
		num /= 16;
		size--;
	}
	res[size] = '-';
	return (res);
}

char			*ft_itoa_hex(long long int n, char conversion)
{
	char			*res;

	if (n >= 0)
		res = if_plus(n, conversion);
	else
		res = if_minus(n, conversion);
	return (res);
}
