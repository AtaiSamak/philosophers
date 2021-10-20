#include "philo.h"

int ft_isNum(int c)
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

unsigned long long int getTime()
{
    struct timeval time;
    unsigned long long int currentTime;

    gettimeofday(&time, NULL);
    currentTime = (time.tv_sec * 1000) + (time.tv_usec / 1000);
    return(currentTime);
}