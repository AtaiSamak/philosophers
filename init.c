#include "philo.h"

int checkAndInitSettings(int argc, char **argv, t_main *args)
{
    int i;
    int j;

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
    return(1);
}

int initPhilosForks(t_main *args)
{
    int i;

    i = -1;
    args->philo = malloc(sizeof(t_philo) * args->setting.philos);
    if(args->philo == 0)
        return -1;
    while(++i < args->setting.philos)
    {
        args->philo[i].lastEat = 0;
        args->philo[i].died = 0;
        args->philo[i].id = i;
        pthread_mutex_init(&args->philo[i].fork_lock, NULL);
    }
    return(1);
}