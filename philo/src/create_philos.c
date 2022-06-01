/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 09:59:49 by moseddik          #+#    #+#             */
/*   Updated: 2022/06/01 10:00:14 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_philos(t_philos *philosophers, t_data *data)
{
	int				i;
	pthread_t		philo;

	i = 0;
	while (i < philosophers->num_philos)
	{
		philosophers[i].last_eat = 0;
		philosophers[i].philo_data = data;
		pthread_create(&philo, NULL, &routine, &(philosophers[i]));
		pthread_detach(philo);
		i++;
		usleep(200);
	}
}
