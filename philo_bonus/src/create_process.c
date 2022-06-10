/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:14:06 by moseddik          #+#    #+#             */
/*   Updated: 2022/06/10 21:20:42 by moseddik         ###   ########.fr       */
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
	int	j;
	int	status;

	i = -1;
	j = 0;
	waitpid(-1, &status, 0);
	while (++i < philosophers->num_philos)
	{
		if (WEXITSTATUS(status) == 2)
		{
			while (j < philosophers->num_philos)
			{
				kill(list_pid[j], SIGINT);
				j++;
			}
		}
		if (WEXITSTATUS(status) == 3)
			waitpid(-1, &status, 0);
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
			sem_unlink("/forks");
			sem_close(philosophers->philo_data->forks);
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
