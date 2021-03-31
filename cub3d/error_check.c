/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 14:55:33 by jeongwle          #+#    #+#             */
/*   Updated: 2021/03/31 19:39:06 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	do_check(char *line, int i, int flag)
{
	while (line[i])
	{
		if (error_check(line[i]))
			i++;
		else
			this_is_error(flag);
	}
}

int		error_check(int c)
{
	if (('0' <= c && c <= '9') || (c == ' ' || (9 <= c && c <= 13)))
		return (1);
	return (0);
}

void	this_is_error(int flag)
{
	if (flag == 1)
	{
		write(1, "resolution error", 16);
		exit(0);
	}
}

