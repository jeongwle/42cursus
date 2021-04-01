/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:23:52 by jeongwle          #+#    #+#             */
/*   Updated: 2021/04/01 19:16:09 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	rgb_check(t_param *p, char *line, int i, int flag)
{
	while (line[i])
	{
		if (!(ft_isdigit(line[i]) || line[i] == ',' || is_space(line[i])))
			this_is_error(flag);
		i++;
	}
}

void	rgb_check_param(t_param *p, char *line, int i, int flag)
{
	while (line[i])
	{
		if (ft_isdigit(line[i]))
			break;
		i++;
	}
	if (!line[i])
		this_is_error(flag);

}

void	rgb_param_two(t_param *p, char *line, int i, int flag)
{
	if (flag == 7)
		p->f_flag = 1;
	else if (flag == 8)
		p->c_flag = 1;
	if (line[i])
	{
		while (line[i])
		{
			if (is_space(line[i]))
				i++;
			else
				this_is_error(flag);
		}
	}
}

void	rgb_param(t_param *p, char *line, int i, int flag)
{
	i++;
	rgb_check(p, line, i, flag);
	rgb_check_param(p, line, i , flag);
	while (!ft_isdigit(line[i]))
		i++;
	p->r = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	rgb_check_param(p, line, i, flag);
	while (!ft_isdigit(line[i]))
		i++;
	p->g = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	rgb_check_param(p, line, i, flag);
	while (!ft_isdigit(line[i]))
		i++;
	p->b = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	rgb_param_two(p, line, i, flag);
}

int		rgb_calc(t_param *p, int r, int g, int b)
{
	int result;

	printf("%d %d %d \n", r, g, b);
	r = r << 16;
	g = g << 8;
	b = b << 0;
	printf("%d %d %d \n", r, g, b);
	result = (r + g + b);
	printf("%d \n", result);
	p->identifier_count++;
	return (result);
}
