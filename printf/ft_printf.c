/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 17:04:39 by jeongwle          #+#    #+#             */
/*   Updated: 2020/11/12 18:28:23 by jeongwle         ###   ########.fr       */
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
	printf("%d ", flag->precision);
	printf("%d\n", flag->asterisk);
}

int	ft_printf(const char *format, ...)
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
			conversion = put_flag(&format, &flag);
			parsing_by_conversion(conversion, ap, &flag);
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
	return (0);
}
/*
int	main(void)
{
	ft_printf("[%.6d]", -3);
}*/
