/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_find.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 16:22:25 by mki               #+#    #+#             */
/*   Updated: 2021/05/13 16:39:41 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexical_analyzer.h"

t_list	*token_find(t_list *lst, char c)
{
	t_token	*token;

	lst = lst->next;
	while (lst)
	{
		token = lst->content;
		if (token->name == c)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
