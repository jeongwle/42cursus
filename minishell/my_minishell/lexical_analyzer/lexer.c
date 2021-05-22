/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 10:12:47 by mki               #+#    #+#             */
/*   Updated: 2021/05/21 12:26:39 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexical_analyzer.h"

int		token_string(t_list **begin_list, char *str, int idx)
{
	int		len;
	t_token	*token;

	token = (t_token *)malloc(sizeof(t_token));
	len = idx;
	while (str[len])
	{
		if (ft_isalpha(str[len]))
			len++;
		else
			break ;
	}
	len -= idx;
	token->value = (char *)malloc(sizeof(char) * (len + 1));
	token->name = 's';
	ft_strlcpy(token->value, str + idx, len + 1);
	ft_lstadd_back(begin_list, ft_lstnew(token));
	return (len);
}

int		token_special(t_list **begin_list, char c)
{
	t_token	*token;

	token = (t_token *)malloc(sizeof(t_token));
	token->name = c;
	token->value = (char *)malloc(sizeof(char) * 2);
	token->value[0] = c;
	token->value[1] = '\0';
	ft_lstadd_back(begin_list, ft_lstnew(token));
	return (1);
}

int		space_token_compress(t_list *lst_begin)
{
	t_token	*token;
	t_list	*lst;
	char	c;

	lst = lst_begin;
	while (lst)
	{
		token = lst->content;
		c = token->name;
		while (c == ' ' && lst->next)
		{	
			token = lst->next->content;
			if (token->name == ' ')
				lst_next_free(lst);
			else
				break ;
		}
		lst = lst->next;
	}
	return (0);
}

t_list	*lexer(char *str)
{
	t_list	*lst_token;
	int		idx;

	lst_token = NULL;
	idx = 0;
	while (str[idx])
	{
		if (ft_isalpha(str[idx]))
			idx += token_string(&lst_token, str, idx);
		else if (ft_isascii(str[idx]))
			idx += token_special(&lst_token, str[idx]);
		else
			idx++;
	}
	if (space_token_compress(lst_token))
		return (NULL);
	return (lst_token);
}
