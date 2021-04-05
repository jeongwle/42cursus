/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 18:16:32 by jeongwle          #+#    #+#             */
/*   Updated: 2021/04/05 18:52:03 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	check_argv_one(char *str)
{
	size_t	i;
	char	*temp;

	if (!str)
		this_is_error(10);
	i = ft_strlen(str);
	if (i < 4)
		this_is_error(10);
	temp = ".cub";
	if (ft_strncmp(&str[i - 4], temp, 4))
		this_is_error(10);
}

void	check_argv_two(t_param *p, char *str)
{
	size_t	i;
	char	*temp;

	if (!str)
		this_is_error(10);
	i = ft_strlen(str);
	if (i != 6)
		this_is_error(10);
	temp = "--save";
	if (ft_strncmp(str, temp, 6))
		this_is_error(10);
	main_loop(p);
	bitmap(p);
}
