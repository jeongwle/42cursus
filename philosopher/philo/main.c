/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 14:09:54 by jeongwle          #+#    #+#             */
/*   Updated: 2021/06/30 06:21:37 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*start_routine(void *arg)
{
	t_param	*param;
	int		num;

	param = (t_param *)((t_philo *)arg)->data;
	num = (int)((t_philo *)arg)->identifier;
	if (num % 2 == 0)
		usleep(100);
	while (!param->death_flag)
	{
		take_left_fork(param, num);
		take_right_fork(param, num);
		param->philo[num - 1].time_stamp = param->time_stamp;
		print_status(param, num, "is eating");
		param->philo[num - 1].eating_num += 1;
		ft_usleep(param, param->time_to_eat);
		return_fork(param, num);
		if (param->philo[num - 1].eating_num == param->must_eat)
			break ;
		print_status(param, num, "is sleeping");
		ft_usleep(param, param->time_to_sleep);
		print_status(param, num, "is thinking");
	}
	return (NULL);
}

int		philo_eat_enough(t_param *param)
{
	int	i;

	i = 0;
	while (param->philo[i].eating_num >= param->must_eat)
		i++;
	if (i == param->philo_num)
		return (1);
	return (0);
}

void	philo_died(t_param *param)
{
	struct timeval	new;
	int				i;
	int				time_stamp;

	while (!param->death_flag)
	{
		i = 0;
		gettimeofday(&new, NULL);
		time_stamp = (new.tv_sec - param->old_time.tv_sec) * 1000 +
			(new.tv_usec / 1000 - param->old_time.tv_usec / 1000);
		while (i < param->philo_num)
		{
			if (param->argc == 6 && philo_eat_enough(param) == 1)
				return ;
			if (time_stamp - param->philo[i].time_stamp > param->time_to_live)
			{
				param->death_flag = 1;
				print_status(param, i + 1, "is died");
				pthread_mutex_unlock(&param->die);
				break ;
			}
			i++;
		}
	}
}

void	create_thread(t_param *param)
{
	int	i;

	i = 0;
	gettimeofday(&param->old_time, NULL);
	while (i < param->philo_num)
	{
		pthread_create(&param->philo[i].ph, NULL, start_routine,
				(void *)&param->philo[i]);
		if (param->philo_num == 1)
			pthread_detach(param->philo[i].ph);
		i++;
	}
	philo_died(param);
	i = 0;
	while (param->philo_num != 1 && i < param->philo_num)
		pthread_join(param->philo[i++].ph, NULL);
}

int		main(int argc, char *argv[])
{
	int		init_res;
	t_param	param;

	if (!(argc == 5 || argc == 6))
	{
		printf("error\n");
		return (-1);
	}
	init_res = init_param(&param, argc, argv);
	if (init_res == -1)
	{
		printf("error\n");
		return (-1);
	}
	make_philo(&param);
	mutex_init(&param);
	create_thread(&param);
	return (0);
}
