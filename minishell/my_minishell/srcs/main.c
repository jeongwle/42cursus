/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 13:16:04 by jeongwle          #+#    #+#             */
/*   Updated: 2021/06/17 17:04:40 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_mini	g_mini;

void	parse_by_builtin_sub(t_mini *mini, char **str, t_word *word)
{
	if (!ft_strcmp("pwd", str[0]))
		pwd();
	else if (!ft_strcmp("cd", str[0]))
		cd(mini, str[1]);
	else if (!ft_strcmp("export", str[0]))
		check_export_param(mini, str);
	else if (!ft_strcmp("env", str[0]))
		print_env(mini);
	else if (!ft_strcmp("unset", str[0]))
		unset(mini, str);
	else if (!ft_strcmp("exit", str[0]))
		mini_exit(mini, str);
	else if (!ft_strcmp("echo", str[0]))
		ft_echo(str);
	else if (word->fd_in == -1)
		printf("bash: %s: No such file or directory\n", &word->argv[0][1]);
	else
		use_execve(mini, str);
}

void	parse_by_builtin(t_mini *mini, char **str, t_word *word)
{
	int	std_fd[2];

	pipe(std_fd);
	dup2(1, std_fd[1]);
	dup2(0, std_fd[0]);
	if (word->fd_in > 0)
		dup2(word->fd_in, 0);
	if (word->fd_out > 0)
		dup2(word->fd_out, 1);
	if (str)
		parse_by_builtin_sub(mini, str, word);
	dup2(std_fd[1], 1);
	dup2(std_fd[0], 0);
}

void	init_mini(t_mini *mini)
{
	mini->idx = 0;
	mini->pid = 0;
	mini->status = 0;
	mini->temp = NULL;
	mini->atoi_flag = 0;
	mini->make_history_flag = 0;
	store_present_term(mini);
	term_set();
	init_history_param(mini);
}

int		is_builtin(char **str)
{
	if (str)
	{
		if (!ft_strcmp("pwd", str[0]))
			return (1);
		else if (!ft_strcmp("cd", str[0]))
			return (1);
		else if (!ft_strcmp("export", str[0]))
			return (1);
		else if (!ft_strcmp("env", str[0]))
			return (1);
		else if (!ft_strcmp("unset", str[0]))
			return (1);
		else if (!ft_strcmp("exit", str[0]))
			return (1);
		else if (!ft_strcmp("echo", str[0]))
			return (1);
	}
	return (0);
}

void	parse_by_input_sub(t_mini *mini)
{
	if (mini->make_history_flag)
	{
		mini->make_history_flag = 0;
		mini->semi = lexical_analyzer(mini->curr->next->history, mini, 0);
		if (mini->semi)
		{
			mini->pipe = mini->semi->content;
			mini->word = mini->pipe->content;
			if (!mini->pipe->next && is_builtin(mini->word->argv))
				parse_by_builtin(mini, mini->word->argv, mini->word);
			else
				is_pipe(mini);
			while (mini->semi->next)
			{
				mini->semi = mini->semi->next;
				mini->pipe = mini->semi->content;
				mini->word = mini->pipe->content;
				if (!mini->pipe->next && is_builtin(mini->word->argv))
					parse_by_builtin(mini, mini->word->argv, mini->word);
				else
					is_pipe(mini);
			}
		}
	}
}

void	parse_by_input(t_mini *mini, long long int *compare)
{
	if (*compare == BACKSPACE)
		delete_end(mini);
	else if (*compare == ARROWUP || *compare == ARROWDOWN)
		arrow_up_down(mini, *compare);
	else
	{
		write(1, compare, 1);
		if (*compare == '\n')
		{
			make_history_lst(mini);
			parse_by_input_sub(mini);
			write(1, "minishell > ", 12);
		}
		else
		{
			mini->buf[mini->idx] = *compare;
			(mini->idx)++;
			if (mini->curr->history && mini->curr != mini->head)
				ifn_head(mini);
			else if (mini->curr == mini->head)
				if_head(mini);
		}
	}
	*compare = 0;
}

int		main(int argc, char *argv[], char *envp[])
{
	long long int	compare;

	argc = 0;
	argv = 0;
	compare = 0;
	init_mini(&g_mini);
	make_export_list(&g_mini, envp);
	signal(SIGINT, (void *)signal_handler);
	signal(SIGQUIT, (void *)signal_handler);
	write(1, "minishell > ", 12);
	while (read(0, &compare, 4) > 0)
	{
		if (compare == '\t' || compare == ARROWLEFT || compare == ARROWRIGHT)
		{
			compare = 0;
			continue ; 
		}
		else if (compare == '\n')
			change_term(&g_mini);
		else if (compare == 4)
		{
			//frefre inisfree
			if (!g_mini.curr->history || !*(g_mini.curr->history))
			{
				ft_putstr_fd("exit\n", 1);
				exit(0);
			}
			else
			{
				compare = 0;
				continue ;
			}
		}
		parse_by_input(&g_mini, &compare);
		term_set();
	}
}
