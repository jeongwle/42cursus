/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 20:07:53 by jeongwle          #+#    #+#             */
/*   Updated: 2020/10/24 02:33:02 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	if_meet_line(char **reposit, char **line, char *reposit_temp)
{
	**reposit = '\0';
	*line = ft_strdup(reposit_temp);
	*reposit = ft_strdup(*reposit + 1);
	free(reposit_temp);
}

static void	if_meet_null(char **reposit, char **line, char *reposit_temp)
{
	*line = ft_strdup(reposit_temp);
	*reposit = ft_strdup(*reposit);
	free(reposit_temp);
}

static void	join(ssize_t read_val, char **reposit, char *buf)
{
	char	*temp;

	buf[read_val] = 0;
	temp = *reposit;
	*reposit = ft_strjoin(*reposit, buf);
	free(temp);
}

int			get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	char		*reposit_temp;
	static char	*reposit;
	ssize_t		read_val;

	reposit = reposit != NULL ? reposit : ft_strdup("");
	if (fd < 0 || !line || BUFFER_SIZE < 1 || fd > OPEN_MAX)
		return (-1);
	while ((read_val = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		join(read_val, &reposit, buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	reposit_temp = reposit;
	while (*reposit != '\n' && *reposit)
		reposit++;
	if (*reposit == '\n')
	{
		if_meet_line(&reposit, line, reposit_temp);
		return (1);
	}
	else
		if_meet_null(&reposit, line, reposit_temp);
	return (read_val < 0 ? -1 : 0);
}
