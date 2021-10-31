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

int	setForkTwo(t_philo *philo)
{
	int	fork_two;

	fork_two = philo->id - 1;
	if (philo->id == 0)
		fork_two = philo->args->setting.philos - 1;
	return (fork_two);
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
		args->philo[i].fork_one = i;
		args->philo[i].fork_two = setForkTwo(&args->philo[i]);
		pthread_mutex_init(&args->philo[i].fork_lock, NULL);
	}
	return (1);
}
