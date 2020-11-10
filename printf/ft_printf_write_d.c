/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_write_d.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <jeongwle@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 12:59:59 by jeongwle          #+#    #+#             */
/*   Updated: 2020/11/10 21:14:40 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_minus_zero(t_format *flag, int temp_len, char *temp)
{
	if (flag->minus)
	{
		if (flag->zero)
		{
			if (temp_len >= flag->precision)
			{
				if
			}
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
		flag->precision = ft_atoi(va_arg(ap, int));
		temp = ft_itoa(va_arg(ap, int));
	}
	else if (flag->asterisk == 1)
	{
		flag->width = ft_atoi(temp);
		temp = ft_itoa(va_arg(ap, int));
	}
	temp_len = ft_strlen(temp);
	return (check_minus_zero(ap, flag, temp_len, temp));
}
