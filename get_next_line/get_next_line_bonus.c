/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:40:13 by jeongwle          #+#    #+#             */
/*   Updated: 2020/10/29 16:23:33 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*reposit[OPEN_MAX];
	char		*reposit_temp;
	char		*new_line;
	char		*buf;
	ssize_t		read_val;

	if (fd < 0 || !line || BUFFER_SIZE < 1 || fd > OPEN_MAX)
		return (-1);
	if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	if (!reposit[fd])
		reposit[fd] = ft_strdup("");
	while (!(new_line = ft_strchr(reposit[fd], '\n')) &&
			(read_val = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_val] = 0;
		reposit_temp = reposit[fd];
		reposit[fd] = ft_strjoin(reposit_temp, buf);
		free(reposit_temp);
	}
	if (buf)
		free(buf);
	if (read_val < 0)
		return (-1);
	return (put_line(&reposit[fd], line, new_line));
}
