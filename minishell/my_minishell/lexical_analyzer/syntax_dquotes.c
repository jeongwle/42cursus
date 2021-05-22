/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_dquotes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:34:51 by mki               #+#    #+#             */
/*   Updated: 2021/05/20 14:45:59 by mki              ###   ########.fr       */
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
		if (token->name = '\'')
			lst = token_find(lst, '\'');
		if (!lst)
			return (syntax_error(ERROR_QUOTES));
		lst = lst->next;
	}
	return (0);
}
