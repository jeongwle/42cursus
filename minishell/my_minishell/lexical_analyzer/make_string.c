/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 18:52:42 by mki               #+#    #+#             */
/*   Updated: 2021/06/16 12:53:10 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/minishell.h"

t_list	*make_string(t_list *start, t_list *end)
{
	t_list	*lst;
	t_list	*lst_tmp;
	char	*str_ret;
	char	*tmp;

	str_ret = (char *)ft_calloc(1, sizeof(char));
	lst = start->next;
	while (lst != end)
	{
		tmp = ft_strjoin(str_ret, ((t_token *)lst->content)->value);
		free(str_ret);
		str_ret = tmp;
		lst_tmp = lst->next;
		token_free(lst);
		lst = lst_tmp;
	}
	((t_token *)start->content)->name = 's';
	free(((t_token *)start->content)->value);
	((t_token *)start->content)->value = str_ret;
	lst_tmp = end->next;
	token_free(end);
	start->next = lst_tmp;
	return (end);
}
