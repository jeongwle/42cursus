/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <jeongwle@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 11:48:11 by jeongwle          #+#    #+#             */
/*   Updated: 2021/06/02 21:54:53 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_already_sub_two(t_export *curr, char *value_temp)
{
	char	*temp;

	if (curr->value)
	{
		free(curr->value);
		curr->value = NULL;
	}
	if (value_temp)
		curr->value = ft_strdup(value_temp);
	free(curr->env_list);
	curr->env_list = ft_strjoin(curr->key, "=");
	temp = curr->env_list;
	if (curr->value)
	{
		curr->env_list = ft_strjoin(temp, curr->value);
		free(temp);
	}
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
		else
			value_temp = NULL;
		free(temp);
		check_already_sub_two(curr, value_temp);
	}
	if (value_temp)
		free(value_temp);
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
			free(temp);
			return (ft_strdup("error"));
		}
		*(ft_strchr(temp, '=')) = '\0';
		key_temp = ft_strdup(temp);
		free(temp);
	}
	else
		return (NULL);
	return (key_temp);
}

int		check_already_exist(t_mini *mini, char *str)
{
	t_export	*curr;
	char		*key_temp;
	char		*temp;

	key_temp = check_key(str);
	if (key_temp && !ft_strcmp("error", key_temp))
		return (0);
	if (key_temp && ft_strchr(key_temp, '+'))
		return (check_plus(mini, str, &key_temp));
	if (!key_temp)
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
