/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 09:20:47 by moseddik          #+#    #+#             */
/*   Updated: 2022/06/01 09:22:14 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (s1[i] != s2[i])
	{
		if (s1[i] < s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		else if (s1[i] > s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}

void	print_routine(char *message, time_t time, t_philos *philosophers)
{
	pthread_mutex_lock(&(philosophers->philo_data->print_mutex));
	printf("%ld %d %s\n", time, philosophers->id + 1, message);
	if (ft_strcmp(message, "died") == 0)
		return ;
	pthread_mutex_unlock(&(philosophers->philo_data->print_mutex));
}
