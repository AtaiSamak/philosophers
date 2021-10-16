#include "stdio.h"
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

int checkAndFill(int argc, char **argv, t_philo *philo)
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
    philo->philos = ft_atoi(argv[1]);
    philo->die = ft_atoi(argv[2]);
    philo->eat = ft_atoi(argv[3]);
    philo->sleep = ft_atoi(argv[4]);
    philo->stopTime = 0;
    if (argc == 6)
        philo->stopTime = ft_atoi(argv[5]);
}

int main(int argc, char **argv)
{
    t_philo philo;
    if (argc == 5 || argc == 6)
    {
        if (checkAndFill(argc, argv, &philo) == -1)
        {
            printf("ERROR!\n");
            return (-1);
        }
    }
    printf("philo - %d\ndie - %d\neat - %d\nsleep - %d\n", philo.philos, philo.die, philo.eat, philo.sleep);
    printf("stopTime - %d\n", philo.stopTime);
}