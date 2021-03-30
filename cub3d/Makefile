CC		= gcc

TARGET	= cub3D

SRCS	= ./main.c \
		  ./init.c \
		  ./key.c \
		  ./sprite.c \
		  ./texture.c \
		  ./dda.c \
		  ./parsing.c \
		  ./get_next_line.c \
		  ./get_next_line_utils.c \
		  ./ft_atoi.c \
		  ./ft_isdigit.c\
		  ./parsing_func.c\
		  ./rgb.c

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
