/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:21:10 by moseddik          #+#    #+#             */
/*   Updated: 2022/06/08 16:22:10 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	print_routine(char *message, time_t time, t_philos *philosophers)
{
	printf("%ld %d %s\n", time, philosophers->id + 1, message);
}
