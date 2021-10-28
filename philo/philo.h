/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahsoka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:47:27 by bahsoka           #+#    #+#             */
/*   Updated: 2021/10/21 16:47:29 by bahsoka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "stdio.h"
# include "stdlib.h"
# include "unistd.h"
# include "pthread.h"
# include "sys/time.h"

struct	s_main;

typedef struct s_philo
{
	unsigned long long int	lastEat;
	int						id;
	int						eats;
	int						died;
	pthread_t				philo;
	pthread_mutex_t			fork_lock;
	struct s_main			*args;
}				t_philo;

typedef struct s_setting
{
	int	philos;
	int	sleep;
	int	eat;
	int	die;
	int	stopTime;
}				t_setting;

typedef struct s_main
{
	unsigned long long int	time;
	t_setting				setting;
	t_philo					*philo;
	pthread_mutex_t			eat;
	pthread_mutex_t			write;
}				t_main;

int						ft_atoi(const char *str);
int						checkAndInitSettings(int argc, \
						char **argv, t_main *args);
int						initPhilosForks(t_main *args);
int						ft_isNum(int c);
unsigned long long int	getTime(void);
int						runThreads(t_main *args);
void					ft_usleep(unsigned int n);
void					ft_putnbr(unsigned long long n);
int						isDead(t_main *args);
void					msg(char *message, int id, t_main *args, int len);
int						isEnd(t_main *args);

#endif
