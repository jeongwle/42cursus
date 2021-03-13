/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <jeongwle@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 15:52:10 by jeongwle          #+#    #+#             */
/*   Updated: 2021/03/12 18:58:03 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		map[mapheight][mapwidth] =
{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void	init_param(t_param *p)
{
	p->posx = 3;
	p->posy = 3;
	p->key_w = 0;
	p->key_s = 0;
	p->key_a = 0;
	p->key_d = 0;
	p->key_esc = 0;
	p->dirx = -1.0;
	p->diry = 0.0;
	p->planex = 0.0;
	p->planey = 0.66;
	p->movespeed = 0.1;
	p->rotspeed = 0.05;
	p->width = 600;
	p->height = 600;
}

int		key_press(int key, t_param *p)
{
	if (key == KEY_W)
		p->key_w = 1;
	else if (key == KEY_S)
		p->key_s = 1;
	else if (key == KEY_A)
		p->key_a = 1;
	else if (key == KEY_D)
		p->key_d = 1;
	else if (key == KEY_ESC)
		p->key_esc = 1;
	return (0);
}

int		key_release(int key, t_param *p)
{
	if (key == KEY_W)
		p->key_w = 0;
	else if (key == KEY_S)
		p->key_s = 0;
	else if (key == KEY_A)
		p->key_a = 0;
	else if (key == KEY_D)
		p->key_d = 0;
	else if (key == KEY_ESC)
		p->key_esc = 0;
	return (0);
}

int		move_player(t_param *p)
{
	double	olddirx;
	double	oldplanex;

	if ((0 < p->posx && p->posx <= p->width) &&
			(0 < p->posy && p->posy <= p->height))
	{
		if (p->key_w)
		{
			if (!map[(int)(p->posx + p->dirx * p->movespeed)][(int)p->posy])
				p->posx += p->dirx * p->movespeed;
			if (!map[(int)p->posx][(int)(p->posy + p->diry * p->movespeed)])
				p->posy += p->diry * p->movespeed;
		}
		if (p->key_s)
		{
			if (!map[(int)(p->posx - p->dirx * p->movespeed)][(int)p->posy])
				p->posx -= p->dirx * p->movespeed;
			if (!map[(int)p->posx][(int)(p->posy - p->diry * p->movespeed)])
				p->posy -= p->diry * p->movespeed;
		}
		if (p->key_a)
		{
			olddirx = p->dirx;
			p->dirx = p->dirx * cos(p->rotspeed) - p->diry * sin(p->rotspeed);
			p->diry = olddirx * sin(p->rotspeed) + p->diry * cos(p->rotspeed);
			oldplanex = p->planex;
			p->planex = p->planex * cos(p->rotspeed) - p->planey * sin(p->rotspeed);
			p->planey = oldplanex * sin(p->rotspeed) + p->planey * cos(p->rotspeed);
		}
		if (p->key_d)
		{
			olddirx = p->dirx;
			p->dirx = p->dirx * cos(-p->rotspeed) - p->diry * sin(-p->rotspeed);
			p->diry = olddirx * sin(-p->rotspeed) + p->diry * cos(-p->rotspeed);
			oldplanex = p->planex;
			p->planex = p->planex * cos(-p->rotspeed) - p->planey * sin(-p->rotspeed);
			p->planey = oldplanex * sin(-p->rotspeed) + p->planey * cos(-p->rotspeed);
		}
		else if (p->key_esc)
			exit(0);
		if (p->posx <= 0)
			p->posx = 1;
		if (p->posy <= 0)
			p->posy = 1;
		if (p->posx > p->width)
			p->posx = p->width;
		if (p->posy > p->height)
			p->posy = p->height;
	}
	return (0);
}

void	wall_param(t_param *p)
{
	int	len;
	int	start;
	int	end;

	len = (int)(p->height / p->walld);
	start = p->height / 2 - len / 2;
	if (start < 0)
		start = 0;
	end = p->height / 2 + len / 2;
	if (end >= p->height)
		end = p->height - 1;
	while (start < end)
	{
		mlx_pixel_put(p->mlx, p->win, p->index, start, 0x00FF00);
		start++;
	}
}

void	DDA_param_two(t_param *p)
{
	if (p->rdirx < 0)
	{
		p->stepx = -1;
		p->sidedx = (p->posx - p->mapx) * p->deldx;
	}
	else
	{
		p->stepx = 1;
		p->sidedx = (p->mapx + 1.0 - p->posx) * p->deldx;
	}
	if (p->rdiry < 0)
	{
		p->stepy = -1;
		p->sidedy = (p->posy - p->mapy) * p->deldy;
	}
	else
	{
		p->stepy = -1;
		p->sidedy = (p->mapy + 1.0 - p->posy) * p->deldy;
	}
}

void	DDA_param(t_param *p)
{
		p->camerax = 2 * p->index / p->width - 1;
		p->rdirx = p->dirx + p->planex * p->camerax;
		p->rdiry = p->diry + p->planey * p->camerax;
		p->mapx = (int)p->posx;
		p->mapy = (int)p->posy;
		p->deldx = fabs(1 / p->rdirx);
		p->deldy = fabs(1 / p->rdiry);
		p->hit = 0;
		DDA_param_two(p);
}

void	DDA(t_param *p)
{
	p->index = -1;
	while (++p->index < p->width)
	{
		DDA_param(p);
		while (p->hit == 0)
		{
			if (p->sidedx < p->sidedy)
			{
				p->sidedx += p->deldx;
				p->mapx += p->stepx;
				p->side = 0;
			}
			else
			{
				p->sidedy += p->deldy;
				p->mapy += p->stepy;
				p->side = 1;
			}
			if (map[p->mapx][p->mapy] > 0)
				p->hit = 1;
		}
		if (p->side == 0)
			p->walld = (p->mapx - p->posx + (1 - p->stepx) / 2) / p->rdirx;
		else
			p->walld = (p->mapy - p->posy + (1 - p->stepy) / 2) / p->rdiry;
		wall_param(p);
	}
}

int		main_loop(t_param *p)
{
	DDA(p);
	move_player(p);
	return (0);
}

int		main(void)
{
	t_param p;

	init_param(&p);
	p.mlx = mlx_init();
	p.win = mlx_new_window(p.mlx, p.width, p.height, "cub3d");
	mlx_loop_hook(p.mlx, main_loop, &p);
	mlx_hook(p.win, 2, 0, &key_press, &p);
	mlx_hook(p.win, 3, 0, &key_release, &p);
	mlx_loop(p.win);


}
