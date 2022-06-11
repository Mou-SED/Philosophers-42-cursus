/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:19:14 by moseddik          #+#    #+#             */
/*   Updated: 2022/06/11 09:15:02 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static	int	ft_isdigit(int c)
{
	if ((c >= 48 && c <= 57))
	{
		return (!0);
	}
	else
		return (0);
}

static int	is_plus_or_minus(int c)
{
	if (c == '+' || c == '-')
		return (!0);
	return (0);
}

static int	is_space(int c)
{
	if (c == ' ' || c == '\t' || c == 32)
		return (!0);
	return (0);
}

static int	check_error(char *str)
{
	int	value;

	value = 0;
	if (is_plus_or_minus(*str) && !ft_isdigit(*(str + 1)))
		return (1);
	if (is_plus_or_minus(*str) && str++)
		value = 0;
	while (*str)
	{
		while (is_space(*str))
			str++;
		if (!ft_isdigit(*str))
			value = 1;
		str++;
	}
	return (value);
}

int	check_argments(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
		if (ft_atoi(av[i++]) < 0)
			return (printf("This is not a valide value!\n"), -1);
	i = 1;
	while (i < ac)
		if (check_error(av[i++]))
			return (printf("This is not a valide value!\n"), -1);
	return (0);
}
