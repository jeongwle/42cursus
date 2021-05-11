/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 13:20:45 by jeongwle          #+#    #+#             */
/*   Updated: 2021/05/11 19:46:50 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lst	*mini_lstnew(char *buf)
{
	t_lst *new;

	new = (t_lst *)malloc(sizeof(t_lst) * 1);
	if (!new)
		return (NULL);
	new->history = ft_strdup(buf);
	new->flag = 0;
	new->temp = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	mini_lstadd_middle(t_mini *mini, t_lst *new)
{
	mini->head->next->prev = new;
	new->next = mini->head->next;
	new->prev = mini->head;
	mini->head->next = new;
	mini->curr = mini->head;
}

void	init_history_param(t_mini *mini)
{
	mini->head = (t_lst *)malloc(sizeof(t_lst) * 1);
	if (!mini->head)
		malloc_error();
	mini->tail = (t_lst *)malloc(sizeof(t_lst) * 1);
	if (!mini->tail)
		malloc_error();
	mini->curr = (t_lst *)malloc(sizeof(t_lst) * 1);
	if (!mini->curr)
		malloc_error();
	mini->head->next = mini->tail;
	mini->head->prev = NULL;
	mini->tail->next = NULL;
	mini->tail->prev = mini->head;
	mini->head->history = 0;
	mini->tail->history = 0;
	mini->curr->history = 0;
	mini->curr->flag = 0;
	mini->head->flag = 0;
	mini->tail->flag = 0;
	mini->curr->temp = 0;
	mini->head->temp = 0;
	mini->tail->temp = 0;
}