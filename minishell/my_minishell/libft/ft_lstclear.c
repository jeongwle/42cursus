/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 20:13:09 by jeongwle          #+#    #+#             */
/*   Updated: 2020/10/14 21:29:45 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *temp;
	t_list *free_temp;

	if (!lst || !del)
		return ;
	temp = *lst;
	while (temp)
	{
		free_temp = temp;
		del(temp->content);
		temp = temp->next;
		free(free_temp);
	}
	*lst = NULL;
}
