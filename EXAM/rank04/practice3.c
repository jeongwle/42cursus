/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <jeongwle@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 21:15:41 by jeongwle          #+#    #+#             */
/*   Updated: 2021/07/02 21:18:14 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

typedef struct		s_cmd
{
	char			**args;
	int				is_pipe;
	int				fd[2];
	struct s_cmd	*next;
	struct s_cmd	*prev;
}					t_cmd;

int	ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr(char *s)
{
	write(2, s, ft_strlen(s));
}

void	exit_fatal(void)
{
	ft_putstr("error fatal\n");
	exit(1);
}

char	*ft_strdup(char *s)
{
	int i = 0;
	char	*res;

	res = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	res[i] = 0;
	return (res);
}
