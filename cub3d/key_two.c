/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_two.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 19:45:52 by jeongwle          #+#    #+#             */
/*   Updated: 2021/04/05 19:57:51 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	move_player_sub(t_param *p)
{
	if (p->key_a)
	{
		if (!p->map[(int)p->posx][(int)(p->posy + p->dirx * p->movespeed)])
			p->posy += p->dirx * p->movespeed;
		if (!p->map[(int)(p->posx - p->diry * p->movespeed)][(int)p->posy])
			p->posx -= p->diry * p->movespeed;
	}
	if (p->key_d)
	{
		if (!p->map[(int)p->posx][(int)(p->posy - p->dirx * p->movespeed)])
			p->posy -= p->dirx * p->movespeed;
		if (!p->map[(int)(p->posx + p->diry * p->movespeed)][(int)p->posy])
			p->posx += p->diry * p->movespeed;
	}
}

void	move_player_sub_two(t_param *p)
{
	double	olddx;
	double	oldpx;

	if (p->key_left)
	{
		olddx = p->dirx;
		p->dirx = p->dirx * cos(p->rotspeed) - p->diry * sin(p->rotspeed);
		p->diry = olddx * sin(p->rotspeed) + p->diry * cos(p->rotspeed);
		oldpx = p->planex;
		p->planex = p->planex * cos(p->rotspeed) - p->planey * sin(p->rotspeed);
		p->planey = oldpx * sin(p->rotspeed) + p->planey * cos(p->rotspeed);
	}
	if (p->key_right)
	{
		olddx = p->dirx;
		p->dirx = p->dirx * cos(-p->rotspeed) - p->diry * sin(-p->rotspeed);
		p->diry = olddx * sin(-p->rotspeed) + p->diry * cos(-p->rotspeed);
		oldpx = p->planex;
		p->planex = p->planex * cos(-p->rotspeed)
		- p->planey * sin(-p->rotspeed);
		p->planey = oldpx * sin(-p->rotspeed) + p->planey * cos(-p->rotspeed);
	}
}
