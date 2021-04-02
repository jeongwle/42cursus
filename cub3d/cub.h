/*************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <jeongwle@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 15:53:01 by jeongwle          #+#    #+#             */
/*   Updated: 2021/04/02 15:44:15 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# include "mlx.h"
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define KEY_ESC 53
# define MAPWIDTH 24
# define MAPHEIGHT 24
# define TEXWIDTH 64
# define TEXHEIGHT 64

typedef struct		s_sprite
{
	double	x;
	double	y;
	double	d;
}					t_sprite;

typedef struct		s_param
{
	void		*mlx;
	void		*win;
	void		*img;
	int			*data;
	int			bpp;
	int			size_l;
	int			endian;
	int			width;
	int			height;
	int			key_w;
	int			key_s;
	int			key_a;
	int			key_d;
	int			key_esc;
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	double		movespeed;
	double		rotspeed;
	double		rdirx;
	double		rdiry;
	int			index;
	int			mapx;
	int			mapy;
	double		sidedx;
	double		sidedy;
	double		deldx;
	double		deldy;
	double		camerax;
	double		walld;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	int			img_w;
	int			img_h;
	int			**buf;
	int			**texture;
	double		wallx;
	int			texx;
	int			texy;
	int			texnum;
	double		step;
	double		texpos;
	int			color;
	t_sprite	*spr;
	int			spr_count;
	double		*zbuffer;
	double		spritex;
	double		spritey;
	double		inverse;
	double		transx;
	double		transy;
	int			spr_screenx;
	int			spr_width;
	int			spr_height;
	int			spr_startx;
	int			spr_starty;
	int			spr_endx;
	int			spr_endy;
	int			spr_texx;
	int			spr_texy;
	int			spr_color;
	char		*texpath[5];
	int			c_color;
	int			f_color;
	int			r;
	int			g;
	int			b;
	int			max_width;
	int			max_height;
	int			identifier_count;
	int			r_flag;
	int			so_flag;
	int			s_flag;
	int			w_flag;
	int			n_flag;
	int			e_flag;
	int			f_flag;
	int			c_flag;
	int			map_flag;
	int			**map;
	int			map_width;
	int			map_height;
}					t_param;

int					 mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strdup(const char *s1);
char				*ft_strchr(const char *s, int c);
size_t				ft_strlen(const char *s);
int					get_next_line(int fd, char **line);
int					ft_atoi(const char *str);
int					ft_isdigit(int c);
int					ft_isalpha(int c);
char				is_space(char c);
char				**ft_split(t_param *p, char const *s, char c);
int					word_count(char const *s, char c);
size_t				word_len(char const *s, char c);
void				get_mapwidth(t_param *p, size_t size);
void				*ft_calloc(size_t count, size_t size);
int					get_info(t_param *p, int i);
void				resolution(t_param *p, char *line, int i, int flag);
void				parsing(t_param *p, char *line, int i, int fd);
void				rgb_param(t_param *p, char *line, int i, int flag);
void				rgb_param_two(t_param *p, char *line, int i, int flag);
int					rgb_calc(t_param *p, int r, int g, int b);
void				do_check(char *line, int i, int flag);
void				do_check_texture(char *line, int i, int flag);
int					error_check(int c);
int					error_check_texture(int c);
void				rgb_check(t_param *p, char *line, int i, int flag);
void				rgb_check_param(t_param *p, char *line, int i, int flag);
void				map_check(char *line, int i);
void				map_init(t_param *p);
int					get_map_size(t_param *p, char *fname, int i);
void				get_map(t_param *p, char *line, int i, int fd);
void				this_is_error(int flag);
void				if_so(t_param *p, char *line, int i);
void				if_s(t_param *p, char *line, int i);
void				if_w(t_param *p, char *line, int i);
void				if_e(t_param *p, char *line, int i);
void				if_n(t_param *p, char *line, int i);
void				init_flag(t_param *p);
void				init_param(t_param *p);
int					init_buf(t_param *p, int i, int j, int k);
int					init_zbuffer(t_param *p);
int					init_texture(t_param *p, int i, int j, int k);
int					find_sprite(t_param *p);
int					sprite_coordinate(t_param *p);
void				change_param(t_param *p, int j);
int					sprite_sort(t_param *p);
void				sprite_param_two(t_param *p, int i);
void				sprite_param(t_param *p);
int					key_press(int key, t_param *p);
int					key_release(int key, t_param *p);
int					move_player(t_param *p);
void				load_image(t_param *p, int *texture, char *path);
void				load_texture(t_param *p);
void				tex_param_two(t_param *p, int len, int start, int end);
void				tex_param(t_param *p, int len, int start, int end);
void				wall_param(t_param *p);
void				dda_param_two(t_param *p);
void				dda_param(t_param *p);
void				dda(t_param *p);

#endif
