/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 14:54:20 by jeongwle          #+#    #+#             */
/*   Updated: 2021/05/22 20:56:31 by jeongwle         ###   ########.fr       */
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

void		make_double_quotes(t_export *new)
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

t_export	*mini_export_new(char *str)
{
	t_export	*new;
	char		*temp;

	new = (t_export *)malloc(sizeof(t_export) * 1);
	if (!new)
		malloc_error();
	temp = ft_strdup("declare -x ");
	new->export_list = ft_strjoin(temp, str);
	if (ft_strchr(new->export_list, '='))
	{
		make_double_quotes(new);
		new->env_list = ft_strdup(str);
	}
	else
		new->env_list = NULL;
	new->next = NULL;
	free(temp);
	temp = NULL;
	return (new);
}

void		make_export_list(t_mini *mini, char *envp[])
{
	int			i;
	t_export	*temp;

	i = 0;
	init_export_param(mini, envp, &i);
	while (envp[i])
	{
		mini_export_addback(mini, mini_export_new(envp[i]));
		i++;
	}
	sort_export(mini);
	temp = mini->exp;
	while (temp)
	{
		printf("%s\n", temp->export_list);
		temp = temp->next;
	}
}
