/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:42:46 by moseddik          #+#    #+#             */
/*   Updated: 2022/05/29 18:57:32 by moseddik         ###   ########.fr       */
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
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
}

void	init_info(t_philos *philosophers, t_data *data, char **av)
{
	int	i;

	i = 0;
	get_info(data, av);
	while (i < philosophers->num_philos)
	{
		philosophers[i].id = i;
		pthread_mutex_init(&(data->forks[i]), NULL);
		philosophers[i].right_fork = i;
		philosophers[i].left_fork = (i + 1) % philosophers->num_philos;
		i++;
	}
}

int main (int ac, char **av)
{
	t_philos		*philosophers;
	t_data			*data;
	pthread_t		philo;
	int 			i;

	i = 0;
	if (ac == 5 || ac == 6)
	{
		if (check_argments(ac, av) == -1)
			return (-1);

		philosophers = malloc(sizeof(t_philos) * ft_atoi(av[1]));
		if (philosophers == NULL)
			return (1);
		philosophers->num_philos = ft_atoi(av[1]);
		data = malloc(sizeof(t_data));
		if (data == NULL)
			return (free(philosophers), 1);
		data->forks = malloc(sizeof(pthread_mutex_t) * philosophers->num_philos);
		if (data->forks == NULL)
			return (free(philosophers), free(data), 1);

		data->init_time = get_time();
		init_info(philosophers, data, av);
		while (i < philosophers->num_philos)
		{
			philosophers[i].philo_data = data;
			pthread_create(&philo, NULL, &routine, &(philosophers[i]));
			pthread_detach(philo);
			i++;
			usleep(500);
		}
		while (1);
		pthread_mutex_destroy(data->forks);
		return (free(philosophers), free(data->forks), free(data), 0);
	}
	else
		return (printf("Number of argument is invalid\n"), 1);
	return (0);
}
