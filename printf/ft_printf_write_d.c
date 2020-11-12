/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_write_d.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <jeongwle@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 12:59:59 by jeongwle          #+#    #+#             */
/*   Updated: 2020/11/12 18:44:31 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_minus_zero(t_format *flag, int temp_len, char *temp)
{
	int	precision_temp;
	int	len_temp;
	int	temp_sign;

	temp_sign = 0;
	if (ft_atoi(temp) < 0)
		temp_sign = 1;
	len_temp = temp_len;
	precision_temp = flag->precision;
	if (flag->minus)
	{		
		if (temp_len > flag->precision)
		{
			write(1, temp, temp_len);
			while (temp_len < flag->width)
			{
				write(1, " ", 1);
				temp_len++;
			}
		}
		if (temp_len <= flag->precision)
		{
			if (temp_sign)
				write(1, "-", 1);
			while (len_temp < flag->precision + temp_sign)
			{
				write(1, "0", 1);
				len_temp++;
			}
			write(1, temp + temp_sign, temp_len - temp_sign);
			while (flag->precision + temp_sign < flag->width)
			{
				write(1, " ", 1);
				(flag->precision)++;
			}
		}
	}
	else if (!(flag->minus))
	{
		if ((flag->zero && flag->dot) || !(flag->zero))
		{
			if (temp_len > flag->precision)
			{
				while (len_temp < flag->width)
				{
					write(1, " ", 1);
					len_temp++;
				}
				write(1, temp, temp_len);
			}
			if (temp_len <= flag->precision)
			{
				while (precision_temp + temp_sign < flag->width)
				{
					write(1, " ", 1);
					precision_temp++;
				}
				if (temp_sign)
					write(1, "-", 1);
				while (len_temp < flag->precision + temp_sign)
				{
					write(1, "0", 1);
					len_temp++;
				}
				write(1, temp + temp_sign, temp_len - temp_sign);
			}
		}
		else if (flag->zero)
		{

			if (temp_sign)
				write(1, "-", 1);
			while (len_temp < flag->width)
			{
				write(1, "0", 1);
				len_temp++;
			}
			write(1, temp + temp_sign, temp_len - temp_sign);
		}
	}
}

void	check_asterisk(va_list ap, t_format *flag)
{
	char	*temp;
	int		temp_len;

	temp = ft_itoa(va_arg(ap, int));
	if (flag->asterisk == 2)
	{
		flag->width = ft_atoi(temp);
		flag->precision = ft_atoi(ft_itoa(va_arg(ap, int)));
		temp = ft_itoa(va_arg(ap, int));
	}
	else if (flag->asterisk == 1)
	{
		flag->width = ft_atoi(temp);
		temp = ft_itoa(va_arg(ap, int));
	}
	temp_len = ft_strlen(temp);
	return (check_minus_zero(flag, temp_len, temp));
}
