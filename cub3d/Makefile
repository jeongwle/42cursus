NAME	= cub3D

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
CC		= gcc -Wall -Wextra -Werror
C		= clang
CFLAGS	= -lmlx -framework OpenGL -framework AppKit

.c.o :
	$(CC) -c $< -o $@

$(NAME) : $(OBJS)
	make -C ./mlx_mms
	make -C ./mlx
	cp ./mlx_mms/libmlx.dylib ./
	$(CC) $(CFLAGS) -o $@ $^ ./libmlx.dylib

all : $(NAME)

fclean : clean
	$(RM) $(NAME)

clean :
	$(RM) $(OBJS)
	$(RM) ./libmlx.dylib
	make clean -C ./mlx_mms
	make clean -C ./mlx

re : fclean all

.PHONY : all clean fclean re
