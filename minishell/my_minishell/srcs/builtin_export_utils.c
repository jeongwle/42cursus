/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <jeongwle@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 21:10:39 by jeongwle          #+#    #+#             */
/*   Updated: 2021/05/28 11:50:00 by jeongwle         ###   ########.fr       */
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
