/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 12:17:15 by jeongwle          #+#    #+#             */
/*   Updated: 2021/06/11 16:33:26 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	test_pipe(t_mini *mini)
{
	int		fd[2];

	pipe(fd);
	mini->pid = fork();
	if (mini->pid == 0) // wktlr
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
	}
	else //qnah
	{
		close(fd[1]);
		mini->lst = mini->lst->next;
	}
}
