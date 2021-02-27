/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 00:45:35 by jeongwle          #+#    #+#             */
/*   Updated: 2021/02/24 03:03:07 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <string.h>
#define KEY_W 13
#define KEY_S 1
#define KEY_A 0
#define KEY_D 2

typedef struct	s_img
{
	void		*img;
	int			*data;
	int			bpp;
	int			size_l;
	int			endian;
	int			map[10][10];
}				t_img;

typedef struct	s_player
{
	int			x;
	int			y;
	int			color;
}				t_player;

typedef struct	s_window
{
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	int			row;
	int			col;
	int			grid_color;
	t_player	player;
}				t_window;
