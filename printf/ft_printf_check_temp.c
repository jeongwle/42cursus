/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_check_temp.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 15:20:54 by jeongwle          #+#    #+#             */
/*   Updated: 2020/11/20 19:53:55 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	check_u_temp(va_list ap, t_format *flag)
{
	char			*temp;
	long long int	param;
	int				temp_len;

	param = va_arg(ap, unsigned int);
	temp = ft_itoa(param);
	temp_len = ft_strlen(temp);
	if ((ft_atoi(temp)) == 0 && flag->dot && !(flag->precision))
	{
		free(temp);
		temp = ft_strdup("");
		temp_len = 0;
	}
	return (write_d(flag, temp_len, temp));
}

int	check_x_upperx(va_list ap, t_format *flag, char conversion)
{
	char			*temp;
	long long int	param;
	int				temp_len;

	param = va_arg(ap, unsigned int);
	temp = ft_itoa_hex(param, conversion);
	temp_len = ft_strlen(temp);
	if (!('a' <= temp[0] && temp[0] <= 'f') &&
			!('A' <= temp[0] && temp[0] <= 'F'))
	{
		if ((ft_atoi(temp)) == 0 && flag->dot && !(flag->precision))
		{
			free(temp);
			temp = ft_strdup("");
			temp_len = 0;
		}
	}
	return (write_d(flag, temp_len, temp));
}

int	check_p_temp(va_list ap, t_format *flag)
{
	char			*temp;
	char			*temp_temp;
	char			*p_temp;
	long long int	param;
	int				temp_len;

	param = va_arg(ap, long long int);
	p_temp = ft_strdup("0x");
	temp = ft_itoa_hex(param, 'x');
	if ((ft_atoi(temp)) == 0 && flag->dot && !(flag->precision))
	{
		free(temp);
		temp = ft_strdup("");
	}
	temp_temp = temp;
	temp = ft_strjoin(p_temp, temp);
	free(p_temp);
	free(temp_temp);
	temp_len = ft_strlen(temp);
	return (write_d(flag, temp_len, temp));
}

int	check_c_temp(va_list ap, t_format *flag)
{
	char			param;
	int				param_len;

	param = (char)va_arg(ap, int);
	param_len = ft_strlen(&param);
	return (write_c(flag, param, param_len));
}
