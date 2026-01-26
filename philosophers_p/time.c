#include "philo.h"

long ft_get_time_ms(void)
{
	struct	timeval tv;

	if (gettimeofday(&tv, NULL) == -1)
		return (0);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void ft_smart_sleep(long time, t_rules *rules)
{
	long	start_time;

	start_time = ft_get_time_ms();
	while (1)
	{
		pthread_mutex_lock(&rules->dead_lock);
		if (rules->someone_died || (ft_get_time_ms() - start_time >= time))
		{
			pthread_mutex_unlock(&rules->dead_lock);
			break;
		}
		pthread_mutex_unlock(&rules->dead_lock);
		usleep(200);
	}
}


/* ft_get_time_ms
Esta función convierte el tiempo actual en milisegundos, 
que luego podemos usar para medir duración de acciones, 
imprimir timestamps o comparar con time_to_die.
*/