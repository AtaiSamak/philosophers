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
# include "semaphore.h"
# include "signal.h"

struct	s_main;

typedef struct s_philo
{
	unsigned long long int	lastEat;
	int						id;
	int						eats;
	int						died;
	pid_t					pid;
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
	sem_t					*write;
	sem_t					*eat;
	sem_t					*forks;
	sem_t					*check;
	sem_t					*finish;
}				t_main;

int						ft_atoi(const char *str);
int						checkAndInitSettings(int argc, \
						char **argv, t_main *args);
int						initPhilosForks(t_main *args);
int						ft_isNum(int c);
unsigned long long int	getTime(void);
int						runProcess(t_main *args);
void					ft_usleep(unsigned int n);
void					ft_putnbr(unsigned long long n);
void					*isDead(void *arg);
void					msg(char *message, int id, t_main *args, int len);
int						isEnd(t_main *args);
void					clearSems(t_main *args);
int						isEnd(t_main *args);
void					killProcess(t_main *args);
void					*isFinish(void *arg);

#endif
