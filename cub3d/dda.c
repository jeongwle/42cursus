/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:22:08 by jeongwle          #+#    #+#             */
/*   Updated: 2021/03/25 12:57:51 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

extern int map[mapheight][mapwidth];

void	wall_param(t_param *p)
{
	int	len;
	int	start;
	int	end;

	if (p->side == 0)
		p->walld = (p->mapx - p->posx + (1 - p->stepx) / 2) / p->rdirx;
	else
		p->walld = (p->mapy - p->posy + (1 - p->stepy) / 2) / p->rdiry;
	p->zbuffer[p->index] = p->walld;
	len = (int)(p->height / p->walld);
	start = p->height / 2 - len / 2;
	if (start < 0)
		start = 0;
	end = p->height / 2 + len / 2;
	if (end >= p->height)
		end = p->height;
	tex_param(p, len, start, end);
//	while (start < end)
//	{
//		my_pixel_put(p, p->index, start, 0x0000FF);
//		start++;
//	}
}

void	dda_param_two(t_param *p)
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
		p->stepy = 1;
		p->sidedy = (p->mapy + 1.0 - p->posy) * p->deldy;
	}
}

void	dda_param(t_param *p)
{
		p->camerax = 2 * p->index / (double)p->width - 1;
		p->rdirx = p->dirx + p->planex * p->camerax;
		p->rdiry = p->diry + p->planey * p->camerax;
		p->mapx = (int)p->posx;
		p->mapy = (int)p->posy;
		p->deldx = fabs(1 / p->rdirx);
		p->deldy = fabs(1 / p->rdiry);
		p->hit = 0;
		dda_param_two(p);
}

void	dda(t_param *p)
{
	p->index = -1;
	while (++p->index < p->width)
	{
		dda_param(p);
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
			if (map[p->mapx][p->mapy] == 1)
				p->hit = 1;
		}
		wall_param(p);
	}
}
