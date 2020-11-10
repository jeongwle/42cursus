/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 17:35:42 by jeongwle          #+#    #+#             */
/*   Updated: 2020/11/10 13:28:53 by jeongwle         ###   ########.fr       */
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

void	check_conversion(const char **foramt, t_format *flag)
{
//	if (**format == 'c')
//		return ();
//	else if (**format == 's')
//		return ();
//	else if (**format == 'p')
//		return ();
	else if (**format == 'd')
		return (write_d();
//	else if (**format == 'i')
//		return ();
//	else if (**format == 'u')
//		return ();
//	else if (**format == 'x')
//		return ();
//	else if (**format == 'X')
//		return ();
}

void	put_flag(const char **format)
{
	t_format	flag;

	initialize_variable(&flag);
	while (**format)
	{
		if (ft_isdigit(**format) && !(flag.dot))
		{
			if (**format == '0')
				flag.zero = 1;
			flag.width = ft_atoi(*format);
			while (ft_isdigit(**format))
				(*format)++;
		}
		else if (ft_isdigit(**format) && flag.dot)
		{
			flag.precision = ft_atoi(*format);
			while (ft_isdigit(**format))
				(*format)++;
		}
		else if (**format == '0')
		{
			flag.zero = 1;
			(*format)++;
		}
		else if (**format == '-')
		{
			flag.minus = 1;
			(*format)++;
		}
		else if (**format == '.')
		{
			flag.dot = 1;
			(*format)++;
		}
		return (check_conversion(*format, &flag);
/*		else if (**format == 'c' || **format == 's' || **format == 'p' ||
				**format == 'd' || **format == 'i' || **format == 'u' ||
				**format == 'x' || **format == 'X')
			(*format)++;*/
	}
}

int main(void)
{
	const char	*temp;
	const char	*temp_temp;

	temp = ft_strdup("0000-1010.4d");
	temp_temp = temp;
	put_flag(&temp);
	printf("%s", temp_temp);
	return (0);
}
