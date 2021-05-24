/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 09:54:33 by jeongwle          #+#    #+#             */
/*   Updated: 2021/05/20 10:02:52 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	history_lst_clear(t_mini *mini)
{
	t_lst	*temp;

	mini->curr = mini->head;
	while (mini->curr)
	{
		if (mini->curr->history)
			ft_free(&mini->curr->history);
		if (mini->curr->temp)
			ft_free(&mini->curr->temp);
		temp = mini->curr;
		mini->curr = mini->curr->next;
		free(temp);
	}
}
