/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:23:52 by jeongwle          #+#    #+#             */
/*   Updated: 2021/03/31 14:23:30 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	rgb_param(t_param *p, char *line, int i)
{
	i++;
	while (!ft_isdigit(line[i]))
		i++;
	p->r = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	while (!ft_isdigit(line[i]))
		i++;
	p->g = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	while (!ft_isdigit(line[i]))
		i++;
	p->b = ft_atoi(&line[i]);
}

int		rgb_calc(int r, int g, int b)
{
	int result;

	printf("%d %d %d \n", r, g, b);
	r = r << 16;
	g = g << 8;
	b = b << 0;
	printf("%d %d %d \n", r, g, b);
	result = (r + g + b);
	printf("%d \n", result);
	return (result);
}
