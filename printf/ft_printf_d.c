/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 17:35:42 by jeongwle          #+#    #+#             */
/*   Updated: 2020/11/09 21:11:10 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	initialize_variable(int *m, int *d, int *z, t_format *flag)
{
	*m = 0;
	*d = 0;
	*z = 0;
	flag->zero = 0;
	flag->minus = 0;
	flag->width = 0;
	flag->dot = 0;
	flag->precision = 0;
}

void	put_flag(const char **format)
{
	t_format	flag;
	int			minus_sign;
	int			dot_sign;
	int			zero_sign;

	initialize_variable(&minus_sign, &dot_sign, &zero_sign, &flag);
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
		else if (**format == 'c' || **format == 's' || **format == 'p' ||
				**format == 'd' || **format == 'i' || **format == 'u' ||
				**format == 'x' || **format == 'X')
			(*format)++;
	}
	printf("%d %d %d %d %d\n", flag.zero, flag.minus, flag.width, flag.dot, flag.precision);
}

int main(void)
{
	const char	*temp;
	const char	*temp_temp;

	temp = ft_strdup("-0-0-10.5d");
	temp_temp = temp;
	put_flag(&temp);
	printf("%s", temp_temp);
	return (0);
}
