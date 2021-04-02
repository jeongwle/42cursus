/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 16:17:32 by jeongwle          #+#    #+#             */
/*   Updated: 2021/04/02 17:57:56 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	is_space(char c)
{
	return (c == ' ' || (9 <= c && c <= 13));
}
void		resolution(t_param *p, char *line, int i, int flag)
{
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
	if (line[i] == 'R' && !p->r_flag)
		resolution(p, line, i, 1);
	else if (line[i] == 'S')
	{
		if (line[i + 1] == 'O' && !p->so_flag)
			if_so(p, line, i);
		else if (is_space(line[i + 1]) && !p->s_flag)
			if_s(p, line, i);
	}
	else if (line[i] == 'W' && !p->w_flag)
		if_w(p, line, i);
	else if (line[i] == 'N' && !p->n_flag)
		if_n(p, line, i);
	else if (line[i] == 'E' && !p->e_flag)
		if_e(p, line, i);
	else if (line[i] == 'F' && !p->f_flag)
	{
		rgb_param(p, line, i, 7);
		p->f_color = rgb_calc(p, p->r, p->g, p->b);
	}
	else if (line[i] == 'C' && !p->c_flag)
	{
		rgb_param(p, line, i, 8);
		p->c_color = rgb_calc(p, p->r, p->g, p->b);
	}
	else if (ft_isdigit(line[i]) && !p->map_flag)
		get_map(p, line, i, fd);
}

int			get_info(t_param *p, int i)
{
	char	*fname;
	int		fd;
	int		gnl;
	char	*line;
	char	**a;
	int j = 0;

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
/*	while (get_next_line(fd, &line) > 0)
	{
		if (word_count(line, '\n'))
		{
			get_mapwidth(p, word_len(line, '\n'));
			p->map_height++;
		}
	}*/
	/*
	if ((fdd = open(fname, O_RDONLY)) < 0)
		return (-1);
	while (get_next_line(fdd, &line) > 0)
	{
	}*/
//	printf("%d\n %d\n", p->map_width, p->map_height);
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
