/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <jeongwle@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 21:10:39 by jeongwle          #+#    #+#             */
/*   Updated: 2021/05/28 01:48:20 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	mini_export_addback(t_mini *mini, t_export *new)
{
	t_export	*temp;

	temp = mini->exp;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	new->prev = temp;
}

void	sort_export(t_mini *mini)
{
	int			i;
	int			j;
	int			count;
	char		*temp;
	t_export	*curr;

	i = 0;
	count = mini_lstsize(mini->exp);
	while (i < count - 1)
	{
		curr = mini->exp;
		j = 0;
		while (j < count - i - 1)
		{
			if (ft_strcmp(curr->export_list, curr->next->export_list) > 0)
			{
				temp = curr->export_list;
				curr->export_list = curr->next->export_list;
				curr->next->export_list = temp;
			}
			curr = curr->next;
			j++;
		}
		i++;
	}
}

void	put_export_list(t_mini *mini)
{
	t_export	*curr;

	curr = mini->exp;
	while (curr)
	{
		if (curr->env_list)
			curr->export_list = ft_strdup(curr->env_list);
		curr = curr->next;
	}
}

int		check_already_sub(t_mini *mini, char **key_temp, t_export *curr, char *str)
{
	char	*value_temp;
	char	*temp;

	if (ft_strchr(str, '='))
	{
		temp = ft_strdup(str);
		if(*(ft_strchr(temp, '=') + 1))
			value_temp = ft_strdup(ft_strchr(temp, '=') + 1);
		free(temp);
	}
	else
		value_temp = NULL;
	if (value_temp)
	{
		free(curr->value);
		curr->value = ft_strdup(value_temp);
		free(curr->env_list);
		curr->env_list = ft_strjoin(curr->key, "=");
		temp = curr->env_list;
		curr->env_list = ft_strjoin(temp, value_temp);
		free(temp);
		free(value_temp);
		free(*key_temp);
		return (1);
	}
	else
		free(*key_temp);
	return (1);
}

int		check_already_exist(t_mini *mini, char *str)
{
	t_export	*curr;
	char		*key_temp;
	char		*temp;

	if (ft_strchr(str, '='))
	{
		temp = ft_strdup(str);
		*(ft_strchr(temp, '=')) = '\0';
		key_temp = ft_strdup(temp);
		free(temp);
	}
	else
		key_temp = ft_strdup(str);
	curr = mini->exp;
	while (curr)
	{
		if (curr->key && !ft_strcmp(key_temp, curr->key))
			return (check_already_sub(mini, &key_temp, curr, str));
		curr = curr->next;
	}
	free(key_temp);
	return (0);
}
