/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 03:25:58 by jeongwle          #+#    #+#             */
/*   Updated: 2021/06/30 04:47:53 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mutex_init(t_param *param)
{
	int	i;

	i = 0;
	while (i < param->philo_num)
	{
		pthread_mutex_init(&param->philo[i].fork, NULL);
		i++;
	}
	pthread_mutex_init(&param->print, NULL);
	pthread_mutex_init(&param->die, NULL);
	pthread_mutex_lock(&param->die);
}

void	make_philo(t_param *param)
{
	int	i;

	param->philo = (t_philo *)malloc(sizeof(t_philo) * param->philo_num);
	i = 0;
	while (i < param->philo_num)
	{
		param->philo[i].identifier = i + 1;
		param->philo[i].time_stamp = 0;
		param->philo[i].eating_num = 0;
		param->philo[i].data = param;
		i++;
	}
}

int		init_param(t_param *param, int argc, char **argv)
{
	param->argc = argc;
	param->philo_num = ft_atoi(argv[1]);
	param->time_to_live = ft_atoi(argv[2]);
	param->time_to_eat = ft_atoi(argv[3]);
	param->time_to_sleep = ft_atoi(argv[4]);
	param->must_eat = 0;
	if (argc == 6)
	{
		param->must_eat = ft_atoi(argv[5]);
		if (param->must_eat <= 0)
			return (-1);
	}
	if (param->philo_num <= 0)
		return (-1);
	param->death_flag = 0;
	return (0);
}
