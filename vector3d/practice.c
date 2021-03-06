/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <jeongwle@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 06:55:50 by jeongwle          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/03/07 03:37:07 by jeongwle         ###   ########.fr       */
=======
/*   Updated: 2021/03/05 17:48:49 by jeongwle         ###   ########.fr       */
>>>>>>> 114014be9fd3d610e4213c45ebd51d856ea709cd
/*                                                                            */
/* ************************************************************************** */

//#include "mlx.h"
#include "mlx_opengl.h"
#include "mlx.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#define KEY_W 13
#define KEY_S 1
#define KEY_A 0
#define KEY_D 2
#define KEY_ESC 53

typedef struct	s_window
{
	void		*mlx;
	void		*win;
	void		*img;
	int			*data;
	int			bpp;
	int			size_l;
	int			endian;
	int			map[10][10];
	int			width;
	int			height;
	int			row;
	int			col;
	int			grid_color;
	int			p_color;
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
}				t_window;

int		ray(t_window *window);
int		my_pixel_put(t_window *window, int x, int y, int color);
/*
int map[10][10] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 1, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 1, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 1, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};*/

void		init_map(t_window *window)
 {
	 int map[10][10] = {
	 	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
<<<<<<< HEAD
	 	{1, 0, 0, 1, 0, 0, 0, 0, 0, 1},
	 	{1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
	 	{1, 0, 0, 0, 1, 0, 0, 1, 1, 1},
=======
	 	{1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
	 	{1, 0, 0, 1, 0, 0, 0, 0, 0, 1},
	 	{1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
>>>>>>> 114014be9fd3d610e4213c45ebd51d856ea709cd
	 	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	 	{1, 1, 1, 1, 0, 0, 0, 0, 0, 1},
	 	{1, 0, 0, 0, 0, 0, 1, 0, 0, 1},
	 	{1, 0, 0, 0, 0, 0, 1, 0, 0, 1},
	 	{1, 0, 0, 1, 0, 0, 1, 0, 0, 1},
	 	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	 };
 	memcpy(window->map, map, sizeof(int) * 10 * 10);
 }

int		draw_map(t_window *window)
{
	int	row;
	int	col;
	int	tile_width;
	int	tile_height;
	int	x;
	int	y;

	tile_width = window->width / window->col;
	tile_height = window->height / window->row;
	col = 0;
	while (col < window->col)
	{
		row = 0;
		while (row < window->row)
		{
			if (window->map[col][row] == 1)
			{
				y = 0;
				while (y < tile_height)
				{
					x = 0;
					while (x < tile_width)
					{
						window->data[(y + (col * tile_height)) * window->width + (x + (row * tile_width))] = 0xFFFFFF;
						x++;
					}
					y++;
				}
			}
			row++;
		}
		col++;
	}
	return (0);
}
/*
int			ft_sunmin(t_window *window, t_img *img)
{
	int	tile_width;
	int	tile_height;
	int	x;
	int	y;

	tile_width = window->width / window->col;
	tile_height = window->height / window->row;

	y = 0;
	while (y < window->height)
	{
		x = 0;
		while (x < window->width)
		{
			if (map[(int)(y / tile_width)][(int)(x / tile_height)] == 1)
			{
				mlx_pixel_put(window->mlx, window->win, x, y,0xFFFFFF);
			}
			x++;
		}
		y++;
	}
	return (0);
}*/

int			draw_grid(t_window *window)
{
	int		draw_position;
	int		i;

	i = 1;
	while (i < window->row)
	{
		draw_position = 0;
		while(draw_position <= window->width)
		{
			my_pixel_put(window, draw_position, i * (window->height / window->row), window->grid_color);
			draw_position++;
		}
		i++;
	}
	i = 1;
	while (i < window->col)
	{
		draw_position = 0;
		while (draw_position <= window->height)
		{
			my_pixel_put(window, i * (window->width / window->col), draw_position, window->grid_color);
			draw_position++;
		}
		i++;
	}
	return (0);
}

int			image_clean(t_window *window)
{
	int	i;
	int	j;

	i = 0;
	while (i < window->height)
	{
		j = 0;
		while (j < window->width)
		{
			window->data[i * window->width + j] = 0x000000;
			j++;
		}
		i++;
	}
	return (0);
}

int			my_pixel_put(t_window *window, int x, int y, int color)
{
	window->data[y * window->width + x] = color;
	return (0);
}

int			key_init(t_window *window)
{
	window->key_w = 0;
	window->key_s = 0;
	window->key_a = 0;
	window->key_d = 0;
	window->key_esc = 0;
	return (0);
}
int			key_press(int key, t_window *window)
{
	if (key == KEY_W)
		window->key_w = 1;
	else if (key == KEY_S)
		window->key_s = 1;
	else if (key == KEY_A)
		window->key_a = 1;
	else if (key == KEY_D)
		window->key_d = 1;
	else if (key == KEY_ESC)
		window->key_esc = 1;
	return (0);
}

int			key_release(int key, t_window *window)
{
	if (key == KEY_W)
		window->key_w = 0;
	else if (key == KEY_S)
		window->key_s = 0;
	else if (key == KEY_A)
		window->key_a = 0;
	else if (key == KEY_D)
		window->key_d = 0;
	else if (key == KEY_ESC)
		window->key_esc = 0;
	return (0);
}
int			move_player(t_window *window)
{
	double	olddirx;
	double	oldplanex;

	if ((0 < window->posx && window->posx <= window->width) &&
			(0 < window->posy && window->posy <= window->height))
	{
		if (window->key_w)
		{
			if (!window->map[(int)(window->posx + window->dirx * window->movespeed) / 50][(int)window->posy / 50])
				window->posx += window->dirx * window->movespeed;
			if (!window->map[(int)window->posx / 50][(int)(window->posy + window->diry * window->movespeed) / 50])
				window->posy += window->diry * window->movespeed;
		}
		if (window->key_s)
		{
			if (!window->map[(int)(window->posx - window->dirx * window->movespeed) / 50][(int)window->posy / 50])
				window->posx -= window->dirx * window->movespeed;
			if (!window->map[(int)window->posx / 50][(int)(window->posy - window->diry * window->movespeed) / 50])
				window->posy -= window->diry * window->movespeed;
		}
		if (window->key_a)
		{
			olddirx = window->dirx;
			window->dirx = window->dirx * cos(window->rotspeed) - window->diry * sin(window->rotspeed);
			window->diry = olddirx * sin(window->rotspeed) + window->diry * cos(window->rotspeed);
			oldplanex = window->planex;
			window->planex = window->planex * cos(window->rotspeed) - window->planey * sin(window->rotspeed);
			window->planey = oldplanex * sin(window->rotspeed) + window->planey * cos(window->rotspeed);
		}
		if (window->key_d)
		{
			olddirx = window->dirx;
			window->dirx = window->dirx * cos(-window->rotspeed) - window->diry * sin(-window->rotspeed);
			window->diry = olddirx * sin(-window->rotspeed) + window->diry * cos(-window->rotspeed);
			oldplanex = window->planex;
			window->planex = window->planex * cos(-window->rotspeed) - window->planey * sin(-window->rotspeed);
			window->planey = oldplanex * sin(-window->rotspeed) + window->planey * cos(-window->rotspeed);
		}
		else if (window->key_esc)
			exit(0);
		if (window->posx <= 0)
			window->posx = 1;
		if (window->posy <= 0)
			window->posy = 1;
		if (window->posx > window->width)
			window->posx = window->width;
		if (window->posy > window->height)
			window->posy = window->height;
	}
	return (0);
}

int		ray(t_window *window)
{
	int	i;
	double	j;

	j = -1;
	while (j <= 1)
	{
		i = 0;
		while (i < sqrt(pow(window->width, 2) + pow(window->height, 2)))
		{
			window->rdirx = window->dirx + window->planex * j;
			window->rdiry = window->diry + window->planey * j;
			if (!window->map[(int)(window->posx + window->rdirx * i) / 50][(int)(window->posy + window->rdiry * i) / 50])
				my_pixel_put(window, (int)(window->posy + window->rdiry * i), (int)(window->posx + window->rdirx * i), 0x00FF00);
			else
				break;
			i++;
		}
		j += 0.03;
	}
	/*
	while (i < 100)
	{
		mlx_pixel_put(window->mlx, window->win, window->posy + window->diry * i, window->posx + window->dirx * i, 0x00FF00);
		i++;
	}
	while (j < 100)
<<<<<<< HEAD
player(window);
338     draw_map(wi	{
		double rdirx = window->dirx + window->planex;
		double rdiry = window->diry + window->planey;
		mlx_pixel_put(window->mlx, window->win, window->posy + rdiry * j, window->posx + rdirx * j, 0xFF0000);
=======
	{
		camera = 2 * j / 100 - 1;
		mlx_pixel_put(window->mlx, window->win, window->posy + (window->diry * (j * (k * camera))), window->posx + (window->dirx * (j * (k * camera))), 0xFFFF00);
>>>>>>> 114014be9fd3d610e4213c45ebd51d856ea709cd
		j++;
	}
	while (l < 100)
	{
		double rdirx = window->dirx - window->planex;
		double rdiry = window->diry - window->planey;
		mlx_pixel_put(window->mlx, window->win, window->posy + rdiry * l, window->posx + rdirx * l, 0x00FFFF);
		l++;
	}*/
	return (0);
}

int		ft_123(t_window *window)
{
	int	i = -5;
	int	j;
	image_clean(window);
	move_player(window);
	draw_map(window);
	ray(window);
	draw_grid(window);
	while (i <= 5)
	{
		j = -5;
		while (j <= 5)
		{
			my_pixel_put(window, window->posy + i, window->posx + j, window->p_color);
			j++;
		}
		i++;
	}	
	mlx_put_image_to_window(window->mlx, window->win, window->img, 0, 0);

	return (0);
}

int		main(void)
{
	t_window	window;

	window.width = 500;
	window.height = 500;
	window.row = 10;
	window.col = 10;
	window.grid_color = 0x00FFFF;
	window.posx = 220;
	window.posy = 220;
	window.dirx = -1;
	window.diry = 0;
	window.planex = 0;
	window.planey = 0.66;
	window.movespeed = 2;
	window.rotspeed = 0.05;
	window.rdirx = 0;
	window.rdiry = 0;
	window.p_color = 0xFF0000;
	key_init(&window);
	window.mlx = mlx_init();
	window.win = mlx_new_window(window.mlx, window.width, window.height, "draw_grid");
	init_map(&window);
	window.img = mlx_new_image(window.mlx, window.width, window.height);
	window.data = (int *)mlx_get_data_addr(window.img, &window.bpp, &window.size_l, &window.endian);
	mlx_loop_hook(window.mlx, ft_123, &window);
	mlx_hook(window.win, 2, 0, &key_press, &window);
	mlx_hook(window.win, 3, 0, &key_release, &window);
	mlx_loop(window.mlx);
}
