/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 01:28:12 by jeongwle          #+#    #+#             */
/*   Updated: 2020/10/24 03:32:33 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static char	*reposit;
	char		*reposit_temp;
	char		buf[BUFFER_SIZE + 1];
	ssize_t		read_val;

	if (!reposit)
		reposit = ft_strdup("");
	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	while ((read_val = read(fd, buf, BUFFER_SIZE)) > 0 && (!(ft_strchr(reposit, '\n'))))
	{
		buf[read_val] = 0;
		reposit_temp = reposit;
		reposit = ft_strjoin(reposit, buf);
		free(reposit_temp);
	}
	reposit_temp = reposit;
	while (*reposit != '\n' && *reposit)
		reposit++;
	if (*reposit == '\n')
	{
		*reposit = 0;
		*line = ft_strdup(reposit_temp);
		reposit = ft_strdup(reposit + 1);
		free(reposit_temp);
		return (1);
	}
	else
	{
		*line = ft_strdup(reposit_temp);
		reposit = ft_strdup(reposit);
		free(reposit_temp);
	}
	return (0);
}
