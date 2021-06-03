/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 15:59:17 by jeongwle          #+#    #+#             */
/*   Updated: 2021/06/03 16:45:06 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void	ft_echo_sub(int *i, char **str, int *flag)
{
	int	j;

	while (ft_strncmp("-n", str[*i], 2) == 0)
	{
		j = 2;
		while (str[*i][j])
		{
			if (str[*i][j] == 'n')
				j++;
			else
			{
				if (*i == 1)
				{
					printf("%s\n", str[*i]);
					(*flag)++;
					return ;
				}
				else
					write(1, str[*i], ft_strlen(str[*i]));
			}
		}
		(*i)++;
		if (str[*i] == NULL)
			return ;
	}
}

void	ft_echo_sub_two(int *i, char **str)
{
	while (str[*i])
	{
		write(1, str[*i], ft_strlen(str[*i]));
		if (str[*i + 1])
			write(1, " ", 1);
		(*i)++;
	}
	printf("\n");
}

void	ft_echo(char **str)
{
	int i;
	int	flag;

	flag = 0;
	if (str[1] == NULL)
	{
		printf("\n");
		return ;
	}
	i = 1;
	if (ft_strncmp("-n", str[i], 2) == 0)
	{
		ft_echo_sub(&i, str, &flag);
		if (flag || str[i] == NULL)
			return ;
		while (str[i])
		{
			write(1, str[i], ft_strlen(str[i]));
			if (str[i + 1])
				write(1, " ", 1);
			i++;
		}
	}
	else
		ft_echo_sub_two(&i, str);
}
