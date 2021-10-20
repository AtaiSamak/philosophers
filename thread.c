#include "philo.h"

int runThreads(t_main *args)
{
    int i;

    i = -1;
    args->time = getTime();
    while(++i < args->setting.philos)
    {
        args->philo[i].lastEat = args->time;
    }
    return 1;
}