/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export_print.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <jeongwle@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 22:31:05 by jeongwle          #+#    #+#             */
/*   Updated: 2021/06/03 02:36:22 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		print_export(t_export *curr)
{
	char	*temp;
	char	*value_temp;

	temp = ft_strchr(curr->export_list, '=');
	if (temp && *(temp + 1))
	{
		value_temp = ft_strdup(temp + 1);
		*(temp) = '\0';
		printf("declare -x %s=\"%s\"\n", curr->export_list, value_temp);
		ft_free(&value_temp);
	}
	else if (temp)
	{
		*(temp) = '\0';
		printf("declare -x %s=\"\"\n", curr->export_list);
	}
	else
		printf("declare -x %s\n", curr->export_list);
}

void		print_env(t_mini *mini)
{
	t_export	*curr;

	curr = mini->exp;
	while (curr)
	{
		if (curr->key)
		{
			if (ft_strchr(curr->env_list, '=') && curr->value)
				printf("%s=%s\n", curr->key, curr->value);
			else if (ft_strchr(curr->env_list, '='))
				printf("%s=\n", curr->key);
		}
		curr = curr->next;
	}
}
