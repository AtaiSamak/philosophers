#include "philo.h"

int ft_atoi(const char *str)
{
    int i;
    int min;
    unsigned long int res;

    i = 0;
    min = 1;
    res = 0;
    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            min *= -1;
        i++;
    }
    while (str[i] >= 48 && str[i] <= 57)
    {
        res = res * 10 + str[i] - '0';
        i++;
    }
    if (res > 9223372036854775807 && min == 1)
        return (-1);
    if (res - 1 > 9223372036854775807 && min == -1)
        return (0);
    return (res * min);
}