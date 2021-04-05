/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:48:19 by jeongwle          #+#    #+#             */
/*   Updated: 2021/04/05 21:15:54 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		find_sprite(t_param *p)
{
	int	x;
	int	y;

	p->spr_count = 0;
	y = 0;
	while (y < p->map_width)
	{
		x = 0;
		while (x < p->map_height)
		{
			if (p->map[x][y] == 2)
				p->spr_count++;
			x++;
		}
		y++;
	}
	return (p->spr_count);
}

void	sprite_coordinate(t_param *p)
{
	int		x;
	int		y;
	int		i;

	i = -1;
	y = 0;
	while (y < p->map_width)
	{
		x = 0;
		while (x < p->map_height)
		{
			if (p->map[x][y] == 2)
			{
				p->spr[++i].x = x + 0.5;
				p->spr[i].y = y + 0.5;
				p->spr[i].d = pow((p->posx - x), 2) + pow((p->posy - y), 2);
			}
			x++;
		}
		y++;
	}
}

void	change_param(t_param *p, int j)
{
	double	temp;

	temp = p->spr[j].x;
	p->spr[j].x = p->spr[j + 1].x;
	p->spr[j + 1].x = temp;
	temp = p->spr[j].y;
	p->spr[j].y = p->spr[j + 1].y;
	p->spr[j + 1].y = temp;
	temp = p->spr[j].d;
	p->spr[j].d = p->spr[j + 1].d;
	p->spr[j + 1].d = temp;
}

int		sprite_sort(t_param *p)
{
	int		i;
	int		j;

	sprite_coordinate(p);
	i = 0;
	while (i < p->spr_count - 1)
	{
		j = 0;
		while (j < p->spr_count - i - 1)
		{
			if (p->spr[j].d < p->spr[j + 1].d)
				change_param(p, j);
			j++;
		}
		i++;
	}
	return (0);
}

void	sprite_param_two(t_param *p, int i)
{
	p->spritex = p->spr[i].x - p->posx;
	p->spritey = p->spr[i].y - p->posy;
	p->inverse = 1.0 / (p->planex * p->diry - p->dirx * p->planey);
	p->transx = p->inverse * (p->diry * p->spritex - p->dirx * p->spritey);
	p->transy = p->inverse * (-p->planey * p->spritex + p->planex * p->spritey);
	p->spr_screenx = (int)((p->width / 2) * (1 + p->transx / p->transy));
	p->spr_height = (int)(fabs((p->height / p->transy)));
	p->spr_starty = p->height / 2 - p->spr_height / 2;
	if (p->spr_starty < 0)
		p->spr_starty = 0;
	p->spr_endy = p->height / 2 + p->spr_height / 2;
	if (p->spr_endy > p->height)
		p->spr_endy = p->height - 1;
	p->spr_width = (int)(fabs((p->height / p->transy)));
	p->spr_startx = p->spr_screenx - p->spr_width / 2;
	if (p->spr_startx < 0)
		p->spr_startx = 0;
	p->spr_endx = p->spr_screenx + p->spr_width / 2;
	if (p->spr_endx > p->width)
		p->spr_endx = p->width - 1;
}
