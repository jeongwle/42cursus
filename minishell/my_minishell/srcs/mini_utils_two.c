/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_utils_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 16:45:42 by jeongwle          #+#    #+#             */
/*   Updated: 2021/06/18 00:18:15 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		mini_lstsize(t_export *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

char	*find_env(t_mini *mini, char *key)
{
	t_export	*curr;

	curr = mini->exp;
	while (curr)
	{
		if (curr->key && !ft_strcmp(key, curr->key))
		{
			if (curr->value)
				return (ft_strdup(curr->value));
			else
				return (NULL);
		}
		curr = curr->next;
	}
	return (NULL);
}

void	ft_free_double(char **s1, char **s2)
{
	free(*s1);
	*s1 = NULL;
	free(*s2);
	*s2 = NULL;
}
