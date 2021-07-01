/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 03:02:30 by jeongwle          #+#    #+#             */
/*   Updated: 2021/06/30 05:16:39 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_left_fork(t_param *param, int num)
{
	if (!param->death_flag)
	{
		pthread_mutex_lock(&param->philo[num - 1].fork);
		print_status(param, num, "has taken a fork");
	}
}

void	take_right_fork(t_param *param, int num)
{
	if (num == 1)
	{
		if (!param->death_flag)
		{
			pthread_mutex_lock(&param->philo[param->philo_num - 1].fork);
			print_status(param, num, "has taken a fork");
		}
	}
	else
	{
		if (!param->death_flag)
		{
			pthread_mutex_lock(&param->philo[num - 2].fork);
			print_status(param, num, "has taken a fork");
		}
	}
}

void	return_fork(t_param *param, int num)
{
	if (num == 1)
	{
		pthread_mutex_unlock(&param->philo[num - 1].fork);
		pthread_mutex_unlock(&param->philo[param->philo_num - 1].fork);
	}
	else
	{
		pthread_mutex_unlock(&param->philo[num - 1].fork);
		pthread_mutex_unlock(&param->philo[num - 2].fork);
	}
}
