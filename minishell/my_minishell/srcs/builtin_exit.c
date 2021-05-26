/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 10:03:50 by jeongwle          #+#    #+#             */
/*   Updated: 2021/05/20 14:32:51 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		is_space(char c)
{
	return (c == ' ' || (9 <= c && c <= 13));
}

static int		atoi_check(const char *str, int i, int sign, long long int res)
{
	int	j;

	j = i + 1;
	if (sign == 1 && str[j] &&
		(res > 922337203685477580 ||
		(res == 922337203685477580 && (str[j] == '8' || str[j] == '9'))))
		return (-1);
	if (sign == -1 && str[j] &&
		(res > 922337203685477580 ||
		(res == 922337203685477580 && str[j] == '9')))
		return (-1);
	return (0);
}

long long int	mini_atoi(const char *str, t_mini *mini)
{
	int				i;
	int				sign;
	long long int	res;

	i = 0;
	res = 0;
	sign = 1;
	while (is_space(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign *= -1;
	}
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + str[i] - '0';
		if (atoi_check(str, i, sign, res) == -1)
		{
			mini->atoi_flag = 1;
			return (-1);
		}
		i++;
	}
	return (sign * res);
}

static int		sentence(char *str)
{
	int i;

	i = 0;
	while (ft_isdigit(str[i]))
		i++;
	if (i == ft_strlen(str))
		return (0);
	return (1);
}

void			mini_exit(t_mini *mini, char *s1, char *s2)
{
	long long int res;

	res = 0;
	write(1, "exit\n", 5);
	res = mini_atoi(s1, mini);
	if ((mini->atoi_flag && res == -1) || sentence(s1))
	{
		write(1, "bash: exit: ", 12);
		write(1, s1, ft_strlen(s1));
		write(1, ": numeric argument required\n", 29);
	}
	else
		write(1, "bash: exit: too many arguments\n", 31);
	mini->atoi_flag = 0;
}
