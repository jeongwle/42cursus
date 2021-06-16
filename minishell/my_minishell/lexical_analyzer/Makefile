# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/14 22:30:00 by mki               #+#    #+#              #
#    Updated: 2021/06/15 21:06:55 by sehan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	liblex.a
CC			=	gcc
ASAN		=	-fsanitize=address -g2
CFLAGS		=	-Wall -Wextra -Werror -I ../ $(ASAN)
AR			=	ar -rcs
RM			=	rm -rf

LEX			=	ft_isall\
				lexer\
				lexical_analyzer\
				make_string\
				make_word_list\
				make_word\
				make_word2\
				parser_backslash\
				parser_env\
				parser_quotes\
				parser\
				syntax_backslash\
				syntax_error\
				syntax_multiline\
				syntax_quotes\
				syntax_redirection\
				token\

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
