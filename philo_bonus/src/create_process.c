/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:14:06 by moseddik          #+#    #+#             */
/*   Updated: 2022/06/09 10:58:20 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int run_proccess(t_philos *philosophers)
{
	pthread_t	t1;

	if (pthread_create(&t1, NULL, &routine, philosophers))
		printf("Error\n");
	pthread_join(t1, NULL);
	exit(0);
}

void	create_process(t_philos *philosophers)
{
	int			*list_pid;
	int			i;

	list_pid = malloc(sizeof(int) * philosophers->num_philos);
	i = -1;
	while (++i < philosophers->num_philos)
	{
		list_pid[i] = fork();
		if (list_pid[i] == -1)
			exit(1);
		if(list_pid[i] == 0)
		{
			run_proccess(&philosophers[i]);
		}
	}
	i = -1;
	while (++i < 4)
		waitpid(-1, NULL, 0);
}
