/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <jeongwle@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 06:55:50 by jeongwle          #+#    #+#             */
/*   Updated: 2021/03/01 22:36:00 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx/mlx.h"
#include <stdlib.h>
#include <string.h>
#define KEY_W 13
#define KEY_S 1
#define KEY_A 0
#define KEY_D 2

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
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
}				t_window;

int		sujicsun(int key, t_window *window);
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

int			move_player(int key, t_window *window)
{
	if ((0 < window->posx && window->posx <= window->width) &&
			(0 < window->posy && window->posy <= window->height))
	{
//		mlx_pixel_put(window->mlx, window->win, window->player.x, window->player.y, 0x000000);
		if (key == KEY_W)
			window->posy -= 5;
		else if (key == KEY_S)
			window->posy += 5;
		else if (key == KEY_A)
			window->posx -= 5;
		else if (key == KEY_D)
			window->posx += 5;
		else if (key == 53)
			exit(0);
		if (window->posx <= 0)
			window->posx = 1;
		if (window->posy <= 0)
			window->posy = 1;
		if (window->posx > window->width)
			window->posx = window->width;
		if (window->posy > window->height)
			window->posy = window->height;
		mlx_pixel_put(window->mlx, window->win, window->posx, window->posy, window->p_color);
		sujicsun(key, window);
	}
	return (0);
}

int		sujicsun(int key, t_window *window)
{
	int	i;
	int j;

	i = window->posy - 1;
	if (key == KEY_W)
	{
		i = window->posy - 1;
		while (i > window->posy - 10)
		{
			mlx_pixel_put(window->mlx, window->win, window->posx, i, 0x00FF00);
			i--;
		}
	}
	else if (key == KEY_S)
	{
		i = window->posy + 1;
		while (i < window->posy + 10)
		{
			mlx_pixel_put(window->mlx, window->win, window->posx, i, 0x00FF00);
			i++;
		}
	}
	else if (key == KEY_A)
	{
		j = window->posx - 1;
		while (j > window->posx - 10)
		{
			mlx_pixel_put(window->mlx, window->win, j, window->posy, 0x00FF00);
			j--;
		}
	}
	else if (key == KEY_D)
	{
		j = window->posx + 1;
		while (j < window->posx + 10)
		{
			mlx_pixel_put(window->mlx, window->win, j, window->posy, 0x00FF00);
			j++;
		}
	}
	return (0);
}

int		ft_123(t_window *window)
{
//	ft_sunmin(window, img);
	draw_map(window);
	mlx_put_image_to_window(window->mlx, window->win, window->img, 0, 0);
	draw_grid(window);
	mlx_pixel_put(window->mlx, window->win, window->posx, window->posy, window->p_color);

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
	window.p_color = 0xFF0000;
	window.mlx = mlx_init();
	window.win = mlx_new_window(window.mlx, window.width, window.height, "draw_grid");
	init_map(&window);
	window.img = mlx_new_image(window.mlx, window.width, window.height);
	window.data = (int *)mlx_get_data_addr(window.img, &window.bpp, &window.size_l, &window.endian);
//	draw_map(&window, &img);
//	mlx_put_image_to_window(window.mlx, window.win, img.img, 0, 0);
	mlx_loop_hook(window.mlx, ft_123, &window);
//	mlx_pixel_put(window.mlx, window.win, window.player.x, window.player.y, window.player.color);
	mlx_key_hook(window.win, &move_player, &window);
	mlx_loop(window.mlx);
}
