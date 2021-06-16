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
		  ./srcs/mini_utils_two.c

OBJS	= $(SRCS:.c=.o)
RM		= rm -f
CC		= gcc
C		= clang

.c.o :
	$(CC) -c -g $< -o $@

$(NAME) : $(OBJS)
	make -C ./libft
	make bonus -C ./libft
	make -C ./lexical_analyzer
	cp ./lexical_analyzer/liblex.a ./
	cp ./libft/libft.a ./
#	$(CC) -lncurses -o $@ $^ ./libft.a ./liblex.a
	$(CC) -fsanitize=address -lncurses -o $@ $^ ./libft.a ./liblex.a

all : $(NAME)

fclean : clean
	$(RM) $(NAME)

clean :
	$(RM) $(OBJS)
	$(RM) ./libft.a ./libft/libft.a
	$(RM) ./liblex.a ./lexical_analyzer/liblex.a
	make clean -C ./libft
	make clean -C ./lexical_analyzer

re : fclean all

.PHONY : all clean fclean re
