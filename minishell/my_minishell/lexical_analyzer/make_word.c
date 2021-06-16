/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:54:15 by mki               #+#    #+#             */
/*   Updated: 2021/06/16 12:53:31 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/minishell.h"

int		pipe_and_semi_size(t_list *lst)
{
	int		i;
	t_token	*token;

	i = 0;
	while (lst)
	{
		token = lst->content;
		if (token->name == ';' || token->name == '|')
			i++;
		lst = lst->next;
	}
	return (i);
}

void	word_init(t_word **word, int i)
{
	int j;

	j = 0;
	*word = (t_word *)malloc(sizeof(t_word) * (i + 1));
	while (j <= i)
	{
		word[0][j].fd_in = -2;
		word[0][j].fd_out = -2;
		j++;
	}
}

int		*string_size(t_list *lst, t_word **word)
{
	t_token	*token;
	int		*str_size;
	int		i;

	i = 0;
	str_size = (int *)malloc(sizeof(int) * (pipe_and_semi_size(lst) + 1));
	ft_memset(str_size, 0, sizeof(int) * (pipe_and_semi_size(lst) + 1));
	while (lst)
	{
		token = lst->content;
		if (token->name == 's')
			str_size[i]++;
		else if (token->name == ';' || token->name == '|')
			i++;
		else if (token->name == '>' || token->name == '<')
		{
			if (((t_token *)lst->next->content)->name == '>')
				lst = lst->next;
			str_size[i]--;
		}
		lst = lst->next;
	}
	word_init(word, i);
	return (str_size);
}

void	make_word_init(t_list *lst, t_word **word, int **str_size)
{
	*str_size = string_size(lst, word);
	if (!str_size[0][0])
		word[0][0].argv = NULL;
	else
	{
		word[0][0].argv =
			(char **)malloc(sizeof(char *) * (str_size[0][0] + 1));
		word[0][0].argv[str_size[0][0]] = 0;
	}
}

t_word	*make_word(t_list *lst_begin)
{
	t_token	*token;
	t_word	*word;
	int		*str_size;
	int		i;
	int		j;

	make_word_init(lst_begin, &word, &str_size);
	i = 0;
	j = -1;
	while (lst_begin)
	{
		token = lst_begin->content;
		if (token->name == 's')
			word[i].argv[++j] = ft_strdup(token->value);
		else if (token->name == '>')
			right_angle_bracket(&lst_begin, word, &i);
		else if (token->name == '<')
			token = left_angle_bracket(&lst_begin, word, &i, &j);
		if (token->name == ';' || token->name == '|')
			malloc_argv(word, &i, &j, str_size[i + 1]);
		lst_begin = lst_begin->next;
	}
	free(str_size);
	return (word);
}
