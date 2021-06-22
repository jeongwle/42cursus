/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:33:49 by jeongwle          #+#    #+#             */
/*   Updated: 2021/06/22 16:43:41 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_export	*find_curr_value(t_mini *mini)
{
	t_export	*curr;

	curr = mini->exp;
	while (curr)
	{
		if (curr->key && !ft_strcmp("PWD", curr->key))
			return (curr);
		curr = curr->next;
	}
	return (NULL);
}

t_export	*find_old_value(t_mini *mini)
{
	t_export	*curr;

	curr = mini->exp;
	while (curr)
	{
		if (curr->key && !ft_strcmp("OLDPWD", curr->key))
			return (curr);
		curr = curr->next;
	}
	return (NULL);
}

void		reverse_old_curr(t_mini *mini)
{
	t_export	*temp;
	char		*old_temp;
	char		*curr_temp;

	temp = find_old_value(mini);
	if (temp && temp->value)
	{
		old_temp = ft_strdup(temp->value);
		temp = find_curr_value(mini);
		if (temp && temp->value)
		{
			curr_temp = ft_strdup(temp->value);
			change_oldpwd(mini, curr_temp);
			change_pwd(mini, old_temp);
			chdir(old_temp);
			printf("%s\n", old_temp);
			ft_free(&old_temp);
			ft_free(&curr_temp);
		}
		else
		{
			free(old_temp);
			return ;
		}
	}
}

void		cd(t_mini *mini, char *path)
{
	char	*buf;
	int		res;

	if (path && !ft_strcmp("-", path))
	{
		reverse_old_curr(mini);
		return ;
	}
	buf = getcwd(NULL, 0);
	res = chdir(path);
	if (!res)
	{
		change_oldpwd(mini, buf);
		free(buf);
		buf = getcwd(NULL, 0);
		change_pwd(mini, buf);
	}
	else
	{
		if (mini->pipe->next)
			dup2(2, 1);
		printf("bash: cd: %s: %s\n", path, strerror(errno));
		mini->status = 1;
	}
	free(buf);
}
