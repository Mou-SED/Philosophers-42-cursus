/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_structs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 09:58:13 by moseddik          #+#    #+#             */
/*   Updated: 2022/06/01 17:14:13 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philos	*alloc_philos(char **av)
{
	t_philos	*philosophers;
	int			num_philos;

	num_philos = ft_atoi(av[1]);
	philosophers = malloc(sizeof(t_philos) * num_philos);
	if (philosophers == NULL)
		return (NULL);
	memset(philosophers, 0, sizeof(t_philos) * num_philos);
	philosophers->num_philos = num_philos;
	return (philosophers);
}

t_data	*alloc_data(t_philos *philosophers)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (data == NULL)
		return (free(philosophers), NULL);
	memset(data, 0, sizeof(t_data));
	data->forks = malloc(sizeof(pthread_mutex_t) * philosophers->num_philos);
	if (data->forks == NULL)
		return (free(philosophers), free(data), NULL);
	memset(data->forks, 0, sizeof(pthread_mutex_t) * philosophers->num_philos);
	return (data);
}
