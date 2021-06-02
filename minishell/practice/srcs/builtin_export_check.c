/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <jeongwle@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 11:48:11 by jeongwle          #+#    #+#             */
/*   Updated: 2021/05/28 11:52:10 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_already_sub_two(t_export *curr, char *value_temp)
{
	char	*temp;

	free(curr->value);
	curr->value = ft_strdup(value_temp);
	free(curr->env_list);
	curr->env_list = ft_strjoin(curr->key, "=");
	temp = curr->env_list;
	curr->env_list = ft_strjoin(temp, value_temp);
	free(temp);
}

int		check_already_sub(t_export *curr, char *str)
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
		check_already_sub_two(curr, value_temp);
		free(value_temp);
		return (1);
	}
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
		{
			free(key_temp);
			return (check_already_sub(curr, str));
		}
		curr = curr->next;
	}
	free(key_temp);
	return (0);
}
