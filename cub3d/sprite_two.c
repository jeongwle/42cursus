/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 21:00:33 by jeongwle          #+#    #+#             */
/*   Updated: 2021/04/06 09:50:34 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	sprite_param_sub(t_param *p, int stripe, int y)
{
	int	d;

	p->spr_texx = (int)(256 * (stripe - (p->spr_screenx - p->spr_width / 2))
	* TEXWIDTH / p->spr_width) / 256;
	if (p->transy > 0 && stripe > 0 && stripe < p->width &&
	p->transy < p->zbuffer[stripe])
	{
		y = p->spr_starty - 1;
		while (++y < p->spr_endy)
		{
			d = y * 256 + p->spr_height * 128 - p->height * 128;
			p->spr_texy = ((d * TEXHEIGHT) / p->spr_height) / 256;
			p->spr_color = p->texture[4][TEXWIDTH * p->spr_texy + p->spr_texx];
			if ((p->spr_color & 0x00FFFFFF) != 0)
				p->buf[y][stripe] = p->spr_color;
		}
	}
}

void	sprite_param(t_param *p)
{
	int	i;
	int	stripe;
	int	y;

	i = -1;
	y = 0;
	sprite_sort(p);
	while (++i < p->spr_count)
	{
		sprite_param_two(p, i);
		stripe = p->spr_startx - 1;
		while (++stripe < p->spr_endx)
			sprite_param_sub(p, stripe, y);
	}
}
