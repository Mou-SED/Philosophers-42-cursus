/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:14:06 by moseddik          #+#    #+#             */
/*   Updated: 2022/06/08 16:19:21 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int run_proccess(t_philos *philosophers)
{
	pthread_t	t1;
	philosophers = NULL;
	printf("Child - %d\n", getpid());
	if (pthread_create(&t1, NULL, &routine, &philosophers))
		printf("Error\n");
	pthread_join(t1, NULL);
	exit(0);
}

void	create_process(t_philos *philosophers)
{
	int			*is_create;
	int			i;

	is_create = malloc(sizeof(int) * philosophers->num_philos);
	i = -1;
	while (++i < philosophers->num_philos)
	{
		is_create[i] = fork();
		if (is_create[i] == -1)
			exit(1);
		if(is_create[i] == 0)
		{
			run_proccess(philosophers);
		}
	}
	i = -1;
	while (++i < 4)
		waitpid(-1, NULL, 0);
	i = -1;
	while (++i < 4)
		printf("\nis_create value : %d\n", is_create[i]);
}
