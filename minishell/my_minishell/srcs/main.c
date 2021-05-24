/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 13:16:04 by jeongwle          #+#    #+#             */
/*   Updated: 2021/05/24 17:44:05 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	long long int	compare;
	t_mini			mini;

	argc = 0;
	argv = 0;
	mini.idx = 0;
	mini.temp = NULL;
	mini.atoi_flag = 0;
	compare = 0;
	term_set();
	init_history_param(&mini);
	make_export_list(&mini, envp);
	signal(SIGINT, (void *)signal_handler);
	write(1, "minishell > ", 12);
	while (read(0, &compare, 4) > 0)
	{
		if (compare == BACKSPACE)
			delete_end(&mini);
		else if (compare == ARROWUP || compare == ARROWDOWN)
			arrow_up_down(&mini, compare);
		else
		{
			write(1, &compare, 1);
			if (compare == '\n')
			{
				make_history_lst(&mini);
				write(1, "minishell > ", 12);
				if (!ft_strncmp("pwd", mini.curr->next->history, 3))
					pwd();
				else if (!ft_strncmp("cd", mini.curr->next->history, 2))
					cd(mini.curr->next->history);
			}
			else
			{
				mini.buf[mini.idx] = compare;
				mini.idx++;
				if (mini.curr->history && mini.curr != mini.head)
					ifn_head(&mini);
				else if (mini.curr == mini.head)
					if_head(&mini);
			}
		}
		compare = 0;
	}
}
