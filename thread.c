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

int	setPrev(t_philo *philo)
{
	int	prev;

	if (philo->id == 0 || (philo->id + 1) % 2 == 1)
	{
		prev = philo->id - 1;
		if (philo->id == 0)
			prev = philo->args->setting.philos - 1;
	}
	else
	{
		prev = philo->id + 1;
		if (philo->id == philo->args->setting.philos - 1)
			prev = 0;
	}
	return (prev);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	int		prev;
	int		next;

	philo = (t_philo *)arg;
	next = philo->id;
	prev = setPrev(philo);
	isEating(philo->args, prev, next);
	philo->eats++;
	msg(" is eating\n", next, philo->args, 11);
	ft_usleep(philo->args->setting.eat * 1000);
	philo->lastEat = getTime();
	msg(" is sleeping\n", next, philo->args, 13);
	pthread_mutex_unlock(&philo->args->philo[prev].fork_lock);
	pthread_mutex_unlock(&philo->args->philo[next].fork_lock);
	ft_usleep(philo->args->setting.sleep * 1000);
	msg(" is thinking\n", next, philo->args, 13);
	if (philo->died == 0)
		routine(philo);
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
