/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 17:05:12 by jeongwle          #+#    #+#             */
/*   Updated: 2020/11/24 23:40:33 by jeongwle         ###   ########.fr       */
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

int					ft_printf(const char *format, ...);
void				initialize_variable(const char **format, t_format *flag);
int					put_flag(const char **format, t_format *flag, va_list ap);
int					parsing(const char **foramt, int conv,
					va_list ap, t_format *flag);
int					check_temp(va_list ap, t_format *flag);
int					write_d(t_format *flag, int temp_len, char *temp);
int					flag_minus(t_format *flag, int temp_l, int temp_s,
					char *temp);
int					flag_not_minus(t_format *flag, int temp_l, int temp_s,
					char *temp);
int					not_minus_zero(t_format *flag, int temp_l, int temp_s,
					char *temp);
int					check_u_temp(va_list ap, t_format *flag);
int					check_x_upperx(va_list ap, t_format *flag, char conversion);
int					check_p_temp(va_list ap, t_format *flag);
int					check_c_temp(va_list ap, t_format *flag);
int					write_c(t_format *flag, char param, int param_len);
void				write_c_else(t_format *flag, char param, int *res,
					int width_temp);
int					check_s_temp(va_list ap, t_format *flag);
void				write_s(t_format *flag, int temp_len, char *temp,
					int *res);
void				write_s_else(t_format *flag, int temp_len, char *temp,
					int *res);
int					write_percent(t_format *flag);
void				asterisk(const char **format, t_format *flag, va_list ap);
int					put_flag_else(const char **format);
void				put_flag_sub(const char **format, t_format *flag);

#endif
