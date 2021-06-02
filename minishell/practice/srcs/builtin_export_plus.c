/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export_plus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <jeongwle@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 22:06:26 by jeongwle          #+#    #+#             */
/*   Updated: 2021/05/27 22:21:29 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		plus_sign(char *str)
{
	int	i;
	int	sign;

	i = 0;
	sign = 0;
	while (str[i])
	{
		if (str[i] == '+')
			sign++;
		i++;
	}
	if (sign == 1)
		return (1);
	return (0);
}

void	check_plus(t_mini *mini, char *str)
{
	char		*temp;
	char		*value_temp;
	char		*key_temp;
	t_export	*curr;

	curr = mini->exp;
	if (plus_sign(str))
	{
		temp = ft_strdup(str);
		value_temp = ft_strdup(ft_strchr(temp, '=') + 1);
		*(ft_strchr(temp, '+')) = '\0';
		key_temp = ft_strdup(temp);
		free(temp);
		while (curr)
		{
			if (!ft_strcmp(curr->key, key_temp))
			{
				temp = curr->value;
				curr->value = ft_strjoin(temp, value_temp);
			}
			curr = curr->next;
		}
		free(temp);
		free(value_temp);
		free(key_temp);
	}
}
