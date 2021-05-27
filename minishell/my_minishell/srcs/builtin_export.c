/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 14:54:20 by jeongwle          #+#    #+#             */
/*   Updated: 2021/05/27 13:54:19 by jeongwle         ###   ########.fr       */
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
		new->value = ft_strdup(ft_strchr(new->env_list, '=') + 1);
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

	i = 1;
	while (str[i])
	{
		if (ft_strchr(str[i], '='))
			check_plus(mini, str[i]);
		if (!check_already_exist(mini, str[i]))
			add_export_list(mini, str[i]);
		i++;
	}
	if (i == 1 && !str[i])
	{
		sort_export(mini);
		curr = mini->exp;
		while (curr)
		{
			if (curr->export_list)
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
