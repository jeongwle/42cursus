/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 17:46:28 by jeongwle          #+#    #+#             */
/*   Updated: 2021/06/21 17:51:24 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/minishell.h"

void	space_helper(t_list *lst, char c)
{
	t_token	*token;

	while (c == ' ' && lst->next)
	{
		token = lst->next->content;
		if (token->name == ' ')
			lst_next_free(lst);
		else
			break ;
	}
}

int		space_token_compress(t_list *lst_begin)
{
	t_token	*token;
	t_list	*lst;
	t_list	*tmp;
	char	c;

	lst = lst_begin;
	while (lst)
	{
		token = lst->content;
		c = token->name;
		if (token->name == '\"' && (tmp = dquotes_token_find(lst)))
		{
			lst = tmp->next;
			continue ;
		}
		if (token->name == '\'' && (tmp = token_find(lst, '\'')))
		{
			lst = tmp->next;
			continue ;
		}
		space_helper(lst, c);
		lst = lst->next;
	}
	return (0);
}
