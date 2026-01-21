#include "philo.h"

long ft_get_time_ms(void)
{
    struct timeval tv;

    if (gettimeofday(&tv, NULL) == -1)
        return (0);
    return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void ft_smart_sleep(long time, t_rules *rules)
{
    long start_time;

    start_time = ft_get_time_ms();      // tiempo al empezar
    while (!rules->someone_died)     // bucle mientras nadie haya muerto
    {
        if (ft_get_time_ms() - start_time >= time) // si pasó el tiempo deseado
            break;                            // salir del bucle
        usleep(100);            // dormir 100 microsegundos, evita que el bucle consuma 100% CPU
    }
}




/* ft_get_time_ms
Esta función convierte el tiempo actual en milisegundos, 
que luego podemos usar para medir duración de acciones, 
imprimir timestamps o comparar con time_to_die.
*/