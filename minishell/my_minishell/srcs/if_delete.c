/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_delete.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <jeongwle@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 16:08:03 by jeongwle          #+#    #+#             */
/*   Updated: 2021/05/27 19:44:50 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		nbr_length(int n)
{
	int i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

void	get_cursor_position(int *col, int *row)
{
	int		a;
	int		i;
	char	buf[255];
	int		ret;

	a = 0;
	i = 0;
	write(0, "\033[6n", 4);
	ret = read(0, buf, 254);
	buf[ret] = 0;
	while (buf[i])
	{
		if (ft_isdigit(buf[i]))
		{
			if (a == 0)
				*row = ft_atoi(&(buf[i])) - 1;
			else
				*col = ft_atoi(&(buf[i])) - 1;
			a++;
			i += nbr_length(*col + 1) - 1;
		}
		i++;
	}
}

int		putchar_tc(int tc)
{
	write(1, &tc, 1);
	return (0);
}

void	delete_end(t_mini *mini)
{
	int		row;
	int		col;
	char	*cm;
	char	*ce;

	if (mini->idx > 0)
		(mini->idx)--;
	mini->buf[mini->idx] = 0;
	row = 0;
	col = 0;
	tgetent(NULL, "xterm");
	cm = tgetstr("cm", NULL);
	ce = tgetstr("ce", NULL);
	get_cursor_position(&col, &row);
	if (col != 0 && col != 12)
		--(col);
	tputs(tgoto(cm, col, row), 1, putchar_tc);
	tputs(ce, 1, putchar_tc);
	if (mini->curr->history)
		if_history_modified(mini);
}

void	delete_prev(void)
{
	int		row;
	int		col;
	char	*cm;
	char	*ce;

	row = 0;
	col = 0;
	tgetent(NULL, "xterm");
	cm = tgetstr("cm", NULL);
	ce = tgetstr("ce", NULL);
	get_cursor_position(&col, &row);
	while (col)
		--(col);
	tputs(tgoto(cm, col, row), 1, putchar_tc);
	tputs(ce, 1, putchar_tc);
}
