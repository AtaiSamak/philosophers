/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahsoka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:34:07 by bahsoka           #+#    #+#             */
/*   Updated: 2021/10/21 16:34:09 by bahsoka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void clearSems(t_main *args)
{
	sem_unlink("forks");
	sem_unlink("eat");
	sem_unlink("write");
	sem_unlink("check");
	sem_unlink("finish");
	sem_unlink("amountAte");
	sem_close(args->forks);
	sem_close(args->eat);
	sem_close(args->write);
	sem_close(args->check);
	sem_close(args->finish);
	sem_close(args->amountAte);
}

void killProcess(t_main *args)
{
	int	i;

	i = -1;
	while(++i < args->setting.philos)
	{
		kill(args->philo[i].pid, SIGTERM);
	}
}

int	main(int argc, char **argv)
{
	t_main	args;
	pthread_t thread; 

	if (argc == 5 || argc == 6)
	{
		if (checkAndInitSettings(argc, argv, &args) == -1)
			return (-1);
	}
	else
	{
		printf("Error. Please write correct!\n");
		return (-1);
	}
	clearSems(&args);
	if (initPhilosForks(&args) == -1)
		return (-1);
	runProcess(&args);
	if(args.setting.stopTime > 0)
		pthread_create(&thread, NULL, ateEnough, &args);
	pthread_create(&thread, NULL, isFinish, &args);
	pthread_join(thread, NULL);
	return(0);
}
