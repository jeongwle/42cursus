NAME	=  minishell

SRCS	= ./main.c \
		  ./term_set.c \
		  ./delete.c \
		  ./signal_handler.c \
		  ./history_set.c \
		  ./history_exe.c \
		  ./malloc_error.c \
		  ./arrow_up_down.c \
		  ./utils.c

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