/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 13:16:04 by jeongwle          #+#    #+#             */
/*   Updated: 2021/05/11 19:50:48 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clear_buf(t_mini *mini)
{
	int	i;

	i = 0;
	while (mini->buf[i])
	{
		mini->buf[i] = 0;
		i++;
	}
	mini->idx = 0;
}

int	main(int argc, char *argv[], char *envp[])
{
	long long int	compare;
	t_mini			mini;

	argc = 0;
	argv = 0;
	mini.idx = 0;
	compare = 0;
	term_set();
	init_history_param(&mini);
	signal(SIGINT, (void *)signal_handler);
	while (read(0, &compare, 4) > 0)
	{
		if (compare == BACKSPACE)
		{
			delete_end(&mini);
		}
		else if (compare == ARROWUP || compare == ARROWDOWN)
		{
			arrow_up_down(&mini, compare);
		}
		else
		{
			write(1, &compare, 1);
			if (compare == '\n')
			{
				mini.buf[mini.idx] = 0;
				if (mini.curr->flag)
				{
					mini_lstadd_middle(&mini, mini_lstnew(ft_strjoin(mini.curr->history, mini.buf)));
					free(mini.curr->history);
					mini.curr->history = ft_strdup(mini.curr->temp);
					free(mini.curr->temp);

				}
				else
					mini_lstadd_middle(&mini, mini_lstnew(mini.buf));
				clear_buf(&mini);
			}
			else
			{
				mini.buf[mini.idx] = compare;
				mini.idx++;
			}
		}
		compare = 0;
	}
}