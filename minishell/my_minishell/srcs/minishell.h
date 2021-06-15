/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 12:50:22 by jeongwle          #+#    #+#             */
/*   Updated: 2021/06/15 13:26:18 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define ARROWUP 4283163
# define ARROWDOWN 4348699
# define BACKSPACE 127
#include "../libft/libft.h"
#include "../lexical_analyzer/lexical_analyzer.h"
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

typedef struct	s_export
{
	char			*export_list;
	struct s_export	*next;
	struct s_export *prev;
	char			*env_list;
	char			*key;
	char			*value;
}				t_export;

typedef struct	s_mini
{
	t_list			*something;
	t_list			*lst;
	t_lst			*head;
	t_lst			*tail;
	t_lst			*curr;
	t_export		*exp;
	struct termios	term_temp;
	int				idx;
	char			buf[4096];
	char			*temp;
	int				atoi_flag;
	int				row_flag;
	int				col_max_temp;
	int				col_temp;
	int				col;
	int				row;
	pid_t			*pid;
	int				**fds;
	int				status;
	int				make_history_flag;
}				t_mini;

void		delete_end(t_mini *mini);
void		delete_prev(void);
void		get_cursor_position(int *col, int *row);
void		signal_handler(int signum);
void		init_history_param(t_mini *mini);
void		malloc_error(void);
void		mini_lstadd_middle(t_mini *mini, t_lst *new);
t_lst		*mini_lstnew(char *buf);

void		ifn_head(t_mini *mini);
void		if_head(t_mini *mini);
void		make_history_lst(t_mini *mini);
void		if_history_modified(t_mini *mini);

void		arrow_up_down(t_mini *mini, long long int compare);

void		history_lst_clear(t_mini *mini);

void		clear_buf(t_mini *mini);
void		head_clear(t_mini *mini);
char		*ft_strndup(const char *s, int n);
void		ft_free(char **s);
int			ft_strcmp(char *s1, char *s2);

int			mini_lstsize(t_export *lst);

void		pwd(void);
void		cd(t_mini *mini, char *path);

void		mini_export_addback(t_mini *mini, t_export *new);
void		sort_export(t_mini *mini);
void		put_export_list(t_mini *mini);
int			check_already_exist(t_mini *mini, char *str);

t_export	*mini_export_new(char *str);
void		make_export_list(t_mini *mini, char *envp[]);
void		add_export_list(t_mini *mini, char *str);
void		check_export_param(t_mini *mini, char **str);
void		init_export_param(t_mini *mini, char *envp[], int *i);

void		change_oldpwd(t_mini *mini, char *buf);
void		change_pwd(t_mini *mini, char *buf);
void		delete_oldpwd(t_mini *mini);

void		print_export(t_export *curr);
void		print_env(t_mini *mini);

void		check_already_sub_two(t_export *curr, char *value_temp);
int			check_already_sub(t_export *curr, char *str);
int			check_already_exist(t_mini *mini, char *str);

int			check_plus(t_mini *mini, char *str, char **temp);

void		unset(t_mini *mini, char **str);

char		**make_env(t_mini *mini);
void		use_execve(t_mini *mini, char **str);

void		mini_exit(t_mini *mini, char **str);

void		ft_echo(char **str);

void		term_set(void);
void		store_present_term(t_mini *mini);
void		change_term(t_mini *mini);

void		parse_by_builtin(t_mini *mini, char **str);
void		is_pipe(t_mini *mini);

#endif
