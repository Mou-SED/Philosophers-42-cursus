/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:15:21 by moseddik          #+#    #+#             */
/*   Updated: 2022/06/08 16:19:47 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*routine(void *philosophers)
{
	t_philos	*philosopher;

	philosopher = (t_philos *)philosophers;
	printf("he!\n");
	return (NULL);
}
