/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 15:49:39 by jeongwle          #+#    #+#             */
/*   Updated: 2020/11/30 16:28:06 by jeongwle         ###   ########.fr       */
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
	return (NULL);
}

void	younion(char *s1, char *s2)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		if (ft_strchr(s1, s1[i]) == &s1[i])
			write(1, &s1[i], 1);
		i++;
	}
	while (s2[j])
	{
		if (ft_strchr(s2, s2[j]) == &s2[j])
			if (!(ft_strchr(s1, s2[j])))
					write(1, &s2[j], 1);
		j++;
	}

}

int	main(int argc, char **argv)
{
	if (argc == 3)
		younion(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
