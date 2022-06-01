/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 08:22:32 by moseddik          #+#    #+#             */
/*   Updated: 2022/06/01 15:13:38 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	taking_fork(t_philos *philosophers, int hand)
{
	time_t	now;

	pthread_mutex_lock(&(philosophers->philo_data->forks)[hand]);
	now = set_time(philosophers->philo_data->init_time);
	print_routine("has taken a fork", now, philosophers);
	return (1);
}

int	unlock_forks(t_philos *philosophers, int hand)
{
	pthread_mutex_unlock(&(philosophers->philo_data->forks)[hand]);
	return (1);
}

int	eating(t_philos *philosophers)
{
	time_t	now;

	now = set_time(philosophers->philo_data->init_time);
	philosophers->last_eat = now;
	print_routine("is eating", now, philosophers);
	ft_usleep(philosophers->philo_data->time_to_eat);
	philosophers->philo_eat++;
	if (philosophers->philo_eat == philosophers->philo_data->n_must_eat)
		philosophers->philo_data->philos_eats++;
	return (1);
}

int	sleeping(t_philos *philosophers)
{
	time_t	now;

	now = set_time(philosophers->philo_data->init_time);
	print_routine("is sleeping", now, philosophers);
	ft_usleep(philosophers->philo_data->time_to_sleep);
	return (1);
}

void	*routine(void *philosophers)
{
	t_philos	*philosopher;

	philosopher = (t_philos *)philosophers;
	if (philosopher->id % 2 == 1)
		usleep(50);
	while (1)
	{
		if (taking_fork(philosopher, philosopher->right_fork) == 0)
			return (NULL);
		if (taking_fork(philosopher, philosopher->left_fork) == 0)
			return (NULL);
		if (eating(philosopher) == 0)
			return (NULL);
		if (unlock_forks(philosopher, philosopher->right_fork) == 0)
			return (NULL);
		if (unlock_forks(philosopher, philosopher->left_fork) == 0)
			return (NULL);
		if (sleeping(philosopher) == 0)
			return (NULL);
		print_routine("is thinking",
			set_time(philosopher->philo_data->init_time), philosopher);
	}
	return (NULL);
}
