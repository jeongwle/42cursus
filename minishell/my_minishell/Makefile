NAME	=  minishell

SRCS	= ./srcs/main.c \
		  ./srcs/term_set.c \
		  ./srcs/signal_handler.c \
		  ./srcs/if_arrow.c \
		  ./srcs/if_delete.c \
		  ./srcs/history_set.c \
		  ./srcs/history_exe.c \
		  ./srcs/malloc_error.c \
		  ./srcs/builtin_exit.c \
		  ./srcs/builtin_pwd.c \
		  ./srcs/builtin_cd.c \
		  ./srcs/builtin_export.c \
		  ./srcs/builtin_export_utils.c \
		  ./srcs/builtin_export_change.c \
		  ./srcs/builtin_export_print.c \
		  ./srcs/builtin_export_check.c \
		  ./srcs/mini_utils.c \
		  ./srcs/mini_utils_two.c

OBJS	= $(SRCS:.c=.o)
RM		= rm -f
CC		= gcc
C		= clang

.c.o :
	$(CC) -c $< -o $@

$(NAME) : $(OBJS)
	make -C ./libft
	make bonus -C ./libft
	make -C ./lexical_analyzer
	cp ./lexical_analyzer/lexical_analyzer.a ./
	cp ./libft/libft.a ./
	$(CC) -lncurses -o $@ $^ ./libft.a ./lexical_analyzer.a
#	$(CC) -fsanitize=address -lncurses -o $@ $^ ./libft.a ./lexical_analyzer.a

all : $(NAME)

fclean : clean
	$(RM) $(NAME)

clean :
	$(RM) $(OBJS)
	$(RM) ./libft.a ./libft/libft.a
	$(RM) ./lexical_analyzer.a ./lexical_analyzer/lexical_analyzer.a
	make clean -C ./libft
	make clean -C ./lexical_analyzer

re : fclean all

.PHONY : all clean fclean re
