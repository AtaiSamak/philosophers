#ifndef PHILO_H
# define PHILO_H

# include "stdio.h"
# include "stdlib.h"
# include "unistd.h"
# include "pthread.h"
# include "sys/time.h"

typedef struct s_philo
{
    unsigned long long int  lastEat;
    int         id;
    int         eats;
    int         died;
    pthread_t   philo;
    pthread_mutex_t fork_lock;
}               t_philo;

typedef struct s_setting
{
    int philos;
    int sleep;
    int eat;
    int die;
    int stopTime;
}               t_setting;

typedef struct s_main
{
    unsigned long long int time;
    t_setting setting;
    t_philo *philo;
    pthread_mutex_t eat;
    pthread_mutex_t write;
}               t_main;

int ft_atoi(const char *str);
int checkAndInitSettings(int argc, char **argv, t_main *args);
int initPhilosForks(t_main *args);
int ft_isNum(int c);
unsigned long long int getTime();
int runThreads(t_main *args);

#endif