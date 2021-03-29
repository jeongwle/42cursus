/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:16:10 by jeongwle          #+#    #+#             */
/*   Updated: 2021/03/29 16:26:11 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_param(t_param *p)
{
	p->posx = 3.5;
	p->posy = 3.5;
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
	p->mapx = (int)p->posx;
	p->mapy = (int)p->posy;
	p->mlx = mlx_init();
	p->win = mlx_new_window(p->mlx, p->width, p->height, "cub3d");
}

int		init_buf(t_param *p, int i, int j, int k)
{
	p->buf = (int **)malloc(sizeof(int *) * p->height);
	if (p->buf == NULL)
		return (-1);
	while (++i < p->height)
	{
		p->buf[i] = (int *)malloc(sizeof(int) * p->width);
		if (p->buf[i] == NULL)
		{
			while (++k < i)
				free(p->buf[k]);
			return (-1);
		}
	}
	i = -1;
	while (++i < p->height)
	{
		j = -1;
		while (++j <p->width)
			p->buf[i][j] = 0;
	}
	return (0);
}

int		init_zbuffer(t_param *p)
{
	int i;

	i = -1;
	p->zbuffer = (double *)malloc(sizeof(double) * p->width);
	if (p->zbuffer == NULL)
		return (-1);
	while (++i < p->width)
		p->zbuffer[i] = 0;
	return (0);
}

int		init_texture(t_param *p, int i, int j, int k)
{
	p->texture = (int **)malloc(sizeof(int *) * 8);
	if (p->texture == NULL)
		return (-1);
	while (++i < 8)
	{
		p->texture[i] = (int *)malloc(sizeof(int) * (TEXHEIGHT* TEXWIDTH));
		if (p->texture[i] == NULL)
		{
			while (k < i)
			{
				free(p->texture[k]);
				k++;
			}
			return (-1);
		}
	}
	i = 0;
	while (i < 8)
	{
		j = -1;
		while (++j < TEXHEIGHT * TEXWIDTH)
			p->texture[i][j] = 0;
		i++;
	}
	return (0);
}
