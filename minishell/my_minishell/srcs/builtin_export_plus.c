/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export_plus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:42:36 by jeongwle          #+#    #+#             */
/*   Updated: 2021/05/27 14:00:18 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		plus_sign(char *str)
{
	int i;
	int sign;

	i = 0;
	sign = 0;
	while (str[i])
	{
		if (str[i] == '+')
			sign = 1;
		i++;
	}
	if (sign == 1)
		return (1);
	return (0);
}

void	check_plus(t_mini *mini, char *str)
{
	char		*temp;
	t_export	*curr;

	curr = mini->exp;
	if (plus_sign(str))
	{
		temp = ft_strjoin("declare -x ", str);
		*(ft_strchr(temp, '=')) = '\0';
		while (curr)
		{
			if (curr->export_list && (ft_strcmp(temp, curr->export_list) ||
				ft_strcmp(temp, curr->export_list == -61)))
				break;
			curr = curr->next;
		}
		if (curr->value)
	}
}
