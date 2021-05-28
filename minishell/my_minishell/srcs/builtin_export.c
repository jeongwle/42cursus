/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <jeongwle@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 19:46:45 by jeongwle          #+#    #+#             */
/*   Updated: 2021/05/28 11:30:35 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_export	*mini_export_new(char *str)
{
	t_export	*new;
	char		*temp;

	new = (t_export *)malloc(sizeof(t_export) * 1);
	if (!new)
		malloc_error();
	new->env_list = ft_strdup(str);
	if (ft_strchr(str, '='))
	{
		temp = ft_strdup(str);
		if (*(ft_strchr(new->env_list, '=') + 1))
			new->value = ft_strdup(ft_strchr(new->env_list, '=') + 1);
		else
			new->value = NULL;
		*(ft_strchr(temp, '=')) = '\0';
		new->key = ft_strdup(temp);
		free(temp);
	}
	else
	{
		new->key = ft_strdup(str);
		new->value = NULL;
	}
	new->next = NULL;
	return (new);
}

void		make_export_list(t_mini *mini, char *envp[])
{
	int	i;

	i = 0;
	init_export_param(mini, envp, &i);
	while (envp[i])
	{
		add_export_list(mini, envp[i]);
		i++;
	}
	delete_oldpwd(mini);
}

void		add_export_list(t_mini *mini, char *str)
{
	mini_export_addback(mini, mini_export_new(str));
}

void		check_export_param(t_mini *mini, char **str)
{
	int			i;
	t_export	*curr;
	char		*temp;

	i = 1;
	while (str[i])
	{
		if (!check_already_exist(mini, str[i]))
			add_export_list(mini, str[i]);
		i++;
	}
	if (i == 1 && !str[i])
	{
		put_export_list(mini);
		sort_export(mini);
		curr = mini->exp;
		while (curr)
		{
			print_export(curr);
			ft_free(&curr->export_list);
			curr = curr->next;
		}
	}
}

void	init_export_param(t_mini *mini, char *envp[], int *i)
{
	char	*temp;

	mini->exp = (t_export *)malloc(sizeof(t_export) * 1);
	if (!mini->exp)
		malloc_error();
	mini->exp->env_list = ft_strdup(envp[*i]);
	if (ft_strchr(mini->exp->env_list, '='))
	{
		temp = ft_strdup(envp[*i]);
		if (*(ft_strchr(temp, '=') + 1))
			mini->exp->value = ft_strdup(ft_strchr(temp, '=') + 1);
		else
			mini->exp->value = NULL;
		*(ft_strchr(temp, '=')) = '\0';
		mini->exp->key = ft_strdup(temp);
		free(temp);
	}
	else
	{
		mini->exp->key = ft_strdup(envp[*i]);
		mini->exp->value = NULL;
	}
	mini->exp->next = NULL;
	mini->exp->prev = NULL;
	(*i)++;
}
