/* *i************************************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <jeongwle@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 15:53:01 by jeongwle          #+#    #+#             */
/*   Updated: 2021/03/23 15:04:21 by jeongwle         ###   ########.fr       */
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

typedef struct	s_sprite
{
	double	x;
	double	y;
	double	d;
}				t_sprite;

typedef struct s_param
{
	void	*mlx;
	void	*win;
	void	*img;
	int		*data;
	int		bpp;
	int		size_l;
	int		endian;
	int		width;
	int		height;
	int		key_w;
	int		key_s;
	int		key_a;
	int		key_d;
	int		key_esc;
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	double	movespeed;
	double	rotspeed;
	double	rdirx;
	double	rdiry;
	int		index;
	int		mapx;
	int		mapy;
	double	sidedx;
	double	sidedy;
	double	deldx;
	double	deldy;
	double	camerax;
	double	walld;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	int		img_w;
	int		img_h;
	int		buf[bufheight][bufwidth];
	int		**texture;
	double	wallx;
	int		texx;
	int		texy;
	int		texnum;
	double	step;
	double	texpos;
	int		color;
	t_sprite	*spr;
	int		spr_count;
	double	zbuffer[bufwidth];
	double	spritex;
	double	spritey;
	double	inverse;
	double	transx;
	double	transy;
	int		spr_screenx;
	int		spr_width;
	int		spr_height;
	int		spr_startx;
	int		spr_starty;
	int		spr_endx;
	int		spr_endy;
	int		spr_texx;
	int		spr_texy;
	int		spr_color;
}				t_param;

#endif
