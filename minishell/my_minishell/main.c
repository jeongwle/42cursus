/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 13:16:04 by jeongwle          #+#    #+#             */
/*   Updated: 2021/05/13 18:53:53 by jeongwle         ###   ########.fr       */
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

void	head_clear(t_mini *mini)
{
	if (mini->head->history)
	{
		free(mini->head->history);
		mini->head->history = NULL;
	}
	if (mini->head->temp)
	{
		free(mini->head->temp);
		mini->head->temp = NULL;
	}
	mini->head->flag = 0;
	mini->curr = mini->head;
}
int	main(int argc, char *argv[], char *envp[])
{
	long long int	compare;
	t_mini			mini;

	argc = 0;
	argv = 0;
	mini.idx = 0;
	mini.temp = NULL;
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
					if (mini.curr->history && ft_strlen(mini.curr->history) != 0)
						mini_lstadd_middle(&mini, mini_lstnew(mini.curr->history));
					if (mini.curr->history)
						ft_free(&mini.curr->history);
					if (mini.curr->temp)
					{
						mini.curr->history = ft_strdup(mini.curr->temp);
						ft_free(&mini.curr->temp);
					}
				}
				else if (mini.curr->history)
					mini_lstadd_middle(&mini, mini_lstnew(mini.curr->history));
				clear_buf(&mini);
				head_clear(&mini);
			}
			else
			{
				mini.buf[mini.idx] = compare;
				mini.idx++;
				if (mini.curr->history && mini.curr != mini.head)
				{
					mini.curr->flag = 1;
					if (!mini.curr->temp)
						mini.curr->temp = mini.curr->history;
					else
						mini.temp = mini.curr->history;
					mini.curr->history = ft_strjoin(mini.curr->history, mini.buf);
					if (mini.temp)
						ft_free(&mini.temp);
					clear_buf(&mini);
				}
				else if (mini.curr == mini.head)
				{
					if (mini.curr->temp)
						ft_free(&mini.curr->temp);
					if (mini.curr->history)
						mini.curr->temp = mini.curr->history;
					mini.curr->history = ft_strjoin(mini.curr->temp, mini.buf);
					if (mini.curr->temp)
						ft_free(&mini.curr->temp);
					clear_buf(&mini);
				}
			}
		}
		compare = 0;
	}
}