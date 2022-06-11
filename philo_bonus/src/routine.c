/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:15:21 by moseddik          #+#    #+#             */
/*   Updated: 2022/06/11 10:22:11 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	taking_fork(t_philos *philosophers)
{
	time_t	now;

	sem_wait(philosophers->philo_data->forks);
	now = set_time(philosophers->philo_data->init_time);
	print_routine("has taken a fork", now, philosophers);
}

void	eating(t_philos *philosophers)
{
	time_t	now;

	now = set_time(philosophers->philo_data->init_time);
	philosophers->last_eat = now;
	print_routine("is eating", now, philosophers);
	ft_usleep(philosophers->philo_data->time_to_eat);
}

void	sleeping(t_philos *philosophers)
{
	time_t	now;

	now = set_time(philosophers->philo_data->init_time);
	print_routine("is sleeping", now, philosophers);
	ft_usleep(philosophers->philo_data->time_to_sleep);
	print_routine("is thinking",
		set_time(philosophers->philo_data->init_time), philosophers);
}

void	*routine(void *philosophers)
{
	t_philos	*philosopher;

	philosopher = (t_philos *)philosophers;
	while (1)
	{
		taking_fork(philosopher);
		taking_fork(philosopher);
		eating(philosopher);
		sem_post(philosopher->philo_data->forks);
		sem_post(philosopher->philo_data->forks);
		philosopher->philo_eat++;
		if (philosopher->philo_eat == philosopher->philo_data->n_must_eat)
			break ;
		sleeping(philosopher);
	}
	exit(3);
	return (NULL);
}
