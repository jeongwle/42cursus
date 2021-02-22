/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <jeongwle@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 03:47:41 by jeongwle          #+#    #+#             */
/*   Updated: 2021/02/22 22:18:07 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
typedef	struct	s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		width;
	int		height;
	int		row;
	int		column;
	int		grid_color;
}				t_window;

int	draw_grid(t_window *window)
{
	int	draw_position;
	int	i;

	i = 1;
	while (i < window->row)
	{
		draw_position = 0;
		while (draw_position <= window->width)
		{
			mlx_pixel_put(window->mlx_ptr, window->win_ptr, draw_position, i * (window->height / window->column), window->grid_color);
			draw_position++;
		}
		i++;
	}
	i = 1;
	while (i < window->column)
	{
		draw_position = 0 ;
		while (draw_position <= window->height)
		{
			mlx_pixel_put(window->mlx_ptr, window->win_ptr, i * (window->width / window->row), draw_position, window->grid_color);
			draw_position++;
		}
		i++;
	}
	return (0);
}

int	main(void)
{
	t_window	window;
	int			player;

	window.mlx_ptr = mlx_init();
	window.width = 500;
	window.height = 500;
	window.row = 10;
	window.column = 10;
	window.grid_color = 0x00FFFF;
	window.win_ptr = mlx_new_window(window.mlx_ptr, window.width, window.height, "fuckingcub3d");
	player = mlx_pixel_put(window.mlx_ptr, window.win_ptr, 240, 240, 0xFF0000);
	mlx_loop_hook(window.mlx_ptr, draw_grid, &window);
	mlx_loop(window.mlx_ptr);
}
