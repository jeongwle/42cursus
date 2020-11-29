/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 15:11:42 by jeongwle          #+#    #+#             */
/*   Updated: 2020/11/24 23:44:29 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		put_flag_else(const char **format)
{
	if (**format == 'c' || **format == 's' || **format == 'p' ||
			**format == 'd' || **format == 'i' || **format == 'u' ||
			**format == 'x' || **format == 'X' || **format == '%')
		return ((char)**format);
	else
		return (-1);
}

void	asterisk(const char **format, t_format *flag, va_list ap)
{
	if (flag->dot)
	{
		flag->precision = va_arg(ap, int);
		if (flag->precision < 0)
		{
			flag->precision = 0;
			flag->dot = 0;
		}
	}
	else
	{
		if ((flag->width = va_arg(ap, int)) < 0)
		{
			flag->width *= -1;
			flag->minus = 1;
		}
	}
	(*format)++;
}

void	put_flag_sub(const char **format, t_format *flag)
{
	if (**format == '0')
	{
		flag->zero = 1;
		(*format)++;
	}
	else if (**format == '-')
	{
		flag->minus = 1;
		(*format)++;
	}
	else if (**format == '.')
	{
		flag->dot = 1;
		(*format)++;
	}
}

int		put_flag(const char **format, t_format *flag, va_list ap)
{
	while (**format)
	{
		if (ft_isdigit(**format) && !(flag->dot))
		{
			if (**format == '0')
				flag->zero = 1;
			flag->width = ft_atoi(*format);
			while (ft_isdigit(**format))
				(*format)++;
		}
		else if (ft_isdigit(**format) && flag->dot)
		{
			flag->precision = ft_atoi(*format);
			while (ft_isdigit(**format))
				(*format)++;
		}
		else if (**format == '*')
			asterisk(format, flag, ap);
		else if (**format == '0' || **format == '-' || **format == '.')
			put_flag_sub(format, flag);
		else
			return (put_flag_else(format));
	}
	return (-1);
}

int		parsing(const char **format, int conv, va_list ap, t_format *flag)
{
	(*format)++;
	if (conv == 'd')
		return (check_temp(ap, flag));
	if (conv == 'i')
		return (check_temp(ap, flag));
	if (conv == 'u')
		return (check_u_temp(ap, flag));
	if (conv == 'x')
		return (check_x_upperx(ap, flag, conv));
	if (conv == 'X')
		return (check_x_upperx(ap, flag, conv));
	if (conv == 'p')
		return (check_p_temp(ap, flag));
	if (conv == 'c')
		return (check_c_temp(ap, flag));
	if (conv == 's')
		return (check_s_temp(ap, flag));
	if (conv == '%')
		return (write_percent(flag));
	return (0);
}
