/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_execve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 11:50:06 by jeongwle          #+#    #+#             */
/*   Updated: 2021/06/22 17:07:28 by jeongwle         ###   ########.fr       */
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
			return (ft_split(curr->value, ':'));
		curr = curr->next;
	}
	return (NULL);
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

int		execute_execve(t_mini *mini, char **str, char **env, int i)
{
	char	**path;
	char	*res;
	char	*execve_param;

	path = get_path_value(mini);
	mini->return_value = execve(str[0], str, env);
	if (path)
	{
		while (path[i] && mini->return_value == -1)
		{
			execve_param = make_execve_param(str[0], path[i]);
			mini->return_value = execve(execve_param, str, env);
			ft_free_double(&execve_param, &path[i]);
			i++;
		}
		ft_free(path);
	}
	if (mini->return_value == -1)
	{
		res = getcwd(NULL, 0);
		execve_param = make_execve_param(str[0], res);
		mini->return_value = execve(execve_param, str, env);
		ft_free_double(&execve_param, &res);
	}
	return (mini->return_value);
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
	char	**path;

	env = make_env(mini);
	res = execute_execve(mini, str, env, 0);
	path = get_path_value(mini);
	if (res == -1)
	{
		write(1, "bash: ", 6);
		ft_putstr_fd(str[0], 1);
		if (str[0][0] == '/' || !path)
			ft_putstr_fd(": No such file or directory\n", 1);
		else
			write(1, ": command not found\n", 20);
		exit(127);
	}
}
