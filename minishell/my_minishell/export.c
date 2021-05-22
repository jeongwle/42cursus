/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 14:54:20 by jeongwle          #+#    #+#             */
/*   Updated: 2021/05/22 17:25:53 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_export_param(t_mini *mini, char *envp[], int *i)
{
	char	*temp;

	temp = ft_strdup("declare -x ");
	mini->exp = (t_export *)malloc(sizeof(t_export) * 1);
	if (!mini->exp)
		malloc_error();
	mini->exp->export_list = ft_strjoin(temp, envp[*i]);
	mini->exp->next = NULL;
	mini->exp->prev = NULL;
	(*i)++;
	free(temp);
	temp = NULL;
}

static void	mini_export_addback(t_mini *mini, t_export *new)
{
	t_export	*temp;

	temp = mini->exp;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	new->prev = temp;
}

static void	sort_export(t_mini *mini)
{
	int 		i;
	int 		j;
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
		//		printf("%s\n%s\n", curr->export_list, curr->next->export_list);
		//		printf("%d\n", ft_strcmp(curr->export_list, curr->next->export_list));
				temp = ft_strdup(curr->export_list);
				free(curr->export_list);
				curr->export_list = ft_strdup(curr->next->export_list);
				free(curr->next->export_list);
				curr->next->export_list = ft_strdup(temp);
				free(temp);
		//		printf("%s\n%s\n", curr->export_list, curr->next->export_list);
				curr = curr->next;
			}
			j++;
		}
		i++;
	}
}
t_export	*mini_export_new(char *str)
{
	t_export	*new;
	char		*temp;

	new = (t_export *)malloc(sizeof(t_export) * 1);
	if (!new)
		malloc_error();
	temp = ft_strdup("declare -x ");
	new->export_list = ft_strjoin(temp, str);
	new->next = NULL;
	free(temp);
	temp = NULL;
	return (new);
}

void		make_export_list(t_mini *mini, char *envp[])
{
	int			i;

	i = 0;
	init_export_param(mini, envp, &i);
	while (envp[i])
	{
		mini_export_addback(mini, mini_export_new(envp[i]));
		i++;
	}
	sort_export(mini);
}
