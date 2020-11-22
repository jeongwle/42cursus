/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_write_d.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <jeongwle@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 12:59:59 by jeongwle          #+#    #+#             */
/*   Updated: 2020/11/22 21:10:00 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	not_minus_zero(t_format *flag, int temp_l, int temp_s, char *temp)
{
	int		res;

	res = 0;
	if (temp_s)
		res += ft_putstr_for_pft("-");
	while (temp_l < flag->width)
	{
		res += ft_putstr_for_pft("0");
		temp_l++;
	}
	res += ft_putstr_for_pft(temp + temp_s);
	return (res);
}

int	flag_not_minus(t_format *flag, int temp_l, int temp_s, char *temp)
{
	int		precision_temp;
	int		res;

	res = 0;
	precision_temp = flag->precision;
	if (temp_l > flag->precision)
	{
		while (temp_l++ < flag->width)
			res += ft_putstr_for_pft(" ");
		res += ft_putstr_for_pft(temp);
	}
	if (temp_l <= flag->precision)
	{
		while (precision_temp + temp_s < flag->width)
		{
			res += ft_putstr_for_pft(" ");
			precision_temp++;
		}
		if (temp_s)
			res += ft_putstr_for_pft("-");
		while (temp_l++ < flag->precision + temp_s)
			res += ft_putstr_for_pft("0");
		res += ft_putstr_for_pft(temp + temp_s);
	}
	return (res);
}

int	flag_minus(t_format *flag, int temp_l, int temp_s, char *temp)
{
	int		res;

	res = 0;
	if (temp_l > flag->precision)
	{
		res += ft_putstr_for_pft(temp);
		while (temp_l++ < flag->width)
			res += ft_putstr_for_pft(" ");
	}
	if (temp_l <= flag->precision)
	{
		if (temp_s)
			res += ft_putstr_for_pft("-");
		while (temp_l++ < flag->precision + temp_s)
			res += ft_putstr_for_pft("0");
		res += ft_putstr_for_pft(temp + temp_s);
		while (flag->precision + temp_s < flag->width)
		{
			res += ft_putstr_for_pft(" ");
			(flag->precision)++;
		}
	}
	return (res);
}

int	write_d(t_format *flag, int temp_len, char *temp)
{
	int		precision_temp;
	int		len_temp;
	int		temp_sign;
	int		result;

	temp_sign = 0;
	result = 0;
	if (ft_atoi(temp) < 0)
		temp_sign = 1;
	len_temp = temp_len;
	precision_temp = flag->precision;
	if (flag->minus)
		result += flag_minus(flag, temp_len, temp_sign, temp);
	else if (!(flag->minus))
	{
		if ((flag->zero && flag->dot) || !(flag->zero))
			result += flag_not_minus(flag, temp_len, temp_sign, temp);
		else if (flag->zero)
			result += not_minus_zero(flag, temp_len, temp_sign, temp);
	}
	if (temp)
		free(temp);
	return (result);
}

int	check_temp(va_list ap, t_format *flag)
{
	char	*temp;
	int		temp_len;

	temp = ft_itoa(va_arg(ap, int));
	temp_len = ft_strlen(temp);
	if ((ft_atoi(temp)) == 0 && flag->dot && !(flag->precision))
	{
		free(temp);
		temp = ft_strdup("");
		temp_len = 0;
	}
	return (write_d(flag, temp_len, temp));
}
