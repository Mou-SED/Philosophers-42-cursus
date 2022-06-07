/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 08:22:32 by moseddik          #+#    #+#             */
/*   Updated: 2022/06/07 10:44:01 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	taking_fork(t_philos *philosophers, int hand)
{
	time_t	now;

	pthread_mutex_lock(&(philosophers->philo_data->forks)[hand]);
	now = set_time(philosophers->philo_data->init_time);
	print_routine("has taken a fork", now, philosophers);
}

void	unlock_forks(t_philos *philosophers, int hand)
{
	pthread_mutex_unlock(&(philosophers->philo_data->forks)[hand]);
}

void	eating(t_philos *philosophers, time_t *now)
{
	philosophers->last_eat = *now;
	print_routine("is eating", *now, philosophers);
	ft_usleep(philosophers->philo_data->time_to_eat);
	philosophers->philo_eat++;
	if (philosophers->philo_eat == philosophers->philo_data->n_must_eat)
		philosophers->philo_data->philos_eats++;
}

void	sleeping(t_philos *philosophers, time_t *now)
{
	print_routine("is sleeping", *now, philosophers);
	ft_usleep(philosophers->philo_data->time_to_sleep);
}

void	*routine(void *philosophers)
{
	t_philos	*philosopher;
	time_t		time_after_unlock;
	time_t		time_after_lock;
	time_t		time_after_sleep;

	philosopher = (t_philos *)philosophers;
	if (philosopher->id % 2 == 1)
		usleep(100);
	while (1)
	{
		taking_fork(philosopher, philosopher->right_fork);
		taking_fork(philosopher, philosopher->left_fork);
		time_after_lock = set_time(philosopher->philo_data->init_time);
		eating(philosopher, &time_after_lock);
		unlock_forks(philosopher, philosopher->right_fork);
		unlock_forks(philosopher, philosopher->left_fork);
		time_after_unlock = set_time(philosopher->philo_data->init_time);
		sleeping(philosopher, &time_after_unlock);
		time_after_sleep = set_time(philosopher->philo_data->init_time);
		print_routine("is thinking",
			time_after_sleep, philosopher);
	}
	return (NULL);
}
