/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isDead.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahsoka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:38:04 by bahsoka           #+#    #+#             */
/*   Updated: 2021/10/21 16:38:06 by bahsoka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	isDead(t_main *args)
{
	int						i;
	unsigned long long int	time;

	time = getTime();
	i = -1;
	while (++i < args->setting.philos)
	{
		if (time - args->philo[i].lastEat \
		> (unsigned long long int)args->setting.die)
		{
			msg(" died\n", args->philo[i].id, args, 6);
			return (-1);
		}
	}
	return (1);
}

int	isEnd(t_main *args)
{
	int	i;

	i = -1;
	while (++i < args->setting.philos)
	{
		if (args->philo[i].eats < args->setting.stopTime)
			break ;
	}
	if (i == args->setting.philos)
	{
		pthread_mutex_lock(&args->write);
		return (-1);
	}
	return (1);
}
