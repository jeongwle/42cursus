/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 12:50:22 by jeongwle          #+#    #+#             */
/*   Updated: 2021/06/21 20:58:34 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define ARROWUP 4283163
# define ARROWDOWN 4348699
# define ARROWRIGHT 4414235
# define ARROWLEFT  4479771
# define BACKSPACE 127
# include "../libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <string.h>
# include <errno.h>
# include <signal.h>
# include <termios.h>
# include <termcap.h>
# define BACKSLASH_MULTI		0x0001
# define DQUOTES_MULTI			0x0002
# define QUOTES_MULTI			0x0004
# define SYNTAX					0x0008
# define PIPELINE_MULTI			0x0080
# define FIRST					1
# define LAST					1

typedef struct	s_word
{
	char				**argv;
	int					fd_in;
	int					fd_out;
}				t_word;

typedef struct	s_token
{
	char				name;
	char				*value;
}				t_token;

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
	t_list			*semi;
	t_list			*pipe;
	t_list			*semi_temp;
	t_word			*word;
	t_lst			*head;
	t_lst			*tail;
	t_lst			*curr;
	t_export		*exp;
	struct termios	term_temp;
	int				idx;
	char			buf[4096];
	char			*temp;
	char			*program_name;
	int				atoi_flag;
	pid_t			*pid;
	int				**fds;
	int				status;
	int				status_temp;
	int				make_history_flag;
	int				sig_flag;
	int				word_cnt;
}				t_mini;

extern			t_mini	g_mini;

void			delete_end(t_mini *mini);
void			delete_prev(void);
void			get_cursor_position(int *col, int *row);
void			signal_handler(int signum);
void			init_history_param(t_mini *mini);
void			malloc_error(void);
void			mini_lstadd_middle(t_mini *mini, t_lst *new);
t_lst			*mini_lstnew(char *buf);

void			ifn_head(t_mini *mini);
void			if_head(t_mini *mini);
void			make_history_lst(t_mini *mini);
void			if_history_modified(t_mini *mini);

void			arrow_up_down(t_mini *mini, long long int compare);

void			history_lst_clear(t_mini *mini);

void			clear_buf(t_mini *mini);
void			head_clear(t_mini *mini);
char			*ft_strndup(const char *s, int n);
void			ft_free(char **s);
int				ft_strcmp(char *s1, char *s2);

int				mini_lstsize(t_export *lst);
char			*find_env(t_mini *mini, char *key);
void			ft_free_double(char **s1, char **s2);
void			free_command_list(t_mini *mini);

void			pwd(void);
void			cd(t_mini *mini, char *path);

void			mini_export_addback(t_mini *mini, t_export *new);
void			sort_export(t_mini *mini);
void			put_export_list(t_mini *mini);
int				check_argument(char *str, char c);

t_export		*mini_export_new(char *str);
void			make_export_list(t_mini *mini, char *envp[]);
void			add_export_list(t_mini *mini, char *str);
void			check_export_param(t_mini *mini, char **str);
void			init_export_param(t_mini *mini, char *envp[], int *i);

void			change_oldpwd(t_mini *mini, char *buf);
void			change_pwd(t_mini *mini, char *buf);
void			delete_oldpwd(t_mini *mini);

void			print_export(t_export *curr);
void			print_env(t_mini *mini);

void			check_already_sub_two(t_export *curr, char *value_temp);
int				check_already_sub(t_export *curr, char *str);
int				check_already_exist(t_mini *mini, char *str);

int				check_plus(t_mini *mini, char *str, char **temp);

void			unset(t_mini *mini, char **str);

char			**make_env(t_mini *mini);
void			use_execve(t_mini *mini, char **str);

void			mini_exit(t_mini *mini, char **str);

void			ft_echo(char **str);

void			term_set(void);
void			store_present_term(t_mini *mini);
void			change_term(t_mini *mini);

void			parse_by_builtin(t_mini *mini, char **str, t_word *word);
void			parse_by_input(t_mini *mini, long long int *compare);

void			is_pipe(t_mini *mini);

int				is_builtin(char **str);
void			free_split(char **split);

t_list			*executor(char *str, t_list *lst_begin);
int				ft_isall(char c);
int				ft_ismeta(char c);
int				ft_isquotes(char c);
int				ft_isspace(char c);
int				ft_isspecial(char c);
t_list			*lexer(char *str);
t_list			*lexical_analyzer
(char *str, t_mini *mini, int status);
t_list			*make_string(t_list *start, t_list *end);
int				parser_backslash(t_list *lst_begin, int mode);
int				parser_dquotes
(t_list *lst_begin, t_mini *mini, int status);
int				parser_env
(t_list *lst_begin, t_mini *mini, int status);
int				parser_quotes(t_list *lst_begin);
int				parser
(t_list *lst_begin, t_mini *mini, int status);
int				syntax_backslash(t_list *lst_begin);
int				syntax_dquotes(t_list *lst_begin);
int				syntax_error(int num);
int				syntax_multline(char *str);
int				syntax_quotes(t_list *lst_begin);
int				syntax_redirection(t_list *lst_begin);
t_list			*token_find(t_list *lst, char c);
void			token_free(t_list *lst);
void			lst_token_free(t_list *start);
t_list			*lst_next_free(t_list *lst);
t_word			*make_word(t_list *lst);
void			print_lst_token(t_list *lst);
void			malloc_argv(t_word *word, int *i, int *j, int size);
t_token			*left_angle_bracket
(t_list **lst, t_word *word, int *i, int *j);
void			right_angle_bracket
(t_list **lst, t_word *word, int *i);
t_list			*make_word_list(t_list *lst, t_word **word);
t_list			*dquotes_token_find(t_list *lst);
void			space_helper(t_list *lst, char c);
int				space_token_compress(t_list *lst_begin);

#endif
