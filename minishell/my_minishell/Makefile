NAME	=  minishell

SRCS	= ./srcs/main.c \
		  ./srcs/term_set.c \
		  ./srcs/signal_handler.c \
		  ./srcs/malloc_error.c \
		  ./srcs/builtin_exit.c \
		  ./srcs/builtin_pwd.c \
		  ./srcs/builtin_cd.c \
		  ./srcs/builtin_export.c \
		  ./srcs/builtin_export_utils.c \
		  ./srcs/builtin_export_change.c \
		  ./srcs/builtin_export_print.c \
		  ./srcs/builtin_export_check.c \
		  ./srcs/builtin_export_plus.c \
		  ./srcs/builtin_unset.c \
		  ./srcs/builtin_exit.c \
		  ./srcs/builtin_echo.c \
		  ./srcs/mini_arrow.c \
		  ./srcs/mini_delete.c \
		  ./srcs/mini_history_set.c \
		  ./srcs/mini_history_exe.c \
		  ./srcs/mini_execve.c \
		  ./srcs/mini_utils.c \
		  ./srcs/mini_pipe.c \
		  ./srcs/mini_parsing.c \
		  ./srcs/mini_utils_two.c \
		  ./lexical_analyzer/ft_isall.c \
		  ./lexical_analyzer/lexer.c \
		  ./lexical_analyzer/lexer_space.c \
		  ./lexical_analyzer/lexical_analyzer.c \
		  ./lexical_analyzer/make_string.c \
		  ./lexical_analyzer/make_word_list.c \
		  ./lexical_analyzer/make_word.c \
		  ./lexical_analyzer/make_word2.c \
		  ./lexical_analyzer/parser_backslash.c \
		  ./lexical_analyzer/parser_env.c \
		  ./lexical_analyzer/parser_quotes.c \
		  ./lexical_analyzer/parser.c \
		  ./lexical_analyzer/syntax_backslash.c \
		  ./lexical_analyzer/syntax_error.c \
		  ./lexical_analyzer/syntax_multiline.c \
		  ./lexical_analyzer/syntax_quotes.c \
		  ./lexical_analyzer/syntax_redirection.c \
		  ./lexical_analyzer/token.c

OBJS	= $(SRCS:.c=.o)
RM		= rm -f
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
C		= clang

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	make -C ./libft
	make bonus -C ./libft
	cp ./libft/libft.a ./
	$(CC) $(CFLAGS) -lncurses -o $@ $^ ./libft.a

all : $(NAME)

fclean : clean
	$(RM) $(NAME)

clean :
	$(RM) $(OBJS)
	$(RM) ./libft.a ./libft/libft.a
	make clean -C ./libft

re : fclean all

.PHONY : all clean fclean re
