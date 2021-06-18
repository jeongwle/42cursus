/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_execve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 11:50:06 by jeongwle          #+#    #+#             */
/*   Updated: 2021/06/18 14:20:12 by jeongwle         ###   ########.fr       */
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

	if (str && !ft_strcmp("minishell", str))
		return (NULL);
	temp = ft_strjoin(path, "/");
	res = ft_strjoin(temp, str);
	ft_free(&temp);
	return (res);
}

int		execute_execve(t_mini *mini, char **str, char **env)
{
	char	**path;
	char	*res;
	char	*execve_param;
	int		i;
	int		return_value;

	i = 0;
	path = get_path_value(mini);
	return_value = -1;
	while (path[i] && return_value == -1)
	{
		execve_param = make_execve_param(str[0], path[i]);
		return_value = execve(execve_param, str, env);
		ft_free_double(&execve_param, &path[i]);
		i++;
	}
	ft_free(path);
	if (return_value == -1)
	{
		res = getcwd(NULL, 0);
		execve_param = make_execve_param(str[0], res);
		return_value = execve(execve_param, str, env);
		ft_free_double(&execve_param, &res);
	}
	return (return_value);
}

char	**make_env(t_mini *mini)
{
	char		**res;
	int			i;
	t_export	*curr;

	res = (char **)malloc(sizeof(char *) * (mini_lstsize(mini->exp) + 1));
	if (!res)
		return (NULL);
	i = 0;
	curr = mini->exp;
	while (curr)
	{
		res[i] = ft_strdup(curr->env_list);
		curr = curr->next;
		i++;
	}
	res[i] = 0;
	return (res);
}

void	use_execve(t_mini *mini, char **str)
{
	char	**env;
	int		res;

	env = make_env(mini);
	res = execute_execve(mini, str, env);
	if (res == -1)
	{
		write(1, "bash: ", 6);
		ft_putstr_fd(str[0], 1);
		write(1, ": command not found\n", 20);
		exit(127);
	}
}
