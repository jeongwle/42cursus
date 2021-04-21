/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 17:15:45 by jeongwle          #+#    #+#             */
/*   Updated: 2020/11/30 19:37:42 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char		*ft_strdup(char *str)
{
	size_t	len;
	char	*res;
	int		i;

	i = 0;
	len = ft_strlen(str);
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = 0;
	return (res);
}

static char		*ft_strjoin(char *s1, char *s2)
{
	size_t	len;
	char	*res;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!s1 && s2)
		return (ft_strdup(s2));
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && !s2)
		return (NULL);
	if ((len = ft_strlen(s1) + ft_strlen(s2)) == 0)
		return (ft_strdup(""));
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s1[++i])
		res[i] = s1[i];
	while (s2[++j])
		res[i++] = s2[j];
	res[i] = 0;
	return (res);
}

int	get_next_line(char **line)
{
	static char	*reposit;
	char		*buf;
	int			read_val;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE < 1 || !line)
		return (-1);
	if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	if (!reposit)
		reposit = ft_strdup("");
	while ((read_val = read(0, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_val] = 0;
		if (buf[0] == '\n')
		{
			*line = reposit;
			free(reposit);
			free(buf);
			reposit = NULL;
			return (1);
		}
		else if (buf[0] == '\0')
		{
			*line = reposit;
			free(reposit);
			free(buf);
			reposit = NULL;
		}
		else
		{
			temp = reposit;
			reposit = ft_strjoin(temp, buf);
			free(temp);
			free(buf);
		}
	}
	if (read_val < 0)
		return (-1);
	return (0);
}
/*
int	main(void)
{
	int		r;
	char	*line;

	line = NULL;
	while ((r = get_next_line(&line)) > 0)
	{
		printf("%s\n", line);
		free(line);
		line = NULL;
	}
	printf("%s", line);
	free(line);
	line = NULL;
}
*/
