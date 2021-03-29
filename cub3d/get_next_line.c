/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 01:28:12 by jeongwle          #+#    #+#             */
/*   Updated: 2021/03/29 16:54:53 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	put_line(char **reposit, char **line, char *new_line)
{
	char		*temp;

	if (new_line)
	{
		*new_line = '\0';
		*line = ft_strdup(*reposit);
		temp = *reposit;
		*reposit = ft_strdup(new_line + 1);
		if (temp)
			free(temp);
		return (1);
	}
	else
	{
		*line = ft_strdup(*reposit);
		if (*reposit)
			free(*reposit);
		*reposit = NULL;
	}
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static char	*reposit;
	char		*reposit_temp;
	char		*new_line;
	char		*buf;
	ssize_t		read_val;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	if (!reposit)
		reposit = ft_strdup("");
	while (!(new_line = ft_strchr(reposit, '\n')) &&
			(read_val = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_val] = 0;
		reposit_temp = reposit;
		reposit = ft_strjoin(reposit_temp, buf);
		free(reposit_temp);
	}
	if (buf)
		free(buf);
	if (read_val < 0)
		return (-1);
	return (put_line(&reposit, line, new_line));
}
