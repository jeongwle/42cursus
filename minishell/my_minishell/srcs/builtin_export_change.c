/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export_change.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <jeongwle@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 21:41:55 by jeongwle          #+#    #+#             */
/*   Updated: 2021/05/28 01:00:10 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	change_oldpwd(t_mini *mini, char *buf)
{
	t_export	*curr;
	char		*temp;

	curr = mini->exp;
	while (curr)
	{
		if (curr->key && !ft_strcmp("OLDPWD", curr->key))
		{
			if (curr->value)
				free(curr->value);
			curr->value = ft_strdup(buf);
			free(curr->env_list);
			temp = ft_strjoin(curr->key, "=");
			curr->env_list = ft_strjoin(temp, curr->value);
			free(temp);
		}
		curr = curr->next;
	}
}

void	change_pwd(t_mini *mini, char *buf)
{
	t_export	*curr;
	char		*temp;

	curr = mini->exp;
	while (curr)
	{
		if (curr->key && !ft_strcmp("PWD", curr->key))
		{
			if (curr->value)
				free(curr->value);
			curr->value = ft_strdup(buf);
			free(curr->env_list);
			temp = ft_strjoin(curr->key, "=");
			curr->env_list = ft_strjoin(temp, curr->value);
			free(temp);
		}
		curr = curr->next;
	}
}
/*
void	delete_env_list(t_export *curr)
{
	if (curr->prev && curr->next)
	{
		curr->prev->next = curr->next;
		curr->next->prev = curr->prev;
	}
	else if (curr->prev && !curr->next)
		curr->prev->next = NULL;
	else if (!curr->prev && curr->next)
		curr->next->prev = NULL;
	free(curr);
}*/
/*
void	delete_oldpwd(t_mini *mini)
{
	t_export	*curr;

	curr = mini->exp;
	while (curr)
	{
		if (curr->key && !ft_strcmp("OLDPWD", curr->key))
		{
			if (curr->value)
			{
				free(curr->value);
				curr->value = NULL;
			}
			*(ft_strchr(curr->env_list, '=')) = '\0';
			return ;
		}
		curr = curr->next;
	}
	if (!curr)
		add_export_list(mini, "OLDPWD");
}*/

void	delete_oldpwd(t_mini *mini)
{
	t_export	*curr;

	curr = mini->exp;
	while (curr)
	{
		if (curr->key && !ft_strcmp("OLDPWD", curr->key))
		{
			if (curr->value)
				ft_free(&curr->value);
			if (ft_strchr(curr->env_list, '='))
				*(ft_strchr(curr->env_list, '=')) = '\0';
			return ;
		}
		curr = curr->next;
	}
	if (!curr)
		add_export_list(mini, "OLDPWD");
}
