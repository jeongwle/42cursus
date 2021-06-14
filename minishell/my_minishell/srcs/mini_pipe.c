/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 12:17:15 by jeongwle          #+#    #+#             */
/*   Updated: 2021/06/14 20:24:46 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void	test(t_mini *mini)
{
	int i;
	t_list	*lst;
	int	size;

	i = 0;
	lst = mini->lst;
	size = ft_lstsize(lst);
	mini->pid = (pid_t *)malloc(sizeof(pid_t) * size);
	mini->fds = (int **)malloc(sizeof(int *) * size);
	while (size--)
	{
		mini->fds[size] = (int *)malloc(sizeof(int) * 2);
	}
	size = ft_lstsize(lst);
	while (i < ft_lstsize(mini->lst))
	{
		pipe(mini->fds[i]);
		mini->pid[i] = fork();
		if (mini->pid[i] == 0)
		{
			if (i != 0 && i != (size - 1))
			{
				dup2(mini->fds[i - 1][0], 0);
				dup2(mini->fds[i][1], 1);
			}
			else if (i == 0 && size != 1)
				dup2(mini->fds[i][1], 1);
			else if (i == (size - 1) && size != 1)
				dup2(mini->fds[i - 1][0], 0);
			if (i != 0 && i != (size - 1))
			{
				close(mini->fds[i - 1][1]);
				close(mini->fds[i][0]);
			}
			else if (i == 0 && size != 1)
				close(mini->fds[i][0]);
			else if (i == (size - 1) && size != 1)
				close(mini->fds[i - 1][1]);
			parse_by_builtin(mini, ((char **)lst->content));
			exit(0);
		}
		else
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
		i++;
		lst = lst->next;
	}
	i = 0;
	while (i < size)
	{
		waitpid(mini->pid[i], NULL, 0);
		i++;
	}
	while (size--)
		free(mini->fds[size]);
	free(mini->fds);
	free(mini->pid);
}
/*
void	test_pipe(t_mini *mini)
{
	int		fd1[2];
	int		fd2[2];
	pid_t	pid[3];
	int		status;

	pipe(fd1);
	pid[0] = fork();
	if (pid[0] == 0)
	{
		dup2(fd1[1], 1);
		close(fd1[0]);
		parse_by_builtin(mini);
		exit(0);
	}
	else
	{
		close(fd1[1]);
	}
	pipe(fd2);
	pid[1] = fork();
	if (pid[1] == 0)
	{
		dup2(fd1[0], 0);
		dup2(fd2[1], 1);
		close(fd1[1]);
		close(fd2[0]);
		mini->lst = mini->lst->next;
		parse_by_builtin(mini);
		exit(0);
	}
	else
	{
		close(fd2[1]);
		close(fd1[0]);
	}
	pid[2] = fork();
	if (pid[2] == 0)
	{
		dup2(fd2[0], 0);
		close(fd2[1]);
		mini->lst = mini->lst->next->next;
		parse_by_builtin(mini);
		exit(0);
	}
	else
	{
		close(fd2[0]);
		close(fd1[1]);
	}
	waitpid(pid[0], NULL, 0);
	waitpid(pid[1], NULL, 0);
	waitpid(pid[2], NULL, 0);
	return ;
}*/
