/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 14:55:33 by jeongwle          #+#    #+#             */
/*   Updated: 2021/04/01 17:02:13 by jeongwle         ###   ########.fr       */
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


void	do_check_texture(char *line, int i, int flag)
{
	while (line[i])
	{
		if (error_check_texture(line[i]))
			i++;
		else
			this_is_error(flag);
	}

}

int		error_check(int c)
{
	if (('0' <= c && c <= '9') || is_space(c))
		return (1);
	return (0);
}

int		error_check_texture(int c)
{
	if (ft_isalpha(c) || c == '.' || c == '/' || is_space(c))
		return (1);
	return (0);
}

void	this_is_error(int flag)
{
	if (flag == 1)
		write(1, "resolution error", 16);
	else if (flag == 2)
		write(1, "SO error", 8);
	else if (flag == 3)
		write(1, "S error", 7);
	else if (flag == 4)
		write(1, "WE error", 8);
	else if (flag == 5)
		write(1, "NO error", 8);
	else if (flag == 6)
		write(1, "EA error", 8);
	else if (flag == 7)
		write(1, "F error", 8);
	else if (flag == 8)
		write(1, "C error", 8);
	else if (flag == 9)
		write(1, "argu error", 10);
	exit(0);
}

