/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 05:15:04 by jeongwle          #+#    #+#             */
/*   Updated: 2020/10/06 05:42:23 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*s_temp;
	int				i;

	s_temp = (unsigned char *)s;
	i = 0;
	while (s_temp[i])
		i++;
	if (s_temp[i] == (unsigned char)c)
		return ((char *)&s_temp[i]);
	while (i >= 0)
	{
		if (s_temp[i] == (unsigned char)c)
			return ((char *)&s_temp[i]);
		i--;
	}
	return (NULL);
}
