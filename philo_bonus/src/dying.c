/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dying.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:16:23 by moseddik          #+#    #+#             */
/*   Updated: 2022/06/11 07:20:44 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	is_die(t_philos *philosophers)
{
	philosophers->philo_data->philo_die
		= set_time(philosophers->philo_data->init_time);
	if (philosophers->philo_data->philo_die - philosophers->last_eat
		>= philosophers->philo_data->time_to_die)
		return (1);
	return (0);
}

int	dying(t_philos *philosophers, pid_t *list_pid)
{
	(void)list_pid;
	while (1)
	{
		if (is_die(philosophers))
		{
			print_routine(NULL,
				set_time(philosophers->philo_data->init_time), philosophers);
			return (2);
		}
		if (philosophers->philo_data->philos_eats == 1)
		{
			return (3);
		}
	}
}
