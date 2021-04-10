/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 16:17:32 by jeongwle          #+#    #+#             */
/*   Updated: 2021/04/09 14:46:36 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		resolution_two(t_param *p, char *line, int i, int flag)
{
	if (ft_isdigit(line[i]))
	{
		if (ft_atoi(&line[i]) == 0)
			this_is_error(flag);
		if ((p->height = ft_atoi(&line[i])) > p->max_height ||
		ft_atoi(&line[i]) == -1)
			p->height = p->max_height;
	}
	else
		this_is_error(flag);
	while (ft_isdigit(line[i]))
		i++;
	while (line[i])
	{
		if (ft_isdigit(line[i]))
			this_is_error(flag);
		i++;
	}
	free(line);
	p->identifier_count++;
	p->r_flag = 1;
}

void		resolution(t_param *p, char *line, int i, int flag)
{
	if (p->r_flag)
		this_is_error(1);
	if (!is_space(line[i + 1]))
		this_is_error(10);
	i++;
	do_check(line, i, flag);
	while (is_space(line[i]))
		i++;
	if (ft_isdigit(line[i]))
	{
		if (ft_atoi(&line[i]) == 0)
			this_is_error(flag);
		if ((p->width = ft_atoi(&line[i])) > p->max_width ||
		ft_atoi(&line[i]) == -1)
			p->width = p->max_width;
	}
	while (ft_isdigit(line[i]))
		i++;
	while (is_space(line[i]))
		i++;
	resolution_two(p, line, i, flag);
}

void		parsing_two(t_param *p, char *line, int i, int flag)
{
	rgb_param(p, line, i, flag);
	if (flag == 7)
		p->f_color = rgb_calc(p, p->r, p->g, p->b);
	if (flag == 8)
		p->c_color = rgb_calc(p, p->r, p->g, p->b);
}

void		parsing(t_param *p, char *line, int i, int fd)
{
	if (line[i] == 'R')
		resolution(p, line, i, 1);
	else if (line[i] == 'S')
	{
		if (line[i + 1] == 'O')
			if_so(p, line, i);
		else if (is_space(line[i + 1]) || !line[i + 1])
			if_s(p, line, i);
		else
			this_is_error(10);
	}
	else if (line[i] == 'W')
		if_w(p, line, i);
	else if (line[i] == 'N')
		if_n(p, line, i);
	else if (line[i] == 'E')
		if_e(p, line, i);
	else if (line[i] == 'F' && is_space(line[i + 1]))
		parsing_two(p, line, i, 7);
	else if (line[i] == 'C' && is_space(line[i + 1]))
		parsing_two(p, line, i, 8);
	else if (ft_isdigit(line[i]))
		get_map(p, line, i, fd);
	else
		this_is_error(10);
}

void		get_info(t_param *p, int i, char *fname)
{
	int		fd;
	char	*line;

	get_map_size(p, fname, 0, 0);
	if ((fd = open(fname, O_RDONLY)) < 0)
		this_is_error(11);
	while (get_next_line(fd, &line) > 0)
	{
		i = 0;
		while (is_space(line[i]))
			i++;
		if (line[0])
			parsing(p, line, i, fd);
		else
			free(line);
	}
	if (line)
		free(line);
	if (!p->player_flag)
		this_is_error(9);
	if (p->identifier_count != 9)
		this_is_error(10);
}
