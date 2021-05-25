/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 14:54:20 by jeongwle          #+#    #+#             */
/*   Updated: 2021/05/25 20:42:09 by jeongwle         ###   ########.fr       */
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
	int	i;

	i = 0;
	init_export_param(mini, envp, &i);
	while (envp[i])
	{
		add_export_list(mini, envp[i]);
		i++;
	}
	sort_export(mini);
}

void		add_export_list(t_mini *mini, char *str)
{
	mini_export_addback(mini, mini_export_new(str));
}

void		check_export_param(t_mini *mini, char **str)
{
	int			i;
	t_export	*curr;

	i = 1;
	if (str[i])
	{
		while (str[i])
		{
			add_export_list(mini, str[i]);
			i++;
		}
	}
	else
	{
		sort_export(mini);
		curr = mini->exp;
		while (curr)
		{
			printf("%s\n", curr->export_list);
			curr = curr->next;
		}
	}
}

void		print_env(t_mini *mini)
{
	t_export	*curr;

	curr = mini->exp;
	while (curr)
	{
		if (curr->env_list)
			printf("%s\n", curr->env_list);
		curr = curr->next;
	}
}
