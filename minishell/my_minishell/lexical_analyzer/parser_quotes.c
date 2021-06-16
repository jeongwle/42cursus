/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 21:39:56 by mki               #+#    #+#             */
/*   Updated: 2021/06/16 13:06:59 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/minishell.h"

t_list	*dquotes_token_find(t_list *lst)
{
	t_token *token;

	while (lst)
	{
		token = lst->content;
		if (token->name == '\\')
			lst = lst->next;
		lst = lst->next;
		token = lst->content;
		if (token->name == '\"')
			return (lst);
	}
	return (lst);
}

int		parser_dquotes(t_list *lst_begin, t_mini *mini, int status)
{
	t_list	*lst;
	t_list	*end;
	t_token	*token;

	lst = lst_begin;
	end = dquotes_token_find(lst);
	while (lst != end)
	{
		token = lst->content;
		if (token->name == '\\' && parser_backslash(lst, 1))
			return (syntax_error(BACKSLASH_MULTI));
		else if (token->name == '$' && parser_env(lst, mini, status))
			return (syntax_error(DQUOTES_MULTI));
		lst = lst->next;
	}
	if (end)
		make_string(lst_begin, end);
	else
		return (syntax_error(DQUOTES_MULTI));
	return (0);
}

int		parser_quotes(t_list *lst_begin)
{
	t_list	*lst;
	t_list	*end;

	lst = lst_begin;
	end = token_find(lst, '\'');
	if (end)
		lst = make_string(lst, end);
	else
		return (syntax_error(QUOTES_MULTI));
	return (0);
}
