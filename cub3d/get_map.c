/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 13:52:10 by jeongwle          #+#    #+#             */
/*   Updated: 2021/04/05 20:51:41 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	map_check(char *line, int i)
{
	while (line[i])
	{
		if (line[i] == '\0' || ft_isdigit(line[i]) || is_space(line[i]))
			i++;
		else if (is_news(line[i]))
			i++;
		else
			this_is_error(9);
	}
}

int		map_init(t_param *p, int i, int j)
{
	p->map = (int **)malloc(sizeof(int *) * p->map_height);
	if (!p->map)
		return (-1);
	while (++i < p->map_height)
	{
		p->map[i] = (int *)malloc(sizeof(int) * p->map_width);
		if (!p->map[i])
		{
			while (++j < i)
				free(p->map[j]);
			free(p->map);
			return (-1);
		}
	}
	i = -1;
	while (++i < p->map_height)
	{
		j = -1;
		while (++j < p->map_width)
			p->map[i][j] = ' ';
	}
	return (0);
}

void	get_map_size(t_param *p, char *fname, int i, int flag)
{
	int		fd;
	char	*line;

	if ((fd = open(fname, O_RDONLY)) < 0)
		this_is_error(11);
	while (get_next_line(fd, &line) > 0)
	{
		i = 0;
		while (is_space(line[i]))
			i++;
		if (ft_isdigit(line[i]))
			flag = 1;
		if (flag && !ft_isdigit(line[i]))
			break ;
		if (ft_isdigit(line[i]))
		{
			map_check(line, i);
			p->map_height++;
			if (p->map_width < word_len(line, '\n'))
				p->map_width = word_len(line, '\n');
		}
		free(line);
	}
	if (line)
		free(line);
}

void	get_map(t_param *p, char *line, int i, int fd)
{
	int	j;
	int	k;
	int	l;

	if (p->identifier_count != 8)
		this_is_error(10);
	map_check(line, i);
	map_init(p, -1, -1);
	j = 0;
	k = 0;
	l = 0;
	while (l < word_len(line, '\n'))
	{
		if (ft_isdigit(line[l]))
			p->map[j][k] = line[l] - '0';
		else if (is_news(line[l]))
			player_dir(p, line[l], j, k);
		k++;
		l++;
	}
	j++;
	free(line);
	get_map_two(p, line, fd, j);
}

void	get_map_two(t_param *p, char *line, int fd, int j)
{
	int k;
	int l;

	while (get_next_line(fd, &line) > 0 && *line)
	{
		k = 0;
		l = -1;
		while (++l < word_len(line, '\n'))
		{
			if (ft_isdigit(line[l]))
				p->map[j][k] = line[l] - '0';
			else if (is_news(line[l]))
				player_dir(p, line[l], j, k);
			else if (!is_space(line[l]))
				this_is_error(10);
			k++;
		}
		j++;
		free(line);
	}
	free(line);
	p->map_flag = 1;
	p->identifier_count++;
	check_map(p);
}
