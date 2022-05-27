/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:42:46 by moseddik          #+#    #+#             */
/*   Updated: 2022/05/27 14:47:41 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// ! ./philo | number_of_philo | time_to_die | time_to_eat | time_to_sleep
//? optional argument number_or_times_each_philosopher_must_eat

void	print_routine(char *message, time_t time, t_philos *philosophers)
{
	printf("%ld %d %s\n",time , philosophers->id + 1, message);
}

void	get_info(t_data *data, char **av)
{
	data->time_to_eat = ft_atoi(av[3]);
}

int	eating(t_philos *philosophers)
{
	time_t	now;

	now = set_time(philosophers->philo_data->init_time);
	print_routine("is eating", now, philosophers);
	usleep(philosophers->philo_data->time_to_eat * 1000);
	return (1);
}

int	unlock_forks(t_philos *philosophers, int hand)
{
	pthread_mutex_unlock(&(philosophers->philo_data->forks)[hand]);
	return	(1);
}

int	taking_fork(t_philos *philosophers, int hand)
{
	time_t	now;

	pthread_mutex_lock(&(philosophers->philo_data->forks)[hand]);
	now = set_time(philosophers->philo_data->init_time);
	print_routine("has taken a fork", now, philosophers);
	return	(1);
}

void	*routine(void *philosophers)
{
	t_philos *philosopher;

	philosopher = (t_philos *)philosophers;
	while (1)
	{
		if (taking_fork(philosopher, philosopher->right_fork) == 0)
			return	(NULL);
		if (taking_fork(philosopher, philosopher->left_fork) == 0)
			return	(NULL);
		if (eating(philosopher) == 0)
			return	(NULL);
		if (unlock_forks(philosopher, philosopher->left_fork) == 0)
			return	(NULL);
		if (unlock_forks(philosopher, philosopher->left_fork) == 0)
			return	(NULL);
	}
	return (NULL);
}

time_t	get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

time_t	set_time(time_t init_time)
{
	return (get_time() - init_time);
}

int main (int ac, char **av)
{
	t_philos		*philosophers;
	t_data			*data;
	pthread_t		*philo;
	int 			i;

	philosophers = malloc(sizeof(t_philos) * ft_atoi(av[1]));
	philo = malloc(sizeof(pthread_t) * ft_atoi(av[1]));
	philosophers->num_philos = ft_atoi(av[1]);
	data = malloc(sizeof(t_data));
	data->forks = malloc(sizeof(pthread_mutex_t) * philosophers->num_philos);

	i = 0;
	get_info(data, av); //! get info of args
	while (i < philosophers->num_philos)
	{
		philosophers[i].id = i;
		pthread_mutex_init(&(data->forks[i]), NULL);
		philosophers[i].right_fork = i;
		philosophers[i].left_fork = (i + 1) % philosophers->num_philos;
		i++;
	}

	i = 0;
	if (ac == 5 || ac == 6)
	{
		if (ft_print_error(ac, av) == -1)
			return (-1);
		data->init_time = get_time();
		while (i < philosophers->num_philos)
		{
			philosophers[i].philo_data = data;
			pthread_create(&philo[i], NULL, &routine, &(philosophers[i]));
			pthread_detach(philo[i]);
			i++;
			usleep(100);
		}
	}
	else
		printf("Number of argument is invalid\n");
	pthread_mutex_destroy(data->forks);
	return (0);
}