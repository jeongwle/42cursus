/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 17:04:39 by jeongwle          #+#    #+#             */
/*   Updated: 2020/11/20 19:46:54 by jeongwle         ###   ########.fr       */
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
	ft_printf("[%c]\n", );
	printf("[%c]\n", );
//	while (1)
//	{
//		;
//	}
	return (0);

}*/
