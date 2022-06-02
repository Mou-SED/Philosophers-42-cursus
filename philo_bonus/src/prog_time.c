/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prog_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 08:20:15 by moseddik          #+#    #+#             */
/*   Updated: 2022/06/02 14:58:06 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

time_t	get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

time_t	set_time(time_t init_time)
{
	return (get_time() - init_time);
}

void	ft_usleep(time_t time)
{
	time_t	start;

	start = get_time();
	while (get_time() - start < time)
		usleep(50);
}
