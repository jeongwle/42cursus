/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 10:31:01 by jeongwle          #+#    #+#             */
/*   Updated: 2021/06/04 11:42:51 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	is_not_n_option(int *i, char **str)
{
	while (str[*i])
	{
		printf("%s", str[*i]);
		if (str[*i + 1])
			printf(" ");
		(*i)++;
	}
	printf("\n");
}

void	is_n_option(int *i, char **str)
{
	int j;

	if (!str[*i + 1])
		return ;
	(*i)++;
	while (str[*i] && !ft_strncmp("-n", str[*i], 2))
	{
		j = 2;
		while (str[*i][j] == 'n')
			j++;
		if (str[*i][j])
			break ;
		(*i)++;
	}
	while (str[*i])
	{
		write(1, str[*i], ft_strlen(str[*i]));
		if (str[*i + 1])
			write(1, " ", 1);
		(*i)++;
	}
}

void	whether_n_option(int *i, char **str)
{
	int	j;

	j = 2;
	while (str[*i][j])
	{
		if (str[*i][j] == 'n')
			j++;
		else
		{
			is_not_n_option(i, str);
			return ;
		}
	}
	is_n_option(i, str);
}

void	ft_echo(char **str)
{
	int	i;

	if (str[1] == NULL)
	{
		printf("\n");
		return ;
	}
	i = 1;
	if (!ft_strncmp("-n", str[i], 2))
		whether_n_option(&i, str);
	else
	{
		while (str[i])
		{
			printf("%s", str[i]);
			if (str[i + 1])
				printf(" ");
			i++;
		}
		printf("\n");
	}
}
