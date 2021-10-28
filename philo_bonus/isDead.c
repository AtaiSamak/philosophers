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

void	*isFinish(void *arg)
{
	int i;
	t_main *args;

	args = (t_main *)arg;
	i = -1;
	sem_wait(args->finish);
	killProcess(args);
	clearSems(args);
	return(NULL);
}

void	*isDead(void *arg)
{
	unsigned long long int	time;
	t_philo					*philo;

	philo = (t_philo *)arg;
	while(1)
	{
		sem_wait(philo->args->check);
		time = getTime();
		if (time - philo->lastEat \
		> (unsigned long long int)philo->args->setting.die)
		{
			msg(" died\n", philo->id, philo->args, 6);
			sem_post(philo->args->finish);
			return(NULL);
		}
		sem_post(philo->args->check);
	}
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
		sem_wait(args->write);
		return (-1);
	}
	return (1);
}