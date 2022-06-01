/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:42:46 by moseddik          #+#    #+#             */
/*   Updated: 2022/06/01 16:43:37 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	get_info(t_data *data, int ac, char **av)
{
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->n_must_eat = ft_atoi(av[5]);
}

static void	init_info(t_philos *philosophers, t_data *data, int ac, char **av)
{
	int	i;

	i = 0;
	get_info(data, ac, av);
	data->init_time = get_time();
	while (i < philosophers->num_philos)
	{
		philosophers[i].id = i;
		pthread_mutex_init(&(data->forks[i]), NULL);
		pthread_mutex_init(&(data->print_mutex), NULL);
		philosophers[i].right_fork = i;
		philosophers[i].left_fork = (i + 1) % philosophers->num_philos;
		philosophers[i].last_eat = 0;
		philosophers[i].philo_eat = 0;
		i++;
	}
}

static void	destroy_all(t_philos *philosophers, t_data *data)
{
	int	i;

	i = 0;
	while (i < philosophers->num_philos)
	{
		pthread_mutex_destroy(&(data->forks[i]));
		i++;
	}
	pthread_mutex_destroy(&(data->print_mutex));
	free(philosophers);
	free(data->forks);
	free(data);
}

int	main(int ac, char **av)
{
	t_philos	*philosophers;
	t_data		*data;

	if (ac != 5 && ac != 6)
		return (printf("Number of argument is invalid\n"), -1);
	if (check_argments(ac, av) == -1)
		return (-1);
	philosophers = alloc_philo(av);
	if (philosophers == NULL)
		return (-1);
	data = alloc_data(philosophers);
	if (data == NULL)
		return (-1);
	init_info(philosophers, data, ac, av);
	create_philos(philosophers, data);
	dying(philosophers);
	destroy_all(philosophers, data);
	return (0);
}
