#include "philo.h"

int main(int argc, char **argv)
{
    t_main args;
    if (argc == 5 || argc == 6)
    {
        if (checkAndInitSettings(argc, argv, &args) == -1)
            return (-1);
    }
    else
    {
        printf("Error. Please write correct!\n");
            return (-1);
    }
    if(initPhilosForks(&args) == -1)
        return (-1);
    if(runThreads(&args) == -1)
        return (-1);

    int i = -1;
    while(++i < args.setting.philos)
    {
        printf("philoId = %d, lastEat = %llu, died = %d\n", \
        args.philo[i].id, args.philo[i].lastEat, args.philo[i].died);
    }
    // printf("philo - %d\ndie - %d\neat - %d\nsleep - %d\n", \
    // args.setting.philos, args.setting.die, args.setting.eat, args.setting.sleep);
}