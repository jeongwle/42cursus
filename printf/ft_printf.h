/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 17:05:12 by jeongwle          #+#    #+#             */
/*   Updated: 2020/11/20 19:37:47 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>

typedef struct		s_format
{
	int	zero;
	int	minus;
	int	width;
	int	dot;
	int	precision;
}					t_format;

int		ft_printf(const char *format, ...);
void	print_flag(t_format *flag);
void	initialize_variable(t_format *flag);
char	put_flag(const char **format, t_format *flag, va_list ap);
char	check_conversion(const char **format);
int		parsing_by_conversion(char conversion, va_list ap, t_format *flag);
int		check_temp(va_list ap, t_format *flag);
int		write_d(t_format *flag, int temp_len, char *temp);
int		flag_minus(t_format *flag, int temp_l, int temp_s, char *temp);
int		flag_not_minus(t_format *flag, int temp_l, int temp_s, char *temp);
int		not_minus_zero(t_format *flag, int temp_l, int temp_s, char *temp);
int		check_u_temp(va_list ap, t_format *flag);
int		check_x_upperx(va_list ap, t_format *flag, char conversion);
int		check_p_temp(va_list ap, t_format *flag);
int		check_c_temp(va_list ap, t_format *flag);
int		write_c(t_format *flag, char param, int param_len);

#endif
