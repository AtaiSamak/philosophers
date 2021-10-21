/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahsoka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:39:37 by bahsoka           #+#    #+#             */
/*   Updated: 2021/10/21 16:41:39 by bahsoka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isNum(int c)
{
	if ((c >= 48 && c <= 57))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

unsigned long long int	getTime(void)
{
	struct timeval			time;
	unsigned long long int	currentTime;

	gettimeofday(&time, NULL);
	currentTime = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (currentTime);
}

void	ft_usleep(unsigned int n)
{
	struct timeval	start;
	struct timeval	step;

	gettimeofday(&start, NULL);
	while (1)
	{
		usleep(50);
		gettimeofday(&step, NULL);
		if ((size_t)(((size_t)(step.tv_sec - start.tv_sec)) * 1000000 +
		((size_t)(step.tv_usec - start.tv_usec))) > n)
			break ;
	}
}

void	ft_putnbr(unsigned long long n)
{
	char	c;

	if (n < 10)
	{
		c = n + '0';
		write(1, &c, 1);
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}
