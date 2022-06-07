/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:14:06 by moseddik          #+#    #+#             */
/*   Updated: 2022/06/07 15:31:46 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	create_process(void)
{
	// pid_t 	c_pid;
	int 	is_create;
	int 	i;

	i = 0;
	while (i < 4)
	{
		is_create = fork();
		i++;
		if (is_create == -1)
			exit(1);
		if (is_create != 0)
		{
			waitpid(is_create, NULL, 0);
			printf("Parent - %d\n", getpid());
		}
		else
		{
			printf("Child - %d\n", getpid());
			exit(0);
		}
	}
}
