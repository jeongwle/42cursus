/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 17:04:39 by jeongwle          #+#    #+#             */
/*   Updated: 2020/11/23 22:41:38 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	print_flag(t_format *flag)
{
	printf("%d ", flag->zero);
	printf("%d ", flag->minus);
	printf("%d ", flag->width);
	printf("%d ", flag->dot);
	printf("%d\n", flag->precision);
}

int		write_percent(t_format *flag)
{
	int	res;
	int len;

	res = 0;
	len = 1;
	if (flag->minus)
	{
		res += ft_putstr_for_pft("%");
		res += ft_putchar(" ", (flag->width - len));
	}
	else
	{
		if (flag->zero)
		{
			res += ft_putchar("0", (flag->width - len));
			res += ft_putstr_for_pft("%");
		}
		else
		{
			res += ft_putchar(" ", (flag->width - len));
			res += ft_putstr_for_pft("%");
		}
	}
	return (res);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	t_format	flag;
	char		conversion;
	int			result;

	result = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			initialize_variable(&flag);
			format++;
			conversion = put_flag(&format, &flag, ap);
			result += parsing_by_conversion(conversion, ap, &flag);
			format++;
		}
		else
		{
			write(1, format, 1);
			result++;
			format++;
		}
	}
	va_end(ap);
	return (result);
}
/*
int	main(void)
{
	int	i;

	i = 0;
	ft_printf("[%2c]\n", '!');
	printf("[%2c]\n", '!');
//	while (1)
//	{
//		;
//	}
	return (0);

}*/
