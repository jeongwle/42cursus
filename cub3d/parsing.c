/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 16:17:32 by jeongwle          #+#    #+#             */
/*   Updated: 2021/03/27 16:24:59 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

extern int map[MAPHEIGHT][MAPWIDTH];

int		get_info()
{
	char	*fname;
	int		fd;
	int		gnl;

	fname = "map.cub";
	if (fd = open(fname, O_RDONLY) < 0)
		return (-1);
	while (gnl = get_next_line(fd, &line) > 0)
	{

	}
}
