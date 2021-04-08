/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <jeongwle@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 15:52:10 by jeongwle          #+#    #+#             */
/*   Updated: 2021/04/08 11:43:37 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ceiling_floor(t_param *p)
{
	int	i;
	int	j;

	i = 0;
	while (i < p->height)
	{
		j = 0;
		while (j < p->width)
		{
			if (i < p->height / 2)
				p->buf[i][j] = p->c_color;
			else
				p->buf[i][j] = p->f_color;
			j++;
		}
		i++;
	}
}

int		image_clean(t_param *p)
{
	int	i;
	int	j;

	i = 0;
	while (i < p->height)
	{
		j = 0;
		while (j < p->width)
		{
			p->data[i * p->width + j] = 0x000000;
			j++;
		}
		i++;
	}
	return (0);
}

void	draw(t_param *p)
{
	int	y;
	int	x;

	y = 0;
	while (y < p->height)
	{
		x = 0;
		while (x < p->width)
		{
			if (p->buf[y][x])
				p->data[y * p->width + x] = p->buf[y][x];
			x++;
		}
		y++;
	}
}

int		main_loop(t_param *p)
{
	image_clean(p);
	ceiling_floor(p);
	dda(p);
//	sprite_param(p);
	draw(p);
	move_player(p);
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
	return (0);
}

int		main(int argc, char *argv[])
{
	t_param p;

	if (argc == 2 || argc == 3)
	{
		check_argv_one(argv[1]);
		mlx_get_screen_size(p.mlx, &p.max_width, &p.max_height);
		init_flag(&p);
		init_texture(&p, -1, -1, 0);
		get_info(&p, 0, argv[1]);
		init_buf(&p, -1, 0, -1);
		init_zbuffer(&p);
		init_param(&p);
		load_texture(&p);
		p.img = mlx_new_image(p.mlx, p.width, p.height);
		p.data = (int *)mlx_get_data_addr(p.img, &p.bpp, &p.size_l, &p.endian);
		if (argc == 3)
			check_argv_two(&p, argv[2]);
		mlx_loop_hook(p.mlx, main_loop, &p);
		mlx_hook(p.win, 2, 0, &key_press, &p);
		mlx_hook(p.win, 3, 0, &key_release, &p);
		mlx_hook(p.win, 17, 0, &red_button, &p);
		mlx_loop(p.mlx);
	}
	else
		this_is_error(10);
}
