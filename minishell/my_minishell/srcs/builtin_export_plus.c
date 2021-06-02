/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export_plus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <jeongwle@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 22:06:26 by jeongwle          #+#    #+#             */
/*   Updated: 2021/06/02 22:15:27 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		plus_sign(char *str)
{
	int i;
	int plus;

	i = 0;
	plus = 0;
	while (str[i])
	{
		if (str[i] == '+')
			plus++;
		i++;
	}
	if (plus == 1)
		return (1);
	return (0);
}

void	check_plus_sub_two(t_export *curr, char *value_temp)
{
	char	*temp;

	if (curr->value)
	{
		temp = curr->value;
		curr->value = ft_strjoin(temp, value_temp);
		free(temp);
	}
	else
		curr->value = ft_strdup(value_temp);
	free(curr->env_list);
	curr->env_list = ft_strjoin(curr->key, "=");
	temp = curr->env_list;
	curr->env_list = ft_strjoin(temp, curr->value);
	free(temp);
}

int		check_plus_sub(t_export *curr, char *str)
{
	char	*value_temp;
	char	*temp;

	temp = ft_strdup(str);
	if (*(ft_strchr(temp, '=') + 1))
		value_temp = ft_strdup(ft_strchr(temp, '=') + 1);
	else
		value_temp = NULL;
	free(temp);
	if (value_temp)
	{
		check_plus_sub_two(curr, value_temp);
		free(value_temp);
	}
	return (1);
}

int		check_plus(t_mini *mini, char *str, char **temp)
{
	char		*key_temp;
	t_export	*curr;

	if (plus_sign(*temp))
	{
		*(ft_strchr(*temp, '+')) = '\0';
		key_temp = ft_strdup(*temp);
		free(*temp);
	}
	else
		free(*temp);
	curr = mini->exp;
	while (curr)
	{
		if (curr->key && !ft_strcmp(key_temp, curr->key))
		{
			free(key_temp);
			return (check_plus_sub(curr, str));
		}
		curr = curr->next;
	}
	if (key_temp)
		free(key_temp);
	return (0);
}
