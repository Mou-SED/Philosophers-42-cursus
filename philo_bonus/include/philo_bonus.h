/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:49:56 by moseddik          #+#    #+#             */
/*   Updated: 2022/06/11 10:22:33 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <pthread.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <semaphore.h>

typedef struct s_data
{
	time_t			init_time;
	sem_t			*forks;
	sem_t			*print_sem;
	time_t			philo_die;
	useconds_t		time_to_eat;
	useconds_t		time_to_sleep;
	useconds_t		time_to_die;
	int				n_must_eat;
}	t_data;

typedef struct s_philos
{
	int				id;
	int				num_philos;
	int				philo_eat;
	useconds_t		last_eat;
	t_data			*philo_data;
}	t_philos;

int			ft_atoi(const char *str);
int			check_argments(int ac, char **av);
t_philos	*alloc_philos(char **av);
t_data		*alloc_data(t_philos *philosophers);
time_t		get_time(void);
time_t		set_time(time_t init_time);
void		ft_usleep(time_t time);
void		create_process(t_philos *philosophers);
void		*routine(void *philosophers);
void		print_routine(char *message, time_t time, t_philos *philosophers);
int			dying(t_philos *philosophers, pid_t *list_pid);

#endif