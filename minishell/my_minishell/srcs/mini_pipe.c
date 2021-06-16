/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 12:17:15 by jeongwle          #+#    #+#             */
/*   Updated: 2021/06/16 18:25:56 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_pipe_param(t_mini *mini, int *size)
{
	int		i;
	t_list	*lst;

	lst = mini->pipe;
	i = ft_lstsize(lst);
	*size = i;
	mini->pid = (pid_t *)malloc(sizeof(pid_t) * i);
	if (!mini->pid)
		return ;
	mini->fds = (int **)malloc(sizeof(int *) * i);
	if (!mini->fds)
		return ;
	while (i--)
		mini->fds[i] = (int *)malloc(sizeof(int) * 2);
}

void	child_process(t_mini *mini, int i, int size, t_list *lst)
{
	t_word *word;

	word = lst->content;
	if (i != 0 && i != (size - 1))
	{
		if (word->fd_in < 0)
			dup2(mini->fds[i - 1][0], 0);
		if (word->fd_out < 0)
			dup2(mini->fds[i][1], 1);
		close(mini->fds[i - 1][1]);
		close(mini->fds[i][0]);
	}
	else if (i == 0 && size != 1)
	{
		if (word->fd_out < 0)
			dup2(mini->fds[i][1], 1);
		close(mini->fds[i][0]);
	}
	else if (i == (size - 1) && size != 1)
	{
		if (word->fd_in < 0)
			dup2(mini->fds[i - 1][0], 0);
		close(mini->fds[i - 1][1]);
	}
//	parse_by_builtin(mini, ((t_word *)lst->content)->argv);
	parse_by_builtin(mini, word->argv, word);
	exit(0);
}

void	parent_process(t_mini *mini, int i, int size)
{
	if (i != 0 && i != (size - 1))
	{
		close(mini->fds[i - 1][0]);
		close(mini->fds[i][1]);
	}
	else if (i == 0 && size != 1)
		close(mini->fds[i][1]);
	else if (i == (size - 1) && size != 1)
		close(mini->fds[i - 1][0]);
}

void	free_pid_fd(t_mini *mini, int size)
{
	while (size--)
		free(mini->fds[size]);
	free(mini->fds);
	free(mini->pid);
}

void	is_pipe(t_mini *mini)
{
	int		i;
	t_list	*lst;
	int		size;

	i = -1;
	lst = mini->pipe;
	init_pipe_param(mini, &size);
	while (++i < size)
	{
		pipe(mini->fds[i]);
		mini->pid[i] = fork();
		if (mini->pid[i] == 0)
			child_process(mini, i, size, lst);
		else
			parent_process(mini, i, size);
		lst = lst->next;
	}
	i = -1;
	while (++i < size)
		waitpid(mini->pid[i], NULL, 0);
	free_pid_fd(mini, size);
}
