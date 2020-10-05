/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <jeongwle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 21:09:44 by jeongwle          #+#    #+#             */
/*   Updated: 2020/09/30 00:40:00 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int i;

	i = 0;
	while (i < n && s1[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (i == n)
		i -= 1;
	return (s1[i] - s2[i]);
}

int	main(void)
{
	char arr1[] = "Happy";
	char arr2[] = "HappyC";

	printf("%d \n", ft_strncmp(arr1, arr2, 7));
	return (0);
}
