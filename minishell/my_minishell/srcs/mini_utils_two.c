/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_utils_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 16:45:42 by jeongwle          #+#    #+#             */
/*   Updated: 2021/06/21 16:48:43 by jeongwle         ###   ########.fr       */
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

void	free_cmd_list_sub(t_list **temp, t_list **param)
{
	*temp = *param;
	*param = (*param)->next;
	free(*temp);
	*temp = NULL;
}

void	free_command_list(t_mini *mini)
{
	t_list	*curr;
	t_list	*pipe;
	t_word	*word;
	t_list	*temp;

	if (mini->semi_temp)
	{
		curr = mini->semi_temp;
		word = ((t_list *)curr->content)->content;
		while (curr)
		{
			if (curr->content)
				pipe = curr->content;
			if (pipe)
			{
				while (pipe)
					free_cmd_list_sub(&temp, &pipe);
			}
			free_cmd_list_sub(&temp, &curr);
		}
	}
	while (--mini->word_cnt >= 0)
		free_split(word[mini->word_cnt].argv);
	free(word);
	word = NULL;
}
