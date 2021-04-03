/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 11:59:06 by jeongwle          #+#    #+#             */
/*   Updated: 2021/04/03 17:38:56 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		is_news(int c)
{
	return (c == 'N' || c == 'E' || c == 'W' || c == 'S');
}

size_t	word_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*(s + len) != c && *(s + len))
		len++;
	return (len);
}

void	player_dir(t_param *p, char c, int j, int k)
{
	p->dirx = 0.0;
	p->diry = 0.0;
	p->planex = 0.0;
	p->planey = 0.66;
	p->map[j][k] = 0;
	p->posx = j + 0.5;
	p->posy = k + 0.5;
	
	if (c == 'N')
		p->dirx = -1.0;
	else if (c == 'S')
	{
		p->dirx = 1.0;
		p->planey = -0.66;
	}
	else if (c == 'W')
	{
		p->diry = -1.0;
		p->planex = -0.66;
		p->planey = 0;
	}
	else if (c == 'E')
	{
		p->diry = 1.0;
		p->planex = 0.66;
		p->planey = 0.0;
	}
}
