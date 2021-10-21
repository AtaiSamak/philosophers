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

int	main(int argc, char **argv)
{
	t_main	args;

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
	if (initPhilosForks(&args) == -1)
		return (-1);
	if (runThreads(&args) == -1)
		return (-1);
	pthread_mutex_destroy(&args.eat);
	pthread_mutex_destroy(&args.write);
	free(args.philo);
}
