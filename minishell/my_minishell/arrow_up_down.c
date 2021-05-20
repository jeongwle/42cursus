/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow_up_down.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 15:05:20 by jeongwle          #+#    #+#             */
/*   Updated: 2021/05/20 09:21:23 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	arrow_up(t_mini *mini)
{
	if (mini->curr->next && mini->curr->next->history)
	{
		delete_prev();
		mini->curr = mini->curr->next;
		write(1, mini->curr->history, ft_strlen(mini->curr->history));
	}
}

void	arrow_down(t_mini *mini)
{
	if (mini->curr->prev && mini->curr->prev->history)
	{
		delete_prev();
		mini->curr = mini->curr->prev;
		write(1, mini->curr->history, ft_strlen(mini->curr->history));
	}
	else if (mini->curr != mini->head)
	{
		mini->curr = mini->curr->prev;
		delete_prev();
	}
}

void	arrow_up_down(t_mini *mini, long long int compare)
{
	if (compare == ARROWUP)
		arrow_up(mini);
	else
		arrow_down(mini);
}
