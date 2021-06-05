/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 13:16:04 by jeongwle          #+#    #+#             */
/*   Updated: 2021/06/05 15:15:39 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
void	check_row_flag(t_mini *mini)
{
	if (mini->col == 0 && mini->col_temp > mini->col)
	{
		mini->col_max_temp = mini->col_temp;
		mini->row_flag += 1;
	}
	mini->col_temp = mini->col;
}*/

void	parse_by_builtin(t_mini *mini)
{
	mini->something = lexical_analyzer(mini->curr->next->history, 0, 0);
	mini->lst = mini->something->content;
	mini->make_history_flag = 0;
	if (!ft_strcmp("pwd", ((char **)mini->lst->content)[0]))
		pwd();
	else if (!ft_strcmp("cd", ((char **)mini->lst->content)[0]))
		cd(mini, ((char **)mini->lst->content)[1]);
	else if (!ft_strcmp("export", ((char **)mini->lst->content)[0]))
		check_export_param(mini, ((char **)mini->lst->content));
	else if (!ft_strcmp("env", ((char **)mini->lst->content)[0]))
		print_env(mini);
	else if (!ft_strcmp("unset", ((char **)mini->lst->content)[0]))
		unset(mini, ((char **)mini->lst->content));
	else if (!ft_strcmp("exit", ((char **)mini->lst->content)[0]))
		mini_exit(mini, ((char **)mini->lst->content));
	else if (!ft_strcmp("echo", ((char **)mini->lst->content)[0]))
		ft_echo(((char **)mini->lst->content));
	else
		use_execve(mini, ((char **)mini->lst->content));
}

void	init_mini(t_mini *mini)
{
	mini->idx = 0;
	mini->row_flag = 0;
	mini->row = 0;
	mini->col = 0;
	mini->col_temp = 0;
	mini->pid = 0;
	mini->status = 0;
	mini->temp = NULL;
	mini->atoi_flag = 0;
	mini->make_history_flag = 0;
	term_set();
	init_history_param(mini);

}

int		main(int argc, char *argv[], char *envp[])
{
	long long int	compare;
	t_mini			mini;

	argc = 0;
	argv = 0;
	compare = 0;
	init_mini(&mini);
	make_export_list(&mini, envp);
	signal(SIGINT, (void *)signal_handler);
	write(1, "minishell > ", 12);
	while (read(0, &compare, 4) > 0)
	{
/*		if (compare != BACKSPACE)
		{
			get_cursor_position(&mini.col, &mini.row);
			check_row_flag(&mini);
		}*/
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
					parse_by_builtin(&mini);
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
