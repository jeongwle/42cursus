/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 12:53:08 by jeongwle          #+#    #+#             */
/*   Updated: 2021/05/20 09:21:53 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strndup(const char *s, int n)
{
	int		i;
	char	*res;

	i = 0;
	res = (char *)malloc(sizeof(char) * (n + 1));
	if (!res)
		return (NULL);
	while (i < n)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = 0;
	return (res);
}

void	ft_free(char **s)
{
	free(*s);
	*s = NULL;
}

void	clear_buf(t_mini *mini)
{
	int	i;

	i = 0;
	while (mini->buf[i])
	{
		mini->buf[i] = 0;
		i++;
	}
	mini->idx = 0;
}

void	head_clear(t_mini *mini)
{
	if (mini->head->history)
		ft_free(&mini->head->history);
	if (mini->head->temp)
		ft_free(&mini->head->temp);
	mini->head->flag = 0;
	mini->curr = mini->head;
}
