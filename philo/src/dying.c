/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dying.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 08:07:40 by moseddik          #+#    #+#             */
/*   Updated: 2022/05/31 22:02:59 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_die(t_philos *philosophers)
{
	philosophers->philo_data->philo_die =
		set_time(philosophers->philo_data->init_time);
	if (philosophers->philo_data->philo_die - philosophers->last_eat
		>= philosophers->philo_data->time_to_die)
	{
		philosophers->philo_data->did_someone_die = 1;
		return (1);
	}
	return (0);
}

void	dying(t_philos *philosophers)
{
	int	i;

	i = 0;
	while (i <= philosophers->num_philos)
	{
		if (i == philosophers->num_philos)
			i = 0;
		if (is_die(&philosophers[i]))
		{
			print_routine("died",
				philosophers[i].philo_data->philo_die, &philosophers[i]);
			break ;
		}
		i++;
	}
}
