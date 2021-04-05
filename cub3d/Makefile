CC		= gcc

TARGET	= cub3D

SRCS	= ./main.c \
		  ./init.c \
		  ./key.c \
		  ./key_two.c \
		  ./sprite.c \
		  ./sprite_two.c \
		  ./texture.c \
		  ./dda.c \
		  ./parsing.c \
		  ./get_next_line.c \
		  ./utils.c \
		  ./utils_two.c \
		  ./parsing_func.c \
		  ./rgb.c \
		  ./error_check.c \
		  ./get_map.c \
		  ./get_map_two.c \
		  ./check_map.c \
		  ./bmp.c \
		  ./check_argv.c

OBJS	= $(SRCS:.c=.o)
RM		= rm -f
CC		= gcc
CFLAGS	= -lmlx -framework OpenGL -framework AppKit

.c.o :
	$(CC) -c $< -o $@

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ ./libmlx.dylib

all : $(TARGET)

fclean : clean
	$(RM) $(TARGET)

clean :
	$(RM) $(OBJS)

re : fclean all

.PHONY : all clean fclean re
