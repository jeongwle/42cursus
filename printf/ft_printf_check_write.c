/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_check_write.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 16:26:48 by jeongwle          #+#    #+#             */
/*   Updated: 2020/11/25 02:43:21 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_c_else(t_format *flag, char param, int *res, int width_temp)
{
	if (flag->zero)
	{
		while (width_temp-- > 0)
			*res += ft_putstr_for_pft("0");
		write(1, &param, 1);
		(*res)++;
	}
	else
	{
		while (width_temp-- > 0)
			*res += ft_putstr_for_pft(" ");
		write(1, &param, 1);
		(*res)++;
	}
}

int		write_c(t_format *flag, char param, int param_len)
{
	int		res;
	int		width_temp;

	res = 0;
	width_temp = flag->width - param_len;
	if (!(param))
		width_temp = flag->width - 1;
	if (flag->minus)
	{
		write(1, &param, 1);
		res++;
		while (width_temp-- > 0)
			res += ft_putstr_for_pft(" ");
	}
	else
		write_c_else(flag, param, &res, width_temp);
	return (res);
}

int		check_s_temp(va_list ap, t_format *flag)
{
	char	*temp;
	int		temp_len;
	int		res;

	res = 0;
	temp = va_arg(ap, char *);
	if (!temp)
		temp = ft_strdup("(null)");
	temp_len = ft_strlen(temp);
	write_s(flag, temp_len, temp, &res);
	return (res);
}

void	write_s_else(t_format *flag, int temp_len, char *temp, int *res)
{
	if (temp_len >= flag->precision)
	{
		if (flag->dot)
			temp_len = flag->precision;
		else
			flag->precision = temp_len;
		if (flag->precision < flag->width && flag->zero)
			*res += ft_putchar("0", (flag->width - flag->precision));
		else
			*res += ft_putchar(" ", (flag->width - flag->precision));
		*res += ft_putchar(temp, flag->precision);
	}
	else
	{
		flag->precision = temp_len;
		if (flag->precision < flag->width && flag->zero)
			*res += ft_putchar("0", (flag->width - flag->precision));
		else
			*res += ft_putchar(" ", (flag->width - flag->precision));
		*res += ft_putchar(temp, flag->precision);
	}
}

void	write_s(t_format *flag, int temp_len, char *temp, int *res)
{
	if (flag->minus)
	{
		if (temp_len >= flag->precision)
		{
			if (flag->dot)
				temp_len = flag->precision;
			else
				flag->precision = temp_len;
			*res += ft_putchar(temp, flag->precision);
			if (flag->precision < flag->width)
				*res += ft_putchar(" ", (flag->width - flag->precision));
		}
		else
		{
			flag->precision = temp_len;
			*res += ft_putchar(temp, flag->precision);
			if (flag->precision < flag->width)
				*res += ft_putchar(" ", (flag->width - flag->precision));
		}
	}
	else
		write_s_else(flag, temp_len, temp, res);
}
