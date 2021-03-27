/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:20:12 by jeongwle          #+#    #+#             */
/*   Updated: 2021/03/25 12:57:30 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

extern int map[mapheight][mapwidth];

void	load_image(t_param *p, int *texture, char *path)
{
	int	x;
	int	y;

	p->img = mlx_xpm_file_to_image(p->mlx, path, &p->img_w, &p->img_h);
	p->data = (int *)mlx_get_data_addr(p->img, &p->bpp, &p->size_l, &p->endian);
	y = 0;
	while (y < p->img_h)
	{
		x = 0;
		while (x < p->img_w)
		{
			texture[p->img_w * y + x] = p->data[p->img_w * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(p->mlx, p->img);
}

void	load_texture(t_param *p)
{
	load_image(p, p->texture[0], "textures/no.xpm");
	load_image(p, p->texture[1], "textures/so.xpm");
	load_image(p, p->texture[2], "textures/ea.xpm");
	load_image(p, p->texture[3], "textures/we.xpm");
	load_image(p, p->texture[4], "textures/s.xpm");
}

/*
void	load_texture(t_param *p)
{
	load_image(p, p->texture[0], "textures/eagle.xpm");
	load_image(p, p->texture[1], "textures/redbrick.xpm");
	load_image(p, p->texture[2], "textures/purplestone.xpm");
	load_image(p, p->texture[3], "textures/greystone.xpm");
	load_image(p, p->texture[4], "textures/bluestone.xpm");
	load_image(p, p->texture[5], "textures/mossy.xpm");
	load_image(p, p->texture[6], "textures/wood.xpm");
	load_image(p, p->texture[7], "textures/colorstone.xpm");
}*/

void	tex_param_two(t_param *p, int len, int start, int end)
{
	int	i;

	i = start;
	while (i < end)
	{
		p->texy = (int)p->texpos & (texheight - 1);
		p->texpos += p->step;
//		p->color = p->texture[p->texnum][texheight * p->texy + p->texx];
		if (map[p->mapx][p->mapy] == 1)
		{
			if (p->side == 0 && p->rdirx < 0)
				p->color = p->texture[0][texheight * p->texy + p->texx];
			else if (p->side == 0 && p->rdirx > 0)
				p->color = p->texture[1][texheight * p->texy + p->texx];
			else if (p->side == 1 && p->rdiry > 0)
				p->color = p->texture[2][texheight * p->texy + p->texx];
			else if (p->side == 1 && p->rdiry < 0)
				p->color = p->texture[3][texheight * p->texy + p->texx];
			p->buf[i][p->index] = p->color;
		}
		i++;
	}
}

void	tex_param(t_param *p, int len, int start, int end)
{
	p->texnum = map[p->mapx][p->mapy] - 1;
	if (p->side == 0)
		p->wallx = p->posy + p->walld * p->rdiry;
	else
		p->wallx = p->posx + p->walld * p->rdirx;
	p->wallx -= floor(p->wallx);
	p->texx = (int)(p->wallx * (double)texwidth);
	if (p->side == 0 && p->rdirx > 0)
		p->texx = texwidth - p->texx - 1;
	if (p->side == 1 && p->rdiry < 0)
		p->texx = texwidth - p->texx - 1;
	p->step = 1.0 * texheight / len;
	p->texpos = (start - p->height / 2 + len / 2) * p->step;
	tex_param_two(p, len, start, end);
}
