/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 01:28:12 by jeongwle          #+#    #+#             */
/*   Updated: 2020/10/28 18:04:08 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	put_line(char **reposit, char **line, char *new_line)
{
	char		*temp;

	if (new_line)
	{
		*reposit	
	}
}

int			get_next_line(int fd, char **line)
{
	static char	*reposit;
	char		*reposit_temp;
	char		*new_line;
	char		buf[BUFFER_SIZE + 1];
	ssize_t		read_val;

	if (!reposit)
		reposit = ft_strdup("");
	if (fd < 0 || !line || BUFFER_SIZE < 1 ||
			!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (!(new_line = ft_strchr(reposit, '\n')) && (read_val = read(fd, buf, BUFFER_SIZE)))
	{
		buf[read_val] = 0;
		reposit_temp = reposit;
		reposit = ft_strjoin(reposit, buf);
		free(reposit_temp);
	}
	if (buf)
		free(buf);
	if (read_val < 0)
		return (-1);
	reposit_temp = reposit;
	if ((reposit = ft_strchr(reposit_temp, '\n')))
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
		reposit = ft_strdup("");
		free(reposit_temp);
	}
	return (0);
}
