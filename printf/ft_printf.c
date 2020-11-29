/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 17:04:39 by jeongwle          #+#    #+#             */
/*   Updated: 2020/11/24 23:44:42 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

void	initialize_variable(const char **format, t_format *flag)
{
	flag->zero = 0;
	flag->minus = 0;
	flag->width = 0;
	flag->dot = 0;
	flag->precision = 0;
	(*format)++;
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	t_format	flag;
	int			conversion;
	int			result;

	result = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			initialize_variable(&format, &flag);
			if ((conversion = put_flag(&format, &flag, ap)) == -1)
				return (-1);
			result += parsing(&format, conversion, ap, &flag);
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
