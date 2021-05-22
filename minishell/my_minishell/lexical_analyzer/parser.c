/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 10:12:50 by mki               #+#    #+#             */
/*   Updated: 2021/05/20 14:32:29 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexical_analyzer.h"

int	parser_if(t_list *lst, t_envp_list *lst_envp, char name, int status)
{
	if (name == '\\')
		return (parser_backslash(lst, 0));
	else if (name == '\"')
		return (parser_dquotes(lst, lst_envp, status));
	else if (name == '$')
		return (parser_env(lst, lst_envp, status));
	else if (name == '|')
		return (parser_pipeline(lst));
	else if (name == '\'')
		return (parser_quotes(lst));
	else if (name == '>' || name == '<')
		return (parser_redirection(lst));
	return (0);
}

int	syntax_check(t_list *lst_begin)
{
	while (lst_begin)
	{
		if (syntax_backslash(lst_begin))
			return (1);
		else if (syntax_pipeline(lst_begin))
			return (1);
		else if (syntax_redirection(lst_begin))
			return (1);
		else if (syntax_semicolon(lst_begin))
			return (1);
		lst_begin = lst_begin->next;
	}
	if (syntax_quotes(lst_begin))
		return (1);
	if (syntax_dquotes(lst_begin))
		return (1);
	return (0);
}

int	parser(t_list *lst_begin, t_envp_list *lst_envp, int status) 
{
	t_list	*lst;
	t_token *token;

	if (syntax_check(lst_begin))
		return (1);
	lst = lst_begin;
	while (lst)
	{
		token = lst->content;
		if (parser_if(lst, lst_envp, token->name, status))
			return (1);
		lst = lst->next;
	}
	return (0);
}
