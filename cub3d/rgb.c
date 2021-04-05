/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:23:52 by jeongwle          #+#    #+#             */
/*   Updated: 2021/04/05 21:26:08 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	rgb_check(t_param *p, char *line, int i, int flag)
{
	int	comma_count;

	comma_count = 0;
	while (line[i])
	{
		if (!(ft_isdigit(line[i]) || line[i] == ','))
			this_is_error(flag);
		if (line[i] == ',')
			comma_count++;
		i++;
	}
	if (comma_count != 2)
		this_is_error(flag);
}

void	rgb_check_param(t_param *p, char *line, int i, int flag)
{
	while (line[i])
	{
		if (ft_isdigit(line[i]))
			break ;
		i++;
	}
	if (!line[i])
		this_is_error(flag);
}

void	rgb_param_two(t_param *p, char *line, int i, int flag)
{
	if (flag == 7)
	{
		if (p->f_flag)
			this_is_error(10);
		p->f_flag = 1;
	}
	else if (flag == 8)
	{
		if (p->c_flag)
			this_is_error(10);
		p->c_flag = 1;
	}
	if (!(0 <= p->b && p->b <= 255))
		this_is_error(flag);
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
	free(line);
}

void	rgb_param(t_param *p, char *line, int i, int flag)
{
	i += 2;
	rgb_check(p, line, i, flag);
	rgb_check_param(p, line, i, flag);
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
	if (!(0 <= p->r && p->r <= 255))
		this_is_error(flag);
	if (!(0 <= p->g && p->g <= 255))
		this_is_error(flag);
	rgb_param_two(p, line, i, flag);
}

int		rgb_calc(t_param *p, int r, int g, int b)
{
	int result;

	r = r << 16;
	g = g << 8;
	b = b << 0;
	result = (r + g + b);
	p->identifier_count++;
	return (result);
}
