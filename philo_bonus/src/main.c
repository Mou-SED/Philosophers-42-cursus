/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:55:25 by moseddik          #+#    #+#             */
/*   Updated: 2022/06/09 10:46:48 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	get_info(t_data *data, int ac, char **av)
{
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
	{
		data->n_must_eat = ft_atoi(av[5]);
		if (data->n_must_eat == 0)
			return (-1);
	}
	return (0);
}

static int	init_info(t_philos *philosophers, t_data *data, int ac, char **av)
{
	int	i;

	i = 0;
	if (get_info(data, ac, av) == -1)
		return (-1);
	data->init_time = get_time();
	while (i < philosophers->num_philos)
	{
		philosophers[i].philo_data = data;
		philosophers[i].id = i;
		philosophers[i].right_fork = i;
		philosophers[i].left_fork = (i + 1) % philosophers->num_philos;
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_philos	*philosophers;
	t_data		*data;

	if (ac != 5 && ac != 6)
		return (printf("Number of argument is invalid\n"), -1);
	if (check_argments(ac, av) == -1)
		return (-1);
	philosophers = alloc_philos(av);
	if (philosophers == NULL)
		return (-1);
	data = alloc_data(philosophers);
	if (data == NULL)
		return (-1);
	if (init_info(philosophers, data, ac, av) == -1)
	{
		free(philosophers);
		free(data);
		return (0);
	}
	create_process(philosophers);
	return (0);
}
