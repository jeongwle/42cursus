/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:51:29 by mki               #+#    #+#             */
/*   Updated: 2021/06/15 12:46:12 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexical_analyzer.h"

int	syntax_dquotes(t_list *lst_begin)
{
	t_list	*lst;
	t_token	*token;

	lst = lst_begin;
	while (lst)
	{
		token = lst->content;
		if (token->name == '\'')
			lst = token_find(lst, '\'');
		if (!lst)
			return (syntax_error(QUOTES_MULTI));
		lst = lst->next;
	}
	return (0);
}

int	syntax_quotes(t_list *lst_begin)
{
	t_list	*lst;
	t_token	*token;

	lst = lst_begin;
	while (lst)
	{
		token = lst->content;
		if (token->name == '\'')
			lst = token_find(lst, '\'');
		if (!lst)
			return (syntax_error(QUOTES_MULTI));
		lst = lst->next;
	}
	return (0);
}
