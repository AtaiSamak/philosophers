#ifndef PHILO_H
# define PHILO_H

# include "stdio.h"
# include "stdlib.h"
# include "unistd.h"
# include "pthread.h"

typedef struct s_philo
{
    int philos;
    int forks;
    int sleep;
    int eat;
    int die;
    int stopTime;
} t_philo;

int ft_atoi(const char *str);

#endif