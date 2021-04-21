/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 17:00:08 by jeongwle          #+#    #+#             */
/*   Updated: 2020/11/30 19:34:27 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LIN_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SZIE 1
# endif

#include <stdlib.h>
#include <unistd.h>

static size_t	ft_strlen(char *str);
static char		*ft_strdup(char *str);
static char		*ft_strjoin(char *s1, char *s2);
int				get_next_line(char **line);

#endif
