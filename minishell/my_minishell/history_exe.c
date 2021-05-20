/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_exe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <jeongwle@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 11:03:47 by jeongwle          #+#    #+#             */
/*   Updated: 2021/05/20 09:22:00 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ifn_head(t_mini *mini)
{
	mini->curr->flag = 1;
	if (!mini->curr->temp)
		mini->curr->temp = mini->curr->history;
	else
		mini->temp = mini->curr->history;
	mini->curr->history = ft_strjoin(mini->curr->history, mini->buf);
	if (mini->temp)
		ft_free(&mini->temp);
	clear_buf(mini);
}

void	if_head(t_mini *mini)
{
	if (mini->curr->temp)
		ft_free(&mini->curr->temp);
	if (mini->curr->history)
		mini->curr->temp = mini->curr->history;
	mini->curr->history = ft_strjoin(mini->curr->temp, mini->buf);
	if (mini->curr->temp)
		ft_free(&mini->curr->temp);
	clear_buf(mini);
}

void	make_history_lst(t_mini *mini)
{
	mini->buf[mini->idx] = 0;
	if (mini->curr->flag)
	{
		if (mini->curr->history && ft_strlen(mini->curr->history) != 0)
			mini_lstadd_middle(mini, mini_lstnew(mini->curr->history));
		if (mini->curr->history)
			ft_free(&mini->curr->history);
		if (mini->curr->temp)
		{
			mini->curr->history = ft_strdup(mini->curr->temp);
			ft_free(&mini->curr->temp);
		}
	}
	else if (mini->curr->history)
		mini_lstadd_middle(mini, mini_lstnew(mini->curr->history));
	clear_buf(mini);
	head_clear(mini);
}

void	if_history_modified(t_mini *mini)
{
	mini->curr->flag = 1;
	if (!mini->curr->temp)
		mini->curr->temp = mini->curr->history;
	else
		mini->temp = mini->curr->history;
	if (ft_strlen(mini->curr->history) != 0)
		mini->curr->history = ft_strndup(mini->curr->history,
				ft_strlen(mini->curr->history) - 1);
	if (mini->temp)
	{
		if (ft_strlen(mini->temp) == 0 && ft_strlen(mini->curr->history) == 0)
			mini->curr->history = ft_strdup("");
		free(mini->temp);
		mini->temp = NULL;
	}
}
