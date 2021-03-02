/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <jeongwle@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 06:55:50 by jeongwle          #+#    #+#             */
/*   Updated: 2021/03/03 04:10:37 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx/mlx.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>
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
}				t_window;

int		sujicsun(t_window *window);
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
	 	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	 	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	 	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	 	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	 	{1, 1, 1, 1, 0, 0, 0, 0, 0, 1},
	 	{1, 0, 0, 0, 0, 0, 1, 0, 0, 1},
	 	{1, 0, 0, 0, 0, 0, 1, 0, 0, 1},
	 	{1, 0, 0, 0, 0, 0, 1, 0, 0, 1},
	 	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	 };
 	memcpy(window->map, map, sizeof(int) * 10 * 10);
 }

#include <stdio.h>

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
			mlx_pixel_put(window->mlx, window->win, draw_position, i * (window->height / window->row), window->grid_color);
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
			mlx_pixel_put(window->mlx, window->win, i * (window->width / window->col), draw_position, window->grid_color);
			draw_position++;
		}
		i++;
	}
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
	if ((0 < window->posx && window->posx <= window->width) &&
			(0 < window->posy && window->posy <= window->height))
	{
//		mlx_pixel_put(window->mlx, window->win, window->player.x, window->player.y, 0x000000);
/*		if (key == KEY_W)
			window->posy -= 5;
		else if (key == KEY_S)
			window->posy += 5;
		else if (key == KEY_A)
			window->posx -= 5;
		else if (key == KEY_D)
			window->posx += 5;*/
		if (window->key_w)
		{
			window->posx += window->dirx * window->movespeed;
			window->posy += window->diry * window->movespeed;
		}
		if (window->key_s)
		{
			window->posx -= window->dirx * window->movespeed;
			window->posy -= window->diry * window->movespeed;
		}
		if (window->key_a)
		{
			double olddirx = window->dirx;
			window->dirx = window->dirx * cos(window->rotspeed) - window->diry * sin(window->rotspeed);
			window->diry = olddirx * sin(window->rotspeed) + window->diry * cos(window->rotspeed);
		}
		if (window->key_d)
		{
			double olddirx = window->dirx;
			window->dirx = window->dirx * cos(-window->rotspeed) - window->diry * sin(-window->rotspeed);
			window->diry = olddirx * sin(-window->rotspeed) + window->diry * cos(-window->rotspeed);
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
#include <stdio.h>

int		sujicsun(t_window *window)
{
	int	i;
	int	j;
	double	k;
	double	camera;

	i = 0;
	j = 0;
	k = window->planey;
	while (i < 100)
	{
		mlx_pixel_put(window->mlx, window->win, window->posy + window->diry * i, window->posx + window->dirx * i, 0x00FF00);
		i++;
	}
	while (j < 100)
	{
		camera = 2 * j / 100 - 1;
		mlx_pixel_put(window->mlx, window->win, window->posy + (window->diry + (j * (k * camera))), window->posx + (window->dirx + (j * (k * camera))), 0x00FF00);
		j++;
	}
	return (0);
}

int		ft_123(t_window *window)
{
	int	i = -5;
	int	j;
//	ft_sunmin(window, img);
	move_player(window);
	draw_map(window);
	mlx_put_image_to_window(window->mlx, window->win, window->img, 0, 0);
	draw_grid(window);
	while (i <= 5)
	{
		j = -5;
		while (j <= 5)
		{
			mlx_pixel_put(window->mlx, window->win, window->posy + i, window->posx + j, window->p_color);
			j++;
		}
		i++;
	}
	sujicsun(window);
//	mlx_pixel_put(window->mlx, window->win, window->posx, window->posy, window->p_color);

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
//	window.player.x = 220;
//	window.player.y = 220;
	window.posx = 220;
	window.posy = 220;
	window.dirx = -1;
	window.diry = 0;
	window.planex = 0;
	window.planey = 0.66;
	window.movespeed = 2;
	window.rotspeed = 0.05;
	window.p_color = 0xFF0000;
	key_init(&window);
	window.mlx = mlx_init();
	window.win = mlx_new_window(window.mlx, window.width, window.height, "draw_grid");
	init_map(&window);
	window.img = mlx_new_image(window.mlx, window.width, window.height);
	window.data = (int *)mlx_get_data_addr(window.img, &window.bpp, &window.size_l, &window.endian);
//	draw_map(&window, &img);
//	mlx_put_image_to_window(window.mlx, window.win, img.img, 0, 0);
	mlx_loop_hook(window.mlx, ft_123, &window);
//	mlx_pixel_put(window.mlx, window.win, window.player.x, window.player.y, window.player.color);
	mlx_hook(window.win, 2, 0, &key_press, &window);
	mlx_hook(window.win, 3, 0, &key_release, &window);
	mlx_loop(window.mlx);
}
