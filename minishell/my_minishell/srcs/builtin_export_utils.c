/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 15:53:06 by jeongwle          #+#    #+#             */
/*   Updated: 2021/05/26 16:28:50 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_export_param(t_mini *mini, char *envp[], int *i)
{
	char	*temp;

	temp = ft_strdup("declare -x ");
	mini->exp = (t_export *)malloc(sizeof(t_export) * 1);
	if (!mini->exp)
		malloc_error();
	mini->exp->export_list = ft_strjoin(temp, envp[*i]);
	if (ft_strchr(envp[*i], '='))
		mini->exp->env_list = ft_strdup(envp[*i]);
	else
		mini->exp->env_list = NULL;
	mini->exp->next = NULL;
	mini->exp->prev = NULL;
	(*i)++;
	free(temp);
	temp = NULL;
}

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

void	make_double_quotes(t_export *new)
{
	char	*temp;
	char	*substr_temp;
	char	*quote_temp;
	size_t	new_len;
	size_t	substr_len;

	new_len = ft_strlen(new->export_list);
	temp = ft_strchr(new->export_list, '=');
	substr_len = ft_strlen(temp + 1);
	substr_temp = ft_substr(new->export_list, new_len - substr_len, substr_len);
	quote_temp = ft_strdup("\"");
	*(temp + 1) = '\0';
	temp = new->export_list;
	new->export_list = ft_strjoin(temp, quote_temp);
	free(temp);
	temp = new->export_list;
	new->export_list = ft_strjoin(temp, substr_temp);
	free(temp);
	temp = new->export_list;
	new->export_list = ft_strjoin(temp, quote_temp);
	free(temp);
	free(substr_temp);
	free(quote_temp);
}

int		check_already_exist(t_mini *mini, char *str)
{
	t_export	*curr;

	curr = mini->exp;
	while (curr)
	{
		if (curr->export_list &&
			(!ft_strcmp(str, curr->export_list) ||
			ft_strcmp(str, curr->export_list) == -61))
			return (-1);
		curr = curr->next;
	}
	return (0);
}
