#ifndef PHILO_H
#define PHILO_H

typedef struct s_philo
{
    int philos;
    int sleep;
    int eat;
    int die;
    int stopTime;
} t_philo;

int ft_atoi(const char *str);

#endif