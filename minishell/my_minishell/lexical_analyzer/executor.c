/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 10:10:01 by mki               #+#    #+#             */
/*   Updated: 2021/05/25 14:01:31 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexical_analyzer.h"

// t_word	*word_new(char *str)
// {
// 	t_word	*ret;

// 	ret = (t_word *)malloc(sizeof(t_word));
// 	ret->argv[0] = str;
// 	ret->fd_in = NULL;
// 	ret->fd_out = NULL;
// 	return (ret);
// }

void		lst_print(t_list *lst)
{
	t_list	*tmp;
	char	**str;
	int		i;

	while (lst)
	{
		tmp = lst->content;
		while (tmp)
		{
			str = (char **)tmp->content;
			i = 0;
			while (str[i])
				printf("%s\n", str[i++]);
			tmp = tmp->next;
		}
		lst = lst->next;
	}
}

char	**ft_str(char *s)
{
	char	**ret;
	
	ret = NULL;
	ret = ft_split(s, ' ');
	free(s);
	return (ret);
}

t_list	*ft_pipe(char *s)
{
	char		**split_pipe;
	t_list		*ret;
	int			i;
	
	split_pipe = ft_split(s, '|');
	free(s);
	ret = NULL;
	i = -1;
	while (split_pipe[++i])
	{
		ft_lstadd_back(&ret, ft_lstnew(ft_str(split_pipe[i])));
	}
	free(split_pipe);
	return (ret);
}

t_list	*ft_semi(char *s)
{
	char		**split_semi;
	t_list	*ret;
	int			i;

	split_semi = ft_split(s, ';');
	ret = NULL;
	i = -1;
	while (split_semi[++i])
	{
		ft_lstadd_back(&ret, ft_lstnew(ft_pipe(split_semi[i])));
		// printf("while: %p\n", ret);
	}
	// printf("res: %p\n", ret);
	// t_list	*pipe = ret->content;
	// t_list	*space = pipe->content;
	// printf("%s\n", ((char **)space->content)[0]);
	free(split_semi);
	return (ret);
}

t_list	*executor(char *str)
{
	t_list	*ret;

	ret = ft_semi(str);
//	lst_print(mini->lst_parsed);
	return (ret);
}
