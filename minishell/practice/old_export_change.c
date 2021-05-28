/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old_export_change.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 15:14:12 by jeongwle          #+#    #+#             */
/*   Updated: 2021/05/27 11:13:30 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_env_list(t_mini *mini, char *str)
{
	t_export	*curr;

	add_export_list(mini, str);
	curr = mini->exp;
	while (curr->next)
		curr = curr->next;
	free(curr->export_list);
	curr->export_list = NULL;
}

void	change_oldpwd_export(t_mini *mini, char *buf)
{
	t_export	*curr;
	char		*temp;

	curr = mini->exp;
	while (curr)
	{
		if (curr->export_list &&
			(!ft_strcmp("declare -x OLDPWD", curr->export_list) ||
			ft_strcmp("declare -x OLDPWD", curr->export_list) == -61))
		{
			free(curr->export_list);
			temp = ft_strdup("declare -x OLDPWD=");
			curr->export_list = ft_strjoin(temp, buf);
			free(temp);
			make_double_quotes(curr);
			return ;
		}
		curr = curr->next;
	}
}

void	change_oldpwd_env(t_mini *mini, char *buf)
{
	t_export	*curr;
	char		*temp;

	curr = mini->exp;
	while (curr)
	{
		if (curr->env_list &&
			(!ft_strcmp("OLDPWD", curr->env_list) ||
			ft_strcmp("OLDPWD", curr->env_list) == -61))
			break ;
		curr = curr->next;
	}
	if (curr)
	{
		free(curr->env_list);
		temp = ft_strdup("OLDPWD=");
		curr->env_list = ft_strjoin(temp, buf);
	}
	else
	{
		temp = ft_strjoin("OLDPWD=", buf);
		add_env_list(mini, temp);
	}
	free(temp);
}

void	change_pwd(t_mini *mini, char *buf)
{
	t_export	*curr;
	char		*temp;

	curr = mini->exp;
	while (curr)
	{
		if (curr->export_list &&
			ft_strcmp("declare -x PWD", curr->export_list) == -61)
		{
			free(curr->export_list);
			temp = ft_strdup("declare -x PWD=");
			curr->export_list = ft_strjoin(temp, buf);
			free(temp);
			make_double_quotes(curr);
		}
		if (curr->env_list &&
			ft_strcmp("PWD", curr->env_list) == -61)
		{
			free(curr->env_list);
			temp = ft_strdup("PWD=");
			curr->env_list = ft_strjoin(temp, buf);
			free(temp);
		}
		curr = curr->next;
	}
}

void	delete_oldpwd(t_mini *mini)
{
	t_export	*curr;

	curr = mini->exp;
	while (curr)
	{
		if (curr->export_list &&
			(!ft_strcmp("declare -x OLDPWD", curr->export_list) ||
			ft_strcmp("declare -x OLDPWD", curr->export_list) == -61))
		{
			*(ft_strchr(curr->export_list, 'D') + 4) = '\0';
			break ;
		}
		curr = curr->next;
	}
	if (!curr)
		add_export_list(mini, "OLDPWD");
	curr = mini->exp;
	while (curr)
	{
		if (curr->env_list && ft_strcmp("OLDPWD", curr->env_list) == -61)
			ft_free(&curr->env_list);
		curr = curr->next;
	}
}
