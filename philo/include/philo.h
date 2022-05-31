/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:44:45 by moseddik          #+#    #+#             */
/*   Updated: 2022/05/31 16:51:14 by moseddik         ###   ########.fr       */
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
	time_t			philo_die;
	useconds_t		time_to_eat;
	useconds_t		time_to_sleep;
	useconds_t		time_to_die;
	time_t 			init_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	int				did_someone_die;
}	t_data;

typedef struct s_philos
{
	int				id;
	int				num_philos;
	int				right_fork;
	int				left_fork;
	useconds_t		last_eat;
	t_data			*philo_data;
}	t_philos;

int			ft_atoi(const char *str);
int			check_argments(int ac, char **av);
time_t		get_time(void);
time_t		set_time(time_t init_time);
void		*routine(void *philosophers);
void		print_routine(char *message, time_t time, t_philos *philosophers);
void		dying(t_philos *philosophers);

#endif
