/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 11:50:06 by jeongwle          #+#    #+#             */
/*   Updated: 2021/06/03 13:24:25 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	use_execve(t_mini *mini, char **str)
{
	int	i;

	i = 0;
	mini->pid = 0;
	mini->status = 0;
	mini->pid = fork();
	if (mini->pid != 0)
	{
		wait(&mini->status);
		return ;
	}
	else
		execve(ft_strjoin("/bin/", str[0]), str, NULL);
}
