/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 15:09:42 by jeongwle          #+#    #+#             */
/*   Updated: 2020/11/30 15:47:43 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strchr(char *str, int c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
			return (&str[i]);
		i++;
	}
	if (str[i] == (unsigned char)c)
		return (&str[i]);
	return (0);
}

void	inter(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i])
	{
		if (ft_strchr(s1, s1[i]) && ft_strchr(s2, s1[i]))
		{
			if (ft_strchr(s1, s1[i]) == &s1[i])
				write(1, &s1[i], 1);
			i++;
		}
		else
			i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		inter(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
