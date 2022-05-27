/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:44:45 by moseddik          #+#    #+#             */
/*   Updated: 2022/05/27 14:41:35 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <stdio.h>

typedef struct s_data
{
	int				time_to_eat;
	time_t 			init_time;
	pthread_mutex_t	*forks;
}	t_data;

typedef struct s_philos
{
	int				id;
	int				num_philos;
	int				right_fork;
	int				left_fork;
	t_data			*philo_data;
}	t_philos;

int			ft_atoi(const char *str);
int			ft_print_error(int ac, char **av);
time_t		set_time(time_t init_time);

#endif
