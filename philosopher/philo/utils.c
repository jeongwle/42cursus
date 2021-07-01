/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 15:09:25 by jeongwle          #+#    #+#             */
/*   Updated: 2021/06/30 05:31:31 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_space(char c)
{
	return (c == ' ' || (9 <= c && c <= 13));
}

int			ft_atoi(const char *str)
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
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		if (sign == 1 && res > 2147483647)
			return (-1);
		if (sign == -1 && res > 2147483648)
			return (0);
		i++;
	}
	return (sign * res);
}

void		print_status(t_param *param, int param_num, char *str)
{
	struct timeval	new_time;

	if (!param->death_flag)
	{
		pthread_mutex_lock(&param->print);
		gettimeofday(&new_time, NULL);
		param->time_stamp = (new_time.tv_sec - param->old_time.tv_sec) * 1000 +
			(new_time.tv_usec / 1000 - param->old_time.tv_usec / 1000);
		if (!param->death_flag)
			printf("%dms %d %s\n", param->time_stamp, param_num, str);
		pthread_mutex_unlock(&param->print);
	}
	else if (!ft_strcmp(str, "is died"))
	{
		pthread_mutex_lock(&param->print);
		gettimeofday(&new_time, NULL);
		param->time_stamp = (new_time.tv_sec - param->old_time.tv_sec) * 1000 +
			(new_time.tv_usec / 1000 - param->old_time.tv_usec / 1000);
		printf("%dms %d %s\n", param->time_stamp, param_num, str);
		pthread_mutex_unlock(&param->print);
	}
}

void		ft_usleep(t_param *param, int num)
{
	struct timeval	old_time;
	struct timeval	new_time;
	int				temp;
	int				diff;

	if (!param->death_flag)
	{
		gettimeofday(&old_time, NULL);
		gettimeofday(&new_time, NULL);
		temp = num * 1000;
		diff = 0;
		while (diff < num)
		{
			temp /= 4;
			usleep(temp);
			gettimeofday(&new_time, NULL);
			diff = (new_time.tv_sec - old_time.tv_sec) * 1000 +
				(new_time.tv_usec / 1000 - old_time.tv_usec / 1000);
		}
	}
}

int			ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
