/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical_analyzer.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:31:42 by mki               #+#    #+#             */
/*   Updated: 2021/05/24 21:24:11 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXICAL_ANALYZER_H
# define LEXICAL_ANALYZER_H
# include "../libft/libft.h"
# include <stdio.h>

# define	ERROR_BACKSLASH		0x01
# define	ERROR_DQUOTES		0x02
# define	ERROR_QUOTES		0x04
# define	ERROR_SEMICOLON		0x08
# define	ERROR_SEMICOLONS	0x10
# define	ERROR_ENV			0x20
# define	ERROR_PIPELINE		0x20

typedef struct			s_word
{
	char				**argv;
	int					*fd_in;
	int					*fd_out;
}						t_word;

typedef struct			s_envp_list
{
	struct s_envp_list	*next;
	void				*key;
	void				*value;
}						t_envp_list;

typedef struct			s_token
{
	char				name;
	char				*value;
}						t_token;

t_list		*executor(char *str);
int			ft_isall(char c);
int			ft_ismeta(char c);
int			ft_isquotes(char c);
int			ft_isspace(char c);
int			ft_isspecial(char c);
t_list		*lexer(char *str);
t_list		*lexical_analyzer(char *str, t_envp_list *lst_envp, int status);
t_list		*make_string(t_list *start, t_list *end);
int			parser_backslash(t_list *lst_begin, int mode);
int			parser_dquotes(t_list *lst_begin, t_envp_list *lst_envp, int status);
int			parser_env(t_list *lst_begin, t_envp_list *lst_envp, int status);
int			parser_pipeline(t_list *lst_begin);
int		 	parser_quotes(t_list *lst_begin);
int		 	parser_redirection(t_list *lst_begin);
int			parser_semicolon(t_list *lst_begin);
int			parser(t_list *lst_begin, t_envp_list *lst_envp, int status);
int			syntax_backslash(t_list *lst_begin);
int			syntax_dquotes(t_list *lst_begin);
int			syntax_error(int num);
int			syntax_pipeline(t_list *lst_begin);
int			syntax_quotes(t_list *lst_begin);
int			syntax_redirection(t_list *lst_begin);
int			syntax_semicolon(t_list *lst_begin);
t_list		*token_find(t_list *lst, char c);
void		token_free(t_list *lst);
void		lst_token_free(t_list *start, t_list *end);
t_list		*lst_next_free(t_list *lst);

#endif
