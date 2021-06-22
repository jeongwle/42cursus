/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 12:30:01 by mki               #+#    #+#             */
/*   Updated: 2021/06/22 13:18:47 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/minishell.h"

void	parser_dollar_question_mark(t_list *lst_begin, int status)
{
	t_list	*lst_next;
	t_token	*token;

	token = lst_begin->content;
	lst_next = lst_begin->next;
	lst_begin->next = lst_next->next;
	token_free(lst_next);
	token->name = 's';
	free(token->value);
	token->value = ft_itoa(status);
}

void	parser_env_trans(t_list *lst_begin, t_mini *mini, char *key)
{
	t_token		*token;
	char		*temp;

	token = lst_begin->content;
	if ((temp = find_env(mini, key)))
	{
		token->name = 's';
		free(token->value);
		token->value = temp;
	}
	else
	{
		token->name = 0;
		token->value[0] = '\0';
	}
	free(key);
}

void	parser_env_var(t_list *lst_begin, t_mini *mini)
{
	t_token	*t;
	char	*key;
	char	*tmp;

	key = (char *)ft_calloc(1, 1);
	t = lst_begin->next->content;
	while (t->name == 's' || t->name == '_' || ft_isdigit(t->name))
	{
		tmp = ft_strjoin(key, t->value);
		free(key);
		key = tmp;
		lst_next_free(lst_begin);
		if (lst_begin->next == NULL)
			break ;
		else
			t = lst_begin->next->content;
	}
	parser_env_trans(lst_begin, mini, key);
}

int		parser_env(t_list *lst_begin, t_mini *mini, int status)
{
	t_token	*token;

	if (lst_begin->next)
	{
		token = lst_begin->next->content;
		if (token->name == 's' || token->name == '_')
			parser_env_var(lst_begin, mini);
		else if (token->name == '?')
			parser_dollar_question_mark(lst_begin, status);
		else if (token->name == '\"' || token->name == ' ')
		{
			token = lst_begin->content;
			token->name = 's';
		}
		else
			return (1);
	}
	return (0);
}
