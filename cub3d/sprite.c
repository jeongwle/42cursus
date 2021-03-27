/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:48:19 by jeongwle          #+#    #+#             */
/*   Updated: 2021/03/25 12:56:59 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

extern int map[mapheight][mapwidth];

int		find_sprite(t_param *p)
{
	int	x;
	int	y;

	p->spr_count = 0;
	y = 0;
	while (y < mapheight)
	{
		x = 0;
		while (x < mapwidth)
		{
			if (map[x][y] == 2)
				p->spr_count++;
			x++;
		}
		y++;
	}
	return (p->spr_count);
}

int		sprite_coordinate(t_param *p)
{
	int		x;
	int		y;
	int		i;

	i = -1;
	p->spr = (t_sprite *)malloc(sizeof(t_sprite) * (find_sprite(p) + 1));
	if (p->spr == NULL)
		return (-1);
	y = 0;
	while (y < mapheight)
	{
		x = 0;
		while (x < mapwidth)
		{
			if (map[x][y] == 2)
			{
				p->spr[++i].x = x + 0.5;
				p->spr[i].y = y + 0.5;
				p->spr[i].d = pow((p->posx - x), 2) + pow((p->posy - y), 2);
			}
			x++;
		}
		y++;
	}
	return (0);
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
	int 	j;
	int		res;


	res = sprite_coordinate(p);
	if (res == -1)
		return (-1);
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
	p->spr_screenx = (int)(p->width / 2) * (1 + p->transx / p->transy);
	p->spr_height = (int)fabs((p->height / p->transy));
	p->spr_starty = p->height / 2 - p->spr_height / 2;
	if (p->spr_starty < 0)
		p->spr_starty = 0;
	p->spr_endy = p->height / 2 + p->spr_height / 2;
	if (p->spr_endy > p->height)
		p->spr_endy = p->height - 1;
	p->spr_width = (int)fabs((p->height / p->transy));
	p->spr_startx = p->spr_screenx - p->spr_width / 2;
	if (p->spr_startx < 0)
		p->spr_startx = 0;
	p->spr_endx = p->spr_screenx + p->spr_width / 2;
	if (p->spr_endx > p->width)
		p->spr_endx = p->width - 1;
}

void	sprite_param(t_param *p)
{
	int	i;
	int	stripe;
	int	y;
	int d;

	i = -1;
	sprite_sort(p);
	while (++i < p->spr_count)
	{
		sprite_param_two(p, i);
		stripe = p->spr_startx - 1;
		while (++stripe < p->spr_endx)
		{
			p->spr_texx = (int)((256 * (stripe - (p->spr_screenx - p->spr_width / 2)) * texwidth / p->spr_width) / 256);
			if (p->transy > 0 && stripe > 0 && stripe < p->width && p->transy < p->zbuffer[stripe])
			{
				y = p->spr_starty - 1;
				while (++y < p->spr_endy)
				{
					d = y * 256 + p->spr_height * 128 - p->height * 128;
					p->spr_texy = ((d * texheight) / p->spr_height) / 256;
					p->spr_color = p->texture[4][texwidth * p->spr_texy + p->spr_texx];
					if ((p->spr_color & 0x00FFFFFF) != 0)
						p->buf[y][stripe] = p->spr_color;
				}
			}
		}
	}
}
