/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_word_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehan <sehan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 17:11:30 by sehan             #+#    #+#             */
/*   Updated: 2021/06/16 12:53:55 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/minishell.h"

t_list	*make_word_list(t_list *lst, t_word **word)
{
	t_list	*first;
	t_list	*second;
	t_token	*token;
	int		i;

	first = NULL;
	i = 0;
	second = ft_lstnew(&word[0][i]);
	ft_lstadd_back(&first, ft_lstnew(second));
	while (lst)
	{
		token = lst->content;
		if (token->name == '|' || token->name == ';')
		{
			if (token->name == '|')
				ft_lstadd_back(&second, ft_lstnew(&word[0][++i]));
			else
			{
				second = ft_lstnew(&word[0][++i]);
				ft_lstadd_back(&first, ft_lstnew(second));
			}
		}
		lst = lst->next;
	}
	return (first);
}
