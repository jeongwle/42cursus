/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:17:11 by jeongwle          #+#    #+#             */
/*   Updated: 2021/06/22 17:30:40 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_by_input_subtwo(t_mini *mini)
{
	mini->semi_temp = mini->semi;
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
	free_command_list(mini);
}

void	parse_by_input_sub(t_mini *mini)
{
	char	*temp;
	int		i;

	i = 0;
	if (mini->make_history_flag)
	{
		temp = mini->curr->next->history;
		mini->make_history_flag = 0;
		if (mini->status > 255 && mini->status != 258)
			mini->status /= 256;
		while (ft_isspace(temp[i]))
			i++;
		if (!temp[i])
			return ;
		mini->semi = lexical_analyzer(temp, mini, mini->status);
		if (mini->semi)
		{
			parse_by_input_subtwo(mini);
			if (mini->word->fd_in == -1)
				mini->status = 1;
		}
		else
			mini->status = 258;
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
			mini->semi = NULL;
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
	{
		ft_putstr_fd("bash: ", 2);
		ft_putstr_fd(&word->argv[0][1], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
	}
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
