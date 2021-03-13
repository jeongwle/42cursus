/* *i************************************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <jeongwle@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 15:53:01 by jeongwle          #+#    #+#             */
/*   Updated: 2021/03/13 17:50:46 by jeongwle         ###   ########.fr       */
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
}				t_param;
#endif
