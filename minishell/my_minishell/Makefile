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
	cp ./libft/libft.a ./
	$(CC) -lncurses -o $@ $^ ./libft.a

all : $(NAME)

fclean : clean
	$(RM) $(NAME)

clean :
	$(RM) $(OBJS)
	$(RM) ./libft.a
	make clean -C ./libft

re : fclean all

.PHONY : all clean fclean re
