/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_write_u.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 18:18:37 by jeongwle          #+#    #+#             */
/*   Updated: 2020/11/18 19:32:47 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	check_u_temp(va_list ap, t_format *flag)
{
	char				*temp;
	long long int		param;
	int					temp_len;

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

int	check_x_X(va_list ap, t_format *flag, char conversion)
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
