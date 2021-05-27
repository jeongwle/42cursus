/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 13:16:04 by jeongwle          #+#    #+#             */
/*   Updated: 2021/05/27 19:44:44 by jeongwle         ###   ########.fr       */
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
	mini.row_flag = 0;
	mini.temp = NULL;
	mini.atoi_flag = 0;
	mini.make_history_flag = 0;
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
				if (mini.make_history_flag)
				{
					mini.something = lexical_analyzer(mini.curr->next->history, 0, 0);
					mini.lst = mini.something->content;
					mini.make_history_flag = 0;
					if (!ft_strncmp("pwd", ((char **)mini.lst->content)[0], 3))
						pwd();
					else if (!ft_strncmp("cd", ((char **)mini.lst->content)[0], 2))
						cd(&mini, ((char **)mini.lst->content)[1]);
					else if (!ft_strncmp("export", ((char **)mini.lst->content)[0], 6))
						check_export_param(&mini, ((char **)mini.lst->content));
					else if (!ft_strncmp("env", ((char **)mini.lst->content)[0], 3))
						print_env(&mini);

				}
				write(1, "minishell > ", 12);
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
