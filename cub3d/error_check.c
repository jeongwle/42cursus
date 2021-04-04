/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 14:55:33 by jeongwle          #+#    #+#             */
/*   Updated: 2021/04/04 16:53:05 by jeongwle         ###   ########.fr       */
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
		write(1, "error\nresolution", 16);
	else if (flag == 2)
		write(1, "error\nSO", 8);
	else if (flag == 3)
		write(1, "error\nS", 7);
	else if (flag == 4)
		write(1, "error\nWE", 8);
	else if (flag == 5)
		write(1, "error\nNO", 8);
	else if (flag == 6)
		write(1, "error\nEA", 8);
	else if (flag == 7)
		write(1, "error\nF", 8);
	else if (flag == 8)
		write(1, "error\nC", 8);
	else if (flag == 9)
		write(1, "error\nmap", 9);
	else if (flag == 10)
		write(1, "error\nargu", 10);
	else if (flag == 11)
		write(1, "error\nopen", 10);
	exit(0);
}

