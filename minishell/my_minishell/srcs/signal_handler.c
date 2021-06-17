/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 15:29:18 by jeongwle          #+#    #+#             */
/*   Updated: 2021/06/17 20:42:26 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	signal_handler(int signum)
{
	if (signum == SIGINT && g_mini.sig_flag == 0)
	{
		write(1, "\n", 1);
		ft_free(&g_mini.head->history);
		if (!g_mini.semi)
			write(1, "minishell > ", 12);
	}
	else if (signum == SIGQUIT && g_mini.pid && g_mini.sig_flag == 0)
		write(1, "Quit: 3\n", 8);
}
