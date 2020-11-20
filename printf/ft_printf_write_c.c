/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_write_c.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 16:21:06 by jeongwle          #+#    #+#             */
/*   Updated: 2020/11/20 19:53:56 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_c(t_format *flag, char param, int param_len)
{
	int	res;
	int width_temp;

	res = 0;
	width_temp = flag->width - param_len;
	if (!(param))
		width_temp = flag->width - 1;
	if (flag->minus)
	{
		write(1, &param, 1);
		res++;
		while (width_temp--)
			res += ft_putstr_for_pft(" ");
	}
	else
	{
		if (flag->zero)
		{
			while (width_temp-- > 0)
				res += ft_putstr_for_pft("0");
			write(1, &param, 1);
			res++;
		}
		else
		{
			while (width_temp-- > 0)
				res += ft_putstr_for_pft(" ");
			write(1, &param, 1);
			res++;
		}
	}
	return (res);
}
