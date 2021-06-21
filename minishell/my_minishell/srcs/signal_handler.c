/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 15:29:18 by jeongwle          #+#    #+#             */
/*   Updated: 2021/06/21 15:38:27 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	signal_handler(int signum)
{
	if (signum == SIGINT && g_mini.sig_flag == 0)
	{
		write(1, "\n", 1);
		g_mini.status = 130;
		ft_free(&g_mini.head->history);
		if (g_mini.curr != g_mini.head)
		{
			while (g_mini.curr->prev)
				g_mini.curr = g_mini.curr->prev;
		}
		if (!g_mini.semi)
		{
			write(1, "minishell > ", 12);
			g_mini.status = 1;
		}
	}
	else if (signum == SIGQUIT && g_mini.pid && g_mini.sig_flag == 0)
	{
		g_mini.status = 131;
		write(1, "Quit: 3\n", 8);
	}
}
