/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <jeongwle@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 06:55:50 by jeongwle          #+#    #+#             */
/*   Updated: 2021/02/22 21:27:07 by jeongwle         ###   ########.fr       */
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
	void	*img;
	int		*data;
	int		bpp;
	int		size_l;
	int		endian;
	int		map[10][10];
}				t_img;

typedef struct	s_player
{
	int		x;
	int		y;
	int		color;
}				t_player;

typedef struct	s_window
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	int		row;
	int		col;
	int		grid_color;
	t_player	player;
}				t_window;

void		init_map(t_img *img)
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
	memcpy(img->map, map, sizeof(int) * 10 * 10);
}

#include <stdio.h>

int		draw_map(t_window *window, t_img *img)
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
			if (img->map[col][row] == 1)
			{
				y = 0;
				while (y < tile_height)
				{
					x = 0;
					while (x < tile_width)
					{
						printf("%d %d %d %d\n", x, y, row, col);
						img->data[tile_height * y + x] = 0xFFFFFF;
						//img->data[(y + (col * tile_height)) * window->width + (x + (row * tile_width))] = 0xFFFFFF;
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
			if (img->map[(int)(y / tile_height)][(int)(x / tile_width)] == 1)
			{
				img->data[tile_height * y + x] = 0xFFFFFF;
			}
			x++;
		}
		y++;
	}
	printf("why?\n");
	return (0);
}

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

int			move_plyaer(int key, t_window *window)
{
	if ((0 < window->player.x && window->player.x <= window->width) &&
			(0 < window->player.y && window->player.y <= window->height))
	{
//		mlx_pixel_put(window->mlx, window->win, window->player.x, window->player.y, 0x000000);
		if (key == KEY_W)
			window->player.y -= 5;
		else if (key == KEY_S)
			window->player.y += 5;
		else if (key == KEY_A)
			window->player.x -= 5;
		else if (key == KEY_D)
			window->player.x += 5;
		if (window->player.x <= 0)
			window->player.x = 1;
		if (window->player.y <= 0)
			window->player.y = 1;
		if (window->player.x > window->width)
			window->player.x = window->width;
		if (window->player.y > window->height)
			window->player.y = window->height;
		mlx_pixel_put(window->mlx, window->win, window->player.x, window->player.y, window->player.color);
	}
	return (0);
}

int		ft_123(t_window *window, t_img *img)
{
	ft_sunmin(window, img);
//	draw_map(window, img);
	mlx_put_image_to_window(window->mlx, window->win, img->img, 0, 0);	
	draw_grid(window);
	mlx_pixel_put(window->mlx, window->win, window->player.x, window->player.y, window->player.color);
	return (0);
}

int		main(void)
{
	t_window	window;
	t_img		img;

	window.width = 500;
	window.height = 500;
	window.row = 10;
	window.col = 10;
	window.grid_color = 0x00FFFF;
	window.player.x = 220;
	window.player.y = 220;
	window.player.color = 0xFF0000;
	window.mlx = mlx_init();
	window.win = mlx_new_window(window.mlx, window.width, window.height, "draw_grid");
	init_map(&img);
	img.img = mlx_new_image(window.mlx, window.width, window.height);
	img.data = (int *)mlx_get_data_addr(img.img, &img.bpp, &img.size_l, &img.endian);
//	draw_map(&window, &img);
//	mlx_put_image_to_window(window.mlx, window.win, img.img, 0, 0);
	mlx_loop_hook(window.mlx, ft_123, &window);
//	mlx_pixel_put(window.mlx, window.win, window.player.x, window.player.y, window.player.color);
	mlx_key_hook(window.win, move_plyaer, &window);
	mlx_loop(window.mlx);
}
