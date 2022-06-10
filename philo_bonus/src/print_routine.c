/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:21:10 by moseddik          #+#    #+#             */
/*   Updated: 2022/06/10 20:53:12 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	print_routine(char *message, time_t time, t_philos *philosophers)
{
	sem_wait(philosophers->philo_data->print_sem);
	if (message == NULL)
	{
		printf("%ld %d %s\n", time, philosophers->id + 1, "died");
		return ;
	}
	printf("%ld %d %s\n", time, philosophers->id + 1, message);
	sem_post(philosophers->philo_data->print_sem);
}
