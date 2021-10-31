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
	sem_wait(args->write);
	ft_putnbr(getTime() - args->time);
	write(1, " ", 1);
	ft_putnbr(id + 1);
	write(1, " ", 1);
	write(1, message, len);
	if (len != 6)
		sem_post(args->write);
}

void	takeForks(t_main *args, int id)
{
	sem_wait(args->eat);
	sem_wait(args->forks);
	msg(" has taken a fork\n", id, args, 18);
	sem_wait(args->forks);
	msg(" has taken a fork\n", id, args, 18);
	sem_post(args->eat);
}

int	runRoutine(t_philo *philo)
{
	pthread_t	thread;

	pthread_create(&thread, NULL, isDead, philo);
	if (philo->id == 0 || (philo->id + 1) % 2 == 1)
		ft_usleep(philo->args->setting.eat * 1000);
	while (1)
	{
		takeForks(philo->args, philo->id);
		philo->eats++;
		msg(" is eating\n", philo->id, philo->args, 11);
		ft_usleep(philo->args->setting.eat * 1000);
		philo->lastEat = getTime();
		if (philo->eats == philo->args->setting.stopTime)
			sem_post(philo->args->amountAte);
		msg(" is sleeping\n", philo->id, philo->args, 13);
		sem_post(philo->args->forks);
		sem_post(philo->args->forks);
		ft_usleep(philo->args->setting.sleep * 1000);
		msg(" is thinking\n", philo->id, philo->args, 13);
	}
	return (1);
}

int	runProcess(t_main *args)
{
	int	i;

	i = -1;
	args->time = getTime();
	while (++i < args->setting.philos)
	{
		args->philo[i].lastEat = args->time;
		args->philo[i].pid = fork();
		if (args->philo[i].pid == 0)
			return (runRoutine(&args->philo[i]));
		else if (args->philo[i].pid < 0)
			return (-1);
	}
	return (0);
}
