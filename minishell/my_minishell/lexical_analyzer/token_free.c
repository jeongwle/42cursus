/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 12:12:40 by mki               #+#    #+#             */
/*   Updated: 2021/05/20 12:26:24 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexical_analyzer.h"

void	token_free(t_list *lst)
{
	free(((t_token *)lst->content)->value);
	((t_token *)lst->content)->value = NULL;
	free(lst->content);
	lst->content = NULL;
	free(lst);
	lst = NULL;
}

t_list	*lst_next_free(t_list *lst)
{
	t_list	*ret;
	t_list	*lst_next;

	ret = NULL;
	lst_next = lst->next;
	if (lst_next)
	{
		ret = lst_next->next;
		token_free(lst_next);
		lst->next = ret;
	}
	return (ret);
}

void	lst_token_free(t_list *start, t_list *end)
{
	t_list	*lst;

	lst = start;
	while (lst != end)
		lst = lst_next_free(lst);
	token_free(start);
}
