/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 16:17:32 by jeongwle          #+#    #+#             */
/*   Updated: 2021/04/03 16:22:01 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		resolution(t_param *p, char *line, int i, int flag)
{
	if (p->r_flag)
		this_is_error(1);
	i++;
	do_check(line, i, flag);
	while (is_space(line[i]))
		i++;
	if (ft_isdigit(line[i]))
	{
		if ((p->width = ft_atoi(&line[i])) > p->max_width)
			p->width = p->max_width;
	}
	while (ft_isdigit(line[i]))
		i++;
	while (is_space(line[i]))
		i++;
	if (ft_isdigit(line[i]))
	{
		if ((p->height = ft_atoi(&line[i]))> p->max_height)
			p->height = p->max_height;
	}
	else
		this_is_error(flag);
	p->identifier_count++;
	p->r_flag = 1;
}

void		parsing(t_param *p, char *line, int i, int fd)
{
	if (line[i] == 'R')
		resolution(p, line, i, 1);
	else if (line[i] == 'S')
	{
		if (line[i + 1] == 'O')
			if_so(p, line, i);
		else if (is_space(line[i + 1]))
			if_s(p, line, i);
	}
	else if (line[i] == 'W')
		if_w(p, line, i);
	else if (line[i] == 'N')
		if_n(p, line, i);
	else if (line[i] == 'E')
		if_e(p, line, i);
	else if (line[i] == 'F')
	{
		rgb_param(p, line, i, 7);
		p->f_color = rgb_calc(p, p->r, p->g, p->b);
	}
	else if (line[i] == 'C')
	{
		rgb_param(p, line, i, 8);
		p->c_color = rgb_calc(p, p->r, p->g, p->b);
	}
	else if (ft_isdigit(line[i]))
		get_map(p, line, i, fd);
}

int			get_info(t_param *p, int i)
{
	char	*fname;
	int		fd;
	int		gnl;
	char	*line;

	fname = "map.cub";
	get_map_size(p, fname, 0);
	if ((fd = open(fname, O_RDONLY)) < 0)
		return (-1);
	while (p->identifier_count != 9 && (gnl = get_next_line(fd, &line)) > 0)
	{
		i = 0;
		while (is_space(line[i]))
			i++;
		if (line[0])
			parsing(p, line, i, fd);
	}
	if (p->identifier_count == 9 && (get_next_line(fd, &line))> 0)
			this_is_error(10);
	if (p->identifier_count != 9)
		this_is_error(10);
	return (0);
}
/*
int	main(void)
{
	t_param p;

	get_info(&p, 0);
	printf("width = %d\n", p.width);
	printf("height = %d\n", p.height);
}*/
