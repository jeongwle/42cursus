/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <jeongwle@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 02:02:43 by jeongwle          #+#    #+#             */
/*   Updated: 2021/06/18 15:53:00 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	if (curr->key)
		ft_free(&curr->key);
	if (curr->value)
		ft_free(&curr->value);
	if (curr->env_list)
		ft_free(&curr->env_list);
	free(curr);
}

void	find_exist(t_mini *mini, char *str)
{
	t_export	*curr;

	curr = mini->exp;
	while (curr)
	{
		if (curr->key && !ft_strcmp(str, curr->key))
		{
			delete_env_list(curr);
			return ;
		}
		curr = curr->next;
	}
}

void	unset(t_mini *mini, char **str)
{
	int	i;
	int	res;

	i = 1;
	while (str[i])
	{
		res = check_argument(str[i], 'u');
		if (res == 1)
		{
			mini->status = 1;
			return ;
		}
		find_exist(mini, str[i]);
		i++;
	}
	mini->status = 0;
}
