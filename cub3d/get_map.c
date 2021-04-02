/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 13:52:10 by jeongwle          #+#    #+#             */
/*   Updated: 2021/04/02 18:38:29 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	map_check(char *line, int i)
{
	while (line[i])
	{
		if (line[i] == '\0' || ft_isdigit(line[i]) || line[i] == 'N'|| is_space(line[i]))
		{

		//	printf("%s\n", line);
			i++;
		}
		else
		{
		//	printf("line =%c\n", line[i]);
		//	printf("i =%d\n", i);
			this_is_error(9);
		}
	}
}

void	map_init(t_param *p)
{
	int i;
	int j;

	i = 0;
	while (p->map[i])
	{
		j = 0;
		while (p->map[i][j])
		{
			p->map[i][j] = 1;
			j++;
		}
		i++;
	}
}

int		get_map_size(t_param *p, char *fname, int i)
{
	int		fd;
	char	*line;

	if ((fd = open(fname, O_RDONLY)) < 0)
		return (-1);
	while (get_next_line(fd, &line) > 0)
	{
		while (is_space(line[i]))
			i++;
		if (ft_isdigit(line[i]))
		{
			map_check(line, i);
			p->map_height++;
		}
		get_mapwidth(p, word_len(line, '\n'));
	}
	p->map = (int **)malloc(sizeof(int *) * p->map_height);
	if (!p->map)
		return (-1);
	i = -1;
	while (++i < p->map_height)
	{
		p->map[i] = (int *)malloc(sizeof(int) * p->map_width);
		if (!p->map[i])
			return (-1);
	}
	return (0);
}

void	get_map(t_param *p, char *line, int i, int fd)
{
	int	j;
	int	k;
	int l;

	if (p->identifier_count != 8)
		this_is_error(10);
	map_check(line, i);
	map_init(p);
	j = 0;
	k = 0;
	l = 0;
	while (l < word_len(line, '\n'))
	{
		if (ft_isdigit(line[l]))
			p->map[j][k] = line[l] - '0';
		else if (line[l] == 'N')
		{
			p->map[j][k] = 0;
			p->posx = j + 0.5;
			p->posy = k + 0.5;
		}
		else if (is_space(line[i]))
			;
		k++;
		l++;
	}
	j++;
	while (get_next_line(fd, &line) > 0)
	{
		k = 0;
		l = 0;
		while (l < word_len(line, '\n'))
		{
			if (ft_isdigit(line[l]))
				p->map[j][k] = line[l] - '0';
			else if (line[l] == 'N')
			{
				p->map[j][k] = 0;
				p->posx = j + 0.5;
				p->posy = k + 0.5;
			}
			else if (is_space(line[i]))
				;
			k++;
			l++;
		}
		j++;
	}
	p->map_flag = 1;
	p->identifier_count++;
	
	j = 0;
	while (j < p->map_height)
	{
		k = 0;
		while (k < p->map_width)
		{
			printf("%d", p->map[j][k]);
			k++;
		}
		printf("\n");
		j++;
	}
}
