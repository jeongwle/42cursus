/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <jeongwle@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 15:53:01 by jeongwle          #+#    #+#             */
/*   Updated: 2021/03/25 12:39:55 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "mlx.h"
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <stdio.h>

# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define KEY_ESC 53
# define mapwidth 24
# define mapheight 24
# define texwidth 64
# define texheight 64
# define bufwidth 640
# define bufheight 480

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
	int			buf[bufheight][bufwidth];
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
	double		zbuffer[bufwidth];
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
}					t_param;
/*
char				**ft_split(char const *s, char c);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strdup(const char *s1);
char				*ft_strchr(const char *s, int c);
size_t				ft_strlen(const char *s);
int					get_next_line(int fd, char **line);
void				init_param(t_param *p);
void				init_buf(t_param *p);
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
*/
#endif
