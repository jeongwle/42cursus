/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <jeongwle@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 15:52:10 by jeongwle          #+#    #+#             */
/*   Updated: 2021/03/24 16:42:43 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		map[mapheight][mapwidth] =
{
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};

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
	p->width = 640;
	p->height = 480;
	p->mapx = (int)p->posx;
	p->mapy = (int)p->posy;
	p->mlx = mlx_init();
	p->win = mlx_new_window(p->mlx, p->width, p->height, "cub3d");
}


void	init_buf(t_param *p)
{
	int	i;
	int	j;

	i = 0;
	while (i < p->height)
	{
		j = 0;
		while (j <p->width)
		{
			p->buf[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	ceiling_floor(t_param *p)
{
	int	i;
	int	j;

	i = 0;
	while (i < p->height)
	{
		j = 0;
		while (j <p->width)
		{
			if (i < p->height / 2)
				p->buf[i][j] = 0x0000FF;
			else
				p->buf[i][j] = 0x00FF00;
			j++;
		}
		i++;
	}
}

int		init_texture(t_param *p, int i, int j, int k)
{
	p->texture = (int **)malloc(sizeof(int *) * 8);
	if (p->texture == NULL)
		return (-1);
	while (++i < 8)
	{
		p->texture[i] = (int *)malloc(sizeof(int) * (texheight* texwidth));
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
		while (++j < texheight * texwidth)
			p->texture[i][j] = 0;
		i++;
	}
	return (0);
}

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

int		my_pixel_put(t_param *p, int x, int y, int color)
{
	p->data[y * p->width + x] = color;
	return (0);
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
				p->data[y * p->width +x] = p->buf[y][x];
			x++;
		}
		y++;
	}
}

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
		p->stepy = 1;
		p->sidedy = (p->mapy + 1.0 - p->posy) * p->deldy;
	}
}

void	DDA_param(t_param *p)
{
		p->camerax = 2 * p->index / (double)p->width - 1;
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
			if (map[p->mapx][p->mapy] == 1)
				p->hit = 1;
		}
		wall_param(p);
	}
}

int		main_loop(t_param *p)
{
	int	i;
	int	j;

	image_clean(p);
//	mlx_clear_window(p->mlx, p->win);
	ceiling_floor(p);
	DDA(p);
	sprite_param(p);
	draw(p);
	move_player(p);
	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			my_pixel_put(p, p->posy * 25 + i, p->posx * 25 + j, 0x00FF00);
			j++;
		}
		i++;
	}
//	printf("%f %f \n", p->dirx, p->diry);
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
	return (0);
}

int		main(void)
{
	t_param p;

	init_param(&p);
	init_buf(&p);
	init_texture(&p, -1, -1, 0);
	load_texture(&p);
	p.img = mlx_new_image(p.mlx, p.width, p.height);
	p.data = (int *)mlx_get_data_addr(p.img, &p.bpp, &p.size_l, &p.endian);
	mlx_loop_hook(p.mlx, main_loop, &p);
	mlx_hook(p.win, 2, 0, &key_press, &p);
	mlx_hook(p.win, 3, 0, &key_release, &p);
	mlx_loop(p.mlx);
}
