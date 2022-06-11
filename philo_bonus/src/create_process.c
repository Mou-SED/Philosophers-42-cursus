/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:14:06 by moseddik          #+#    #+#             */
/*   Updated: 2022/06/11 10:22:56 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	run_proccess(t_philos *philosophers, pid_t *list_pid)
{
	pthread_t	t1;

	pthread_create(&t1, NULL, &routine, philosophers);
	pthread_detach(t1);
	return (dying(philosophers, list_pid));
}

static void	kill_process(t_philos *philosophers, pid_t *list_pid)
{
	int	i;
	int	status;

	i = 0;
	waitpid(-1, &status, 0);
	while (i < philosophers->num_philos)
	{
		if (WEXITSTATUS(status) == 2)
			kill(list_pid[i], SIGINT);
		i++;
	}
	i = 0;
	while (i < philosophers->num_philos)
	{
		if (WEXITSTATUS(status) == 3)
			waitpid(-1, &status, 0);
		i++;
	}
}

static void	run_proccess_with_free(t_philos *philosophers, int *list_pid, int i)
{
	int	ikes;

	ikes = run_proccess(&philosophers[i], list_pid);
	free(philosophers->philo_data);
	free(philosophers);
	free(list_pid);
	exit(ikes);
}

void	create_process(t_philos *philosophers)
{
	pid_t	*list_pid;
	int		i;

	list_pid = malloc(sizeof(pid_t) * philosophers->num_philos);
	i = -1;
	while (++i < philosophers->num_philos)
	{
		list_pid[i] = fork();
		if (list_pid[i] == -1)
		{
			printf("No child process is created!\n");
			sem_close(philosophers->philo_data->forks);
			sem_close(philosophers->philo_data->print_sem);
			sem_unlink("/forks");
			sem_unlink("/print_sem");
			free(philosophers->philo_data);
			free(philosophers);
			free(list_pid);
			exit(EXIT_FAILURE);
		}
		if (list_pid[i] == 0)
			run_proccess_with_free(philosophers, list_pid, i);
	}
	kill_process(philosophers, list_pid);
	free(list_pid);
}
