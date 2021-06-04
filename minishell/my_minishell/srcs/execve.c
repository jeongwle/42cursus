/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 11:50:06 by jeongwle          #+#    #+#             */
/*   Updated: 2021/06/04 18:55:43 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_path_value(t_mini *mini)
{
	t_export	*curr;

	curr = mini->exp;
	while (curr)
	{
		if (curr->key && !ft_strcmp("PATH", curr->key))
			break ;
		curr = curr->next;
	}
	return (ft_split(curr->value, ':'));
}

char	*make_execve_param(char *str, char *path)
{
	char	*temp;
	char	*res;

	temp = ft_strjoin(path, "/");
	res = ft_strjoin(temp, str);
	ft_free(&temp);
	return (res);
}

void	use_execve(t_mini *mini, char **str)
{
	char	**path;
	int		i;
	char	*execve_param;

	i = 0;
	mini->pid = 0;
	mini->status = 0;
	mini->pid = fork();
	path = get_path_value(mini);
	if (mini->pid != 0)
	{
		wait(&mini->status);
		return ;
	}
	else
	{
		while (path[i])
		{
			execve_param = make_execve_param(str[0], path[i]);
			execve(execve_param, str, NULL);
			ft_free(&execve_param);
			ft_free(&path[i]);
			i++;
		}
		ft_free(path);
		exit(0);
	}
}
