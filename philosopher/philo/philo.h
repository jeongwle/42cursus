/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 18:40:12 by jeongwle          #+#    #+#             */
/*   Updated: 2021/06/30 04:55:44 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct	s_philo
{
	pthread_t		ph;
	int				time_stamp;
	int				eating_num;
	int				identifier;
	void			*data;
	pthread_mutex_t fork;
}				t_philo;

typedef struct	s_param
{
	t_philo			*philo;
	int				philo_num;
	int				argc;
	int				time_stamp;
	int				time_to_live;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				death_flag;
	struct timeval	old_time;
	pthread_mutex_t	print;
	pthread_mutex_t	die;
}				t_param;

int				ft_atoi(const char *str);
void			print_status(t_param *param, int param_num, char *str);
void			ft_usleep(t_param *param, int num);
int				ft_strcmp(char *s1, char *s2);
void			mutex_init(t_param *param);
void			make_philo(t_param *param);
int				init_param(t_param *param, int argc, char **argv);
void			take_left_fork(t_param *param, int num);
void			take_right_fork(t_param *param, int num);
void			return_fork(t_param *param, int num);

#endif
