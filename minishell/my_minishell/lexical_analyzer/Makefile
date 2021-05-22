# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/14 22:30:00 by mki               #+#    #+#              #
#    Updated: 2021/05/22 14:59:10 by mki              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	lexical_analyzer.a
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
AR			=	ar -rcs
RM			=	rm -f
.SUFFIXES	=	.c.o

LEX			=	executor\
				ft_isall\
				ft_ismeta\
				ft_isquotes\
				ft_isspace\
				ft_isspecial\
				lexer\
				lexical_analyzer\
				make_string\
				parser_backslash\
				parser_dquotes\
				parser_pipeline\
				parser_quotes\
				parser_redirection\
				parser_semicolon\
				parser\
				token_find\
				token_free\
				#syntax_backslash\
				syntax_dquotes\
				syntax_error\
				syntax_pipeline\
				syntax_quotes\
				syntax_redirection\
				syntax_semicolon\
				parser_env\

LEX_DIR		=	./
LEX_SRCS	=	$(addprefix $(LEX_DIR), $(addsuffix .c, $(LEX))) 
LEX_OBJS	=	$(addprefix $(LEX_DIR), $(addsuffix .o, $(LEX))) 

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

all: $(NAME)

$(NAME): $(LEX_OBJS)
	$(AR) $@ $^

clean:
	$(RM) $(LEX_OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: clean all bonus fclean re
