/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 16:17:32 by jeongwle          #+#    #+#             */
/*   Updated: 2021/03/29 20:07:40 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

extern int map[MAPHEIGHT][MAPWIDTH];

int 	ft_spacelen(char *str)
{
	int	count;

	count = 0;
	while (*str != ' ' || (9 <= *str && *str <= 13))
	{
		count++;
		str++;
	}
	return (count);
}

char	is_space(char c)
{
	return (c == ' ' || (9 <= c && c <= 13));
}

void		resolution(t_param *p, char *line, int fd, int i)
{
	if (line[i] == 'R')
	{
		i++;
		while (is_space(line[i]))
			i++;
		if (ft_isdigit(line[i]))
			p->width = ft_atoi(&line[i]);
		i += ft_spacelen(&line[i]);
		while (is_space(line[i]))
			i++;
		if (ft_isdigit(line[i]))
			p->height = ft_atoi(&line[i]);
	}
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
}

int			get_info(t_param *p, int i)
{
	char	*fname;
	int		fd;
	int		gnl;
	char	*line;

	fname = "map.cub";
	if ((fd = open(fname, O_RDONLY)) < 0)
		return (-1);
	while ((gnl = get_next_line(fd, &line)) > 0)
	{
		i = 0;
		while (is_space(line[i]))
			i++;
		resolution(p, line, fd, i);
	}
	return (0);
}
/*
int	main(void)
{
	t_param p;

	get_info(&p);
	printf("width = %d\n", p.width);
	printf("height = %d\n", p.height);
}*/
