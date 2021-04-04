/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 17:19:17 by jeongwle          #+#    #+#             */
/*   Updated: 2021/04/04 15:35:02 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	check_map(t_param *p)
{
	int	i;
	int j;

	i = 0;
	while (i < p->map_height)
	{
		j = 0;
		while (j < p->map_width)
		{
			if (p->map[i][j] == 0 || is_news(p->map[i][j]) || p->map[i][j] == 2)
			{
				check_right(p, i, j);
				check_left(p, i, j);
				check_up(p, i, j);
				check_down(p, i, j);
			}
			j++;
		}
		i++;
	}
}

void	check_right(t_param *p, int i , int j)
{
	while (j < p->map_width)
	{
		if (p->map[i][j] == ' ')
			this_is_error(9);
		if (p->map[i][j] == 1)
			return ;
		j++;
	}
	if (p->map[i][j] != 1 && j == p->map_width)
		this_is_error(9);
}

void	check_left(t_param *p, int i, int j)
{
	while (0 < j)
	{
		if (p->map[i][j] == ' ')
			this_is_error(9);
		if (p->map[i][j] == 1)
			return ;
		j--;
	}
	if (p->map[i][j] != 1 && j == 0)
		this_is_error(9);
}

void	check_up(t_param *p, int i, int j)
{
	while (0 < i)
	{
		if (p->map[i][j] == ' ')
			this_is_error(9);
		if (p->map[i][j] == 1)
			return ;
		i--;
	}
	if (p->map[i][j] != 1 && i == 0)
		this_is_error(9);
}

void	check_down(t_param *p, int i, int j)
{
	while (i < p->map_height)
	{
		if (p->map[i][j] == ' ')
			this_is_error(9);
		if (p->map[i][j] == 1)
			return ;
		i++;
	}
	if (p->map[i][j] != 1 && i == p->map_height)
		this_is_error(9);
}
