/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahsoka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:41:50 by bahsoka           #+#    #+#             */
/*   Updated: 2021/10/21 16:41:52 by bahsoka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	msg(char *message, int id, t_main *args, int len)
{
	pthread_mutex_lock(&args->write);
	ft_putnbr(getTime() - args->time);
	write(1, " ", 1);
	ft_putnbr(id + 1);
	write(1, " ", 1);
	write(1, message, len);
	if (len != 6)
		pthread_mutex_unlock(&args->write);
}

void	isEating(t_main *args, int prev, int next)
{
	pthread_mutex_lock(&args->eat);
	pthread_mutex_lock(&args->philo[prev].fork_lock);
	msg(" has taken a fork\n", next, args, 18);
	pthread_mutex_lock(&args->philo[next].fork_lock);
	msg(" has taken a fork\n", next, args, 18);
	pthread_mutex_unlock(&args->eat);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id == 0 || (philo->id + 1) % 2 == 1)
		ft_usleep(philo->args->setting.eat * 1000);
	while (1)
	{
		isEating(philo->args, philo->fork_two, philo->fork_one);
		philo->eats++;
		msg(" is eating\n", philo->id, philo->args, 11);
		ft_usleep(philo->args->setting.eat * 1000);
		philo->lastEat = getTime();
		msg(" is sleeping\n", philo->id, philo->args, 13);
		pthread_mutex_unlock(&philo->args->philo[philo->fork_one].fork_lock);
		pthread_mutex_unlock(&philo->args->philo[philo->fork_two].fork_lock);
		ft_usleep(philo->args->setting.sleep * 1000);
		msg(" is thinking\n", philo->id, philo->args, 13);
	}
	return (NULL);
}

int	runThreads(t_main *args)
{
	int	i;

	i = -1;
	args->time = getTime();
	pthread_mutex_init(&args->write, NULL);
	pthread_mutex_init(&args->eat, NULL);
	while (++i < args->setting.philos)
	{
		args->philo[i].lastEat = args->time;
		pthread_create(&args->philo[i].philo, NULL, routine, &args->philo[i]);
	}
	while (1)
	{
		if (isDead(args) == -1 || \
		(args->setting.stopTime != 0 && isEnd(args) == -1))
		{
			pthread_mutex_destroy(&args->write);
			pthread_mutex_destroy(&args->eat);
			return (-1);
		}
		usleep(100);
	}
	return (1);
}
