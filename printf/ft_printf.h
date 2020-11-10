/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 17:05:12 by jeongwle          #+#    #+#             */
/*   Updated: 2020/11/10 17:18:59 by jeongwle         ###   ########.fr       */
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

#endif
