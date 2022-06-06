/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 09:20:47 by moseddik          #+#    #+#             */
/*   Updated: 2022/06/06 18:53:59 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_routine(char *message, time_t time, t_philos *philosophers)
{
	pthread_mutex_lock(&(philosophers->philo_data->print_mutex));
	if (message == NULL)
	{
		printf("%ld %d %s\n", time, philosophers->id + 1, "died");
		return ;
	}
	printf("%ld %d %s\n", time, philosophers->id + 1, message);
	pthread_mutex_unlock(&(philosophers->philo_data->print_mutex));
}
