/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 17:35:42 by jeongwle          #+#    #+#             */
/*   Updated: 2020/11/16 19:52:28 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	initialize_variable(t_format *flag)
{
	flag->zero = 0;
	flag->minus = 0;
	flag->width = 0;
	flag->dot = 0;
	flag->precision = 0;
}

char	check_conversion(const char **format)
{
	if (**format == 'c' || **format == 's' || **format == 'p' ||
**format == 'd' || **format == 'i' || **format == 'u' ||
**format == 'x' || **format == 'X')
		return ((char)**format);
	return (0);
}

char	put_flag(const char **format, t_format *flag, va_list ap)
{
	while (**format)
	{
	//	print_flag(flag);
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
		else if (**format == '0')
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
		else
			return (check_conversion(format));
	}
	return (0);
}

int	parsing_by_conversion(char conversion, va_list ap, t_format *flag)
{
	if (conversion == 'd')
		return (check_temp(ap, flag));
	if (conversion == 'i')
		return (check_temp(ap, flag));
	if (conversion == 'u')
		return (check_u_temp(ap, flag));
	return (0);
}
