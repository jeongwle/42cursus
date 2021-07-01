NAME	= philo

SRCS	= ./main.c \
		  ./init.c \
		  ./fork.c \
		  ./utils.c

OBJS	= $(SRCS:.c=.o)
RM		= rm -f
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

.c.o :
	$(CC) $(CFLAGS) -pthread -c -o $@ $<

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -pthread -o $@ $^

all : $(NAME)

fclean : clean
	$(RM) $(NAME)

clean :
	$(RM) $(OBJS)

re : fclean all

.PHONY : all clean fclean re
