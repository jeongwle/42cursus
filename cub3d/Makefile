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
		  ./utils.c \
		  ./parsing_func.c \
		  ./rgb.c \
		  ./error_check.c \
		  ./get_map.c \
		  ./get_map_two.c \
		  ./check_map.c

OBJS	= $(SRCS:.c=.o)
RM		= rm -f
CC		= gcc
CFLAGS	= -lmlx -framework OpenGL -framework AppKit

.c.o :
	$(CC) -c $< -o $@

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -fsanitize=address -o $@ $^ ./libmlx.dylib

all : $(TARGET)

fclean : clean
	$(RM) $(TARGET)

clean :
	$(RM) $(OBJS)

re : fclean all

.PHONY : all clean fclean re
