/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 14:35:04 by jeongwle          #+#    #+#             */
/*   Updated: 2021/03/27 16:10:52 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char 	*line;
	char 	*fname;
	int		fd;
	int		res;
	int		i;

	i = 0;
	fname = "map.cub";
	fd = open(fname, O_RDONLY);
	res = get_next_line(fd, &line);
	printf("%s\n", line);
	return (0);
}
