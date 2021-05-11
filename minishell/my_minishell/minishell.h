/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 12:50:22 by jeongwle          #+#    #+#             */
/*   Updated: 2021/05/11 19:50:54 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define ARROWUP 4283163
# define ARROWDOWN 4348699
# define BACKSPACE 127
#include "./libft/libft.h"
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <termios.h>
#include <termcap.h>

typedef struct	s_lst
{
	char			*history;
	struct s_lst	*next;
	struct s_lst	*prev;
	int				flag;
	char			*temp;
}				t_lst;

typedef struct	s_mini
{
	t_lst	*head;
	t_lst	*tail;
	t_lst	*curr;
	int		idx;
	char	buf[4096];
}				t_mini;

void	term_set(void);
void	delete_end(t_mini *mini);
void	signal_handler(int signum);
void	init_history_param(t_mini *mini);
void	malloc_error(void);
void	mini_lstadd_middle(t_mini *mini, t_lst *new);
t_lst	*mini_lstnew(char *buf);
void	arrow_up_down(t_mini *mini, long long int compare);
void	clear_buf(t_mini *mini);
void	delete_prev(void);

#endif