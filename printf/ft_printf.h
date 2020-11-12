/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 17:05:12 by jeongwle          #+#    #+#             */
/*   Updated: 2020/11/12 11:19:23 by jeongwle         ###   ########.fr       */
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
	int	asterisk;
}					t_format;

int		ft_printf(const char *format, ...);
void	print_flag(t_format *flag);
void	initialize_variable(t_format *flag);
char	put_flag(const char **format, t_format *flag);
char	check_conversion(const char **format);
void	parsing_by_conversion(char conversion, va_list ap, t_format *flag);
void	check_asterisk(va_list ap, t_format *flag);
void	check_minus_zero(t_format *flag, int temp_len, char *temp);

#endif
