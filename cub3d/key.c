/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:22:58 by jeongwle          #+#    #+#             */
/*   Updated: 2021/04/05 19:56:04 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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
	else if (key == KEY_LEFT)
		p->key_left = 1;
	else if (key == KEY_RIGHT)
		p->key_right = 1;
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
	else if (key == KEY_LEFT)
		p->key_left = 0;
	else if (key == KEY_RIGHT)
		p->key_right = 0;
	else if (key == KEY_ESC)
		p->key_esc = 0;
	return (0);
}

int		red_button(void *param)
{
	(void)param;
	exit(0);
}

int		move_player(t_param *p)
{
	if ((0 < p->posx && p->posx <= p->width) &&
	(0 < p->posy && p->posy <= p->height))
	{
		if (p->key_w)
		{
			if (!p->map[(int)(p->posx + p->dirx * p->movespeed)][(int)p->posy])
				p->posx += p->dirx * p->movespeed;
			if (!p->map[(int)p->posx][(int)(p->posy + p->diry * p->movespeed)])
				p->posy += p->diry * p->movespeed;
		}
		if (p->key_s)
		{
			if (!p->map[(int)(p->posx - p->dirx * p->movespeed)][(int)p->posy])
				p->posx -= p->dirx * p->movespeed;
			if (!p->map[(int)p->posx][(int)(p->posy - p->diry * p->movespeed)])
				p->posy -= p->diry * p->movespeed;
		}
		move_player_sub(p);
		move_player_sub_two(p);
		if (p->key_esc)
			exit(0);
	}
	return (0);
}
