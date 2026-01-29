#include "philo.h"

int	ft_check_death(t_philo *philo, t_rules *rules)
{
	long	time_since_last;

	pthread_mutex_lock(&philo->philo_lock);
	time_since_last = ft_get_time_ms() - philo->last_meal;
	pthread_mutex_unlock(&philo->philo_lock);
	if (time_since_last > rules->time_to_die)
	{
		pthread_mutex_lock(&rules->dead_lock);
		if (!rules->someone_died)
		{
			rules->someone_died = 1;
			pthread_mutex_lock(&rules->print);
			printf("%ld %d died\n",
				ft_get_time_ms() - rules->start_time, philo->id);
			pthread_mutex_unlock(&rules->print);
		}
		pthread_mutex_unlock(&rules->dead_lock);
		return (1);
	}
	return (0);
}

int	ft_check_all_full(t_philo *philos, t_rules *rules)
{
	int	i;
	int	all_full;

	i = 0;
	all_full = 1;
	if (rules->must_eat == -1)
		return (0);
	while (i < rules->nb_philos)
	{
		pthread_mutex_lock(&philos[i].philo_lock);
		if (philos[i].meals_eaten < rules->must_eat)
			all_full = 0;
		pthread_mutex_unlock(&philos[i].philo_lock);
		i++;
	}
	if (all_full)
	{
		pthread_mutex_lock(&rules->dead_lock);
		rules->someone_died = 1;
		pthread_mutex_unlock(&rules->dead_lock);
		return (1);
	}
	return (0);
}

void	*ft_monitor(void *arg)
{
	t_philo	*philos;
	t_rules	*rules;
	int		i;

	philos = (t_philo *)arg;
	rules = philos[0].rules;
	while (1)
	{
		i = 0;
		while (i < rules->nb_philos)
		{
			if (ft_check_death(&philos[i], rules))
				return (NULL);
			i++;
		}
		if (ft_check_all_full(philos, rules))
			return (NULL);
		usleep(100);
	}
	return (NULL);
}






/*Codigo original ok, pero se pasa de lineas 

void *ft_monitor(void *arg)
{
    t_philo *philos;
    t_rules *rules;
    int i;
    int all_full;
    long time_since_last_meal;

    philos = (t_philo *)arg;
    rules = philos[0].rules;
    while (1)
    {
        i = 0;
        all_full = 1;
        while (i < rules->nb_philos)
        {
            time_since_last_meal = ft_get_time_ms() - philos[i].last_meal;
            // Comprobar si murió
            pthread_mutex_lock(&rules->death);
            if (time_since_last_meal > rules->time_to_die && !rules->someone_died)
            {
                pthread_mutex_lock(&rules->print);
                printf("%ld %d died\n",
                       ft_get_time_ms() - rules->start_time,
                       philos[i].id);
                pthread_mutex_unlock(&rules->print);

                rules->someone_died = 1;
                pthread_mutex_unlock(&rules->death);
                return (NULL);
            }
            pthread_mutex_unlock(&rules->death);

            // Comprobar must_eat
            if (rules->must_eat > 0 && philos[i].meals_eaten < rules->must_eat)
                all_full = 0;

            i++;
        }

        if (rules->must_eat > 0 && all_full)
        {
            pthread_mutex_lock(&rules->death);
            rules->someone_died = 1; // Señal para terminar simulación
            pthread_mutex_unlock(&rules->death);
            return (NULL);
        }
        usleep(100); // evitar 100% CPU
    }
    return (NULL);
}
*/
