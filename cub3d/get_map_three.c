/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 10:06:30 by jeongwle          #+#    #+#             */
/*   Updated: 2021/04/07 10:22:26 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	map_size_sub(t_param *p, char *line, int i, char param)
{
	map_check(line, i);
	p->map_height++;
	if (p->map_width < (int)word_len(line, param))
		p->map_width = word_len(line, param);
}

void	getmap_two_sub(t_param *p, char *line, int j)
{
	int	l;
	int	k;

	l = -1;
	k = 0;
	while (++l < (int)word_len(line, '\0'))
	{
		if (ft_isdigit(line[l]))
			p->map[j][k] = line[l] - '0';
		else if (is_news(line[l]))
			player_dir(p, line[l], j, k);
		k++;
	}
}
