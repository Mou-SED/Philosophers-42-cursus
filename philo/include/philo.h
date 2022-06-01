/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:44:45 by moseddik          #+#    #+#             */
/*   Updated: 2022/06/01 15:13:31 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <string.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>

typedef struct s_data
{
	time_t			init_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	time_t			philo_die;
	useconds_t		time_to_eat;
	useconds_t		time_to_sleep;
	useconds_t		time_to_die;
	int				n_must_eat;
	int				philos_eats;
}	t_data;

typedef struct s_philos
{
	int				id;
	int				num_philos;
	int				right_fork;
	int				left_fork;
	int				philo_eat;
	useconds_t		last_eat;
	t_data			*philo_data;
}	t_philos;

int			ft_atoi(const char *str);
int			check_argments(int ac, char **av);
time_t		get_time(void);
time_t		set_time(time_t init_time);
t_philos	*alloc_philo(char **av);
t_data		*alloc_data(t_philos *philosophers);
void		create_philos(t_philos *philosophers, t_data *data);
void		*routine(void *philosophers);
void		print_routine(char *message, time_t time, t_philos *philosophers);
void		dying(t_philos *philosophers);
void		ft_usleep(time_t time);

#endif
