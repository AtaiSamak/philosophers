/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahsoka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:36:21 by bahsoka           #+#    #+#             */
/*   Updated: 2021/10/21 16:36:23 by bahsoka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	checkAndInitSettings(int argc, char **argv, t_main *args)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j] != '\0')
			if (ft_isNum(argv[i][j++]) == 0)
				return (-1);
		i++;
	}
	args->setting.philos = ft_atoi(argv[1]);
	args->setting.die = ft_atoi(argv[2]);
	args->setting.eat = ft_atoi(argv[3]);
	args->setting.sleep = ft_atoi(argv[4]);
	args->setting.stopTime = 0;
	if (argc == 6)
		args->setting.stopTime = ft_atoi(argv[5]);
	return (1);
}

int	initSemaphores(t_main *args)
{
	args->forks = sem_open("forks", O_CREAT | \
	O_EXCL, 0644, args->setting.philos);
	args->eat = sem_open("eat", O_CREAT | O_EXCL, 0644, 1);
	args->write = sem_open("write", O_CREAT | O_EXCL, 0644, 1);
	args->finish = sem_open("finish", O_CREAT | O_EXCL, 0644, 0);
	args->check = sem_open("check", O_CREAT | O_EXCL, 0644, 1);
	args->amountAte = sem_open("amountAte", O_CREAT | O_EXCL, 0644, 1);
	if (args->write == SEM_FAILED || args->eat == SEM_FAILED || \
	args->forks == SEM_FAILED || args->finish == SEM_FAILED || \
	args->check == SEM_FAILED || args->amountAte == SEM_FAILED)
	{
		clearSems(args);
		return (-1);
	}
	return (1);
}

int	initPhilosForks(t_main *args)
{
	int	i;

	i = -1;
	args->philo = malloc(sizeof(t_philo) * args->setting.philos);
	if (args->philo == 0)
		return (-1);
	while (++i < args->setting.philos)
	{
		args->philo[i].lastEat = 0;
		args->philo[i].id = i;
		args->philo[i].args = args;
		args->philo[i].eats = 0;
	}
	clearSems(args);
	if (initSemaphores(args) == -1)
		return (-1);
	return (1);
}
