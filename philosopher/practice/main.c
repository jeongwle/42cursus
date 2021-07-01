/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 14:09:54 by jeongwle          #+#    #+#             */
/*   Updated: 2021/06/29 20:11:17 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void	take_left_fork(t_param *param, int num)
{	
	pthread_mutex_lock(&param->philo[num - 1].fork);
	print_status(param, num, "has taken left fork");
}

void	take_right_fork(t_param *param, int num)
{
	if (num == 1)
	{
		pthread_mutex_lock(&param->philo[param->philo_num - 1].fork);
		print_status(param, num, "has taken right fork");
	}
	else
	{
		pthread_mutex_lock(&param->philo[num - 2].fork);
		print_status(param, num, "has taken right fork");
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

void	*start_routine(void *arg)
{
	t_param	*param;
	int		num;

	param = (t_param *)((t_philo *)arg)->data;
	num = (int)((t_philo *)arg)->identifier;
	if (num % 2 == 0)
		ft_usleep(1);
	while (1)
	{
		take_left_fork(param, num);
		take_right_fork(param, num);
		print_status(param, num, "is eating");
		ft_usleep(400);
		return_fork(param, num);
		print_status(param, num, "is sleeping");
		ft_usleep(200);
		print_status(param, num, "is thinking");
	}
	/*
	if (num == 1)
	{
		if (param->philo[param->philo_num - 1].left == 0)
		{
			param->philo[num - 1].right = 1;
			pthread_mutex_lock(&param->philo[param->philo_num - 1].fork);
			print_status(param, num, "has taken fork");
			if (param->philo[num - 1].left == 1)
			{
				print_status(param, num, "is eating");
				ft_usleep(400);
				param->philo[num - 1].right = 0;
				param->philo[num - 1].left = 0;
				pthread_mutex_unlock(&param->philo[param->philo_num - 1].fork);
				pthread_mutex_unlock(&param->philo[num - 1].fork);
			}
		}
		if (param->philo[num].right == 0)
		{
			param->philo[num - 1].left = 1;
			pthread_mutex_lock(&param->philo[num - 1].fork);
			print_status(param, num, "has taken fork");
			if (param->philo[num - 1].right == 1)
			{
				print_status(param, num, "is eating");
				ft_usleep(400);
				param->philo[num - 1].right = 0;
				param->philo[num - 1].left = 0;
				pthread_mutex_unlock(&param->philo[param->philo_num - 1].fork);
				pthread_mutex_unlock(&param->philo[num - 1].fork);
			}
		}
	}
	else if (num == param->philo_num)
	{
		if (param->philo[num - 2].left == 0)
		{
			param->philo[num - 1].right = 1;
			pthread_mutex_lock(&param->philo[num - 2].fork);
			print_status(param, num, "has taken fork");
			if (param->philo[num - 1].left == 1)
			{
				print_status(param, num, "is eating");
				ft_usleep(400);
				param->philo[num - 1].right = 0;
				param->philo[num - 1].left = 0;
				pthread_mutex_unlock(&param->philo[num - 2].fork);
				pthread_mutex_unlock(&param->philo[num - 1].fork);
			}
		}
		if (param->philo[0].right == 0)
		{
			param->philo[num - 1].left = 1;
			pthread_mutex_lock(&param->philo[0].fork);
			print_status(param, num, "has taken fork");
			if (param->philo[num - 1].right == 1)
			{
				print_status(param, num, "is eating");
				ft_usleep(400);
				param->philo[num - 1].right = 0;
				param->philo[num - 1].left = 0;
				pthread_mutex_unlock(&param->philo[num - 2].fork);
				pthread_mutex_unlock(&param->philo[num - 1].fork);
			}
		}
	}
	else
	{
		if (param->philo[num - 2].left == 0)
		{
			param->philo[num - 1].right = 1;
			pthread_mutex_lock(&param->philo[num - 2].fork);
			print_status(param, num, "has taken fork");
			if (param->philo[num - 1].left == 1)
			{
				print_status(param, num, "is eating");
				ft_usleep(400);
				param->philo[num - 1].right = 0;
				param->philo[num - 1].left = 0;
				pthread_mutex_unlock(&param->philo[num - 2].fork);
				pthread_mutex_unlock(&param->philo[num - 1].fork);
			}
		}
		if (param->philo[num].right == 0)
		{
			param->philo[num - 1].left = 1;
			pthread_mutex_lock(&param->philo[num - 1].fork);
			print_status(param, num, "has taken fork");
			if (param->philo[num - 1].right == 1)
			{
				print_status(param, num, "is eating");
				ft_usleep(400);
				param->philo[num - 1].right = 0;
				param->philo[num - 1].left = 0;
				pthread_mutex_unlock(&param->philo[num - 2].fork);
				pthread_mutex_unlock(&param->philo[num - 1].fork);
			}
		}
	}*/
	return (NULL);
}

void	create_thread(t_param *param)
{
	int	i;

	i = 0;
	gettimeofday(&param->old_time, NULL);
	while (i < param->philo_num)
	{
		pthread_create(&param->philo[i].ph, NULL, start_routine, (void *)&param->philo[i]);
//		pthread_join(param->philo[i].ph, NULL);
		pthread_detach(param->philo[i].ph);
		i++;
	}
//	i = 0;
	while(1)
		;
	//while (i < param->philo_num)
	//{
	//	pthread_detach(param->philo[i].ph);
	//	i++;
	//}
}

void	mutex_init(t_param *param)
{
	int	i;

	i = 0;
	while (i < param->philo_num)
	{
		pthread_mutex_init(&param->philo[i].fork, NULL);
		i++;
	}
}

void	make_philo(t_param *param)
{
	int	i;
	t_param	*temp;

	param->philo = (t_philo *)malloc(sizeof(t_philo) * param->philo_num);
	i = 0;
	while (i < param->philo_num)
	{
		param->philo[i].identifier = i + 1;
		param->philo[i].data = param;
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_param	param;

	param.time_stamp = 0;
	param.philo_num = ft_atoi(argv[1]);
	make_philo(&param);
	mutex_init(&param);
	create_thread(&param);
}
