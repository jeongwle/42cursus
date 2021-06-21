/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <jeongwle@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 21:10:39 by jeongwle          #+#    #+#             */
/*   Updated: 2021/06/21 20:37:20 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

void	put_export_list(t_mini *mini)
{
	t_export	*curr;

	curr = mini->exp;
	while (curr)
	{
		if (curr->env_list)
			curr->export_list = ft_strdup(curr->env_list);
		curr = curr->next;
	}
}

int		check_argument_sub(char *str, char c)
{
	if (g_mini.pipe->next)
		dup2(2, 1);
	if (c == 'e')
		write(1, "bash: export: `", 15);
	else if (c == 'u')
		write(1, "bash: unset: `", 14);
	ft_putstr_fd(str, 1);
	write(1, "': not a valid identifier\n", 26);
	g_mini.status = 1;
	return (1);
}

int		check_argument(char *str, char c)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	if (!ft_isalpha(str[i]) && str[i] != '_')
		return (check_argument_sub(str, c));
	i++;
	while (str[i] != '=' && str[i])
	{
		if (ft_isalpha(str[i]))
			i++;
		else if (ft_isdigit(str[i]))
			i++;
		else if (str[i] == '_')
			i++;
		else if (!flag && str[i] == '+' && (str[i + 1] && str[i + 1] == '='))
		{
			i++;
			flag = 1;
		}
		else
			return (check_argument_sub(str, c));
	}
	return (0);
}
