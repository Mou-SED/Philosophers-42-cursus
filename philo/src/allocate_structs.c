/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_structs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 09:58:13 by moseddik          #+#    #+#             */
/*   Updated: 2022/06/01 09:58:47 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philos	*alloc_philo(char **av)
{
	t_philos	*philosophers;

	philosophers = malloc(sizeof(t_philos) * ft_atoi(av[1]));
	if (philosophers == NULL)
		return (NULL);
	philosophers->num_philos = ft_atoi(av[1]);
	return (philosophers);
}

t_data	*alloc_data(t_philos *philosophers)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (data == NULL)
		return (free(philosophers), NULL);
	data->forks = malloc(sizeof(pthread_mutex_t) * philosophers->num_philos);
	if (data->forks == NULL)
		return (free(philosophers), free(data), NULL);
	return (data);
}
