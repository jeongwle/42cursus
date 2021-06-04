/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <jeongwle@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 11:48:11 by jeongwle          #+#    #+#             */
/*   Updated: 2021/06/04 16:45:24 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_already_sub_two(t_export *curr, char *value_temp)
{
	char	*temp;

	if (curr->value)
		ft_free(&curr->value);
	if (value_temp)
		curr->value = ft_strdup(value_temp);
	ft_free(&curr->env_list);
	curr->env_list = ft_strjoin(curr->key, "=");
	temp = curr->env_list;
	if (curr->value)
	{
		curr->env_list = ft_strjoin(temp, curr->value);
		ft_free(&temp);
	}
}

int		check_already_sub(t_export *curr, char *str)
{
	char	*value_temp;
	char	*temp;

	value_temp = NULL;
	if (ft_strchr(str, '='))
	{
		temp = ft_strdup(str);
		if (*(ft_strchr(temp, '=') + 1))
			value_temp = ft_strdup(ft_strchr(temp, '=') + 1);
		else
			value_temp = NULL;
		ft_free(&temp);
		check_already_sub_two(curr, value_temp);
	}
	if (value_temp)
		ft_free(&value_temp);
	return (1);
}

char	*check_key(char *str)
{
	char	*temp;
	char	*key_temp;

	if (ft_strchr(str, '='))
	{
		temp = ft_strdup(str);
		if (temp[0] == '=')
		{
			ft_free(&temp);
			return (ft_strdup("error"));
		}
		*(ft_strchr(temp, '=')) = '\0';
		key_temp = ft_strdup(temp);
		ft_free(&temp);
	}
	else
		return (NULL);
	return (key_temp);
}

int		check_already_exist(t_mini *mini, char *str)
{
	t_export	*curr;
	char		*key_temp;

	key_temp = check_key(str);
	if (key_temp && !ft_strcmp("error", key_temp))
		ft_free(&key_temp);
	else if (key_temp && ft_strchr(key_temp, '+'))
		return (check_plus(mini, str, &key_temp));
	else if (!key_temp)
		key_temp = ft_strdup(str);
	if (key_temp && !ft_strcmp("error", key_temp))
		ft_free(&key_temp);
	curr = mini->exp;
	while (curr && key_temp)
	{
		if (curr->key && !ft_strcmp(key_temp, curr->key))
		{
			ft_free(&key_temp);
			return (check_already_sub(curr, str));
		}
		curr = curr->next;
	}
	if (key_temp)
		ft_free(&key_temp);
	return (0);
}
