/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 10:36:17 by jeongwle          #+#    #+#             */
/*   Updated: 2020/12/01 12:48:23 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

size_t ft_strlen(char *str)
{
	size_t	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_numlen(long long n, int base_len)
{
	int i = 1;

	if (n >= base_len || n <= -base_len)
	{
		n /= base_len;
		i++;
	}
	return (i);
}

void	ft_putnum(long long n, int base_len, char *base)
{
	if (n >= base_len)
		ft_putnum(n / base_len, base_len, base);
	write(1, &base[n % base_len], 1);
}

int	ft_printf(char *format, ...)
{
	va_list ap;
	char	*base, *s, *str;
	long	num;
	int		width = 0, prec = 0, bolprec = 0, base_len, n = 0, space = 0, neg = 0, zeros = 0, leng = 0;

	va_start(ap, *format);
	str = (char *)format;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			width = 0, prec = 0, bolprec = 0, n = 0, space = 0, neg = 0, zeros = 0;
			while ('0' <= *str && *str <= '9')
			{
				width = width * 10 + (*str - 48);
				str++;
			}
			if (*str == '.')
			{
				str++;
				while ('0' <= *str && *str <= '9')
				{
					prec = prec * 10 + (*str - 48);
					str++;
				}
				bolprec = 1;
			}
			if (*str == 's')
			{
				s = va_arg(ap, (char *));
				if (!s)
					s = "(null)";
				n = ft_strlen(s);
			}
			if (*str == 'd')
			{
				num = va_arg(ap, int);
				base = "0123456789";
				base_len = 10;
				if (num < 0 )
				{
					num *= -1;
					neg = 1;
				}
				n = ft_numlen(num, base_len) + neg;
			}
			if (*str == 'x')
			{
				num = va_arg(ap, unsigned int);
				base = "0123456789abcdef";
				base_len = 16;
				n = ft_numlen(num, base_len);
			}
			if (bolprec == 1 && prec >= n && *str != 's')
				zeros = prec - n + neg;
			else if (bolprec == 1 && prec < n && *str == 's')
				n = prec;
			else if (bolprec == 1 && prec == 0 && (*str == 's' || num == 0))
				n = 0;
			space = width - n - zeros;
			while (space-- > 0)
			{
				write(1, " ", 1);
				leng++;
			}
			if (neg == 1)
				write(1, "-", 1);
			while (zeros-- > 0)
			{
				write(1, "0", 1);
				leng++;
			}
			if (*str == 's')
				write(1, s, n);
			else if (n > 0)
				ft_putnum(num, base_len, base);
			leng += n;
			str++;
		}
		else
		{
			write(1, str, 1);
			leng++;
			str++;
		}
	}
	return (leng);
}
