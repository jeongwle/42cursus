CC		= gcc

TARGET	= cub3D

SRCS	= ./main.c \
		  ./init.c \
		  ./key.c \
		  ./sprite.c \
		  ./texture.c \
		  ./dda.c

OBJS	= $(SRCS:.c=.o)
RM		= rm -f
CC		= gcc
CFLAGS	= -lmlx -framework OpenGL -framework AppKit

.c.o :
	$(CC) -c $< -o $@

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

all : $(TARGET)

fclean : clean
	$(RM) $(TARGET)

clean :
	$(RM) $(OBJS)

re : fclean all

.PHONY : all clean fclean re
