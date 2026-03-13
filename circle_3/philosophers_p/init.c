#include "philo.h"

int	init_rules(t_rules *rules)
{
	rules->someone_died = 0;
	rules->start_time = ft_get_time_ms();
	if (pthread_mutex_init(&rules->print, NULL))
		return (1);
	if (pthread_mutex_init(&rules->dead_lock, NULL))
	{
		pthread_mutex_destroy(&rules->print);
		return (1);
	}
	return (0);
}

int	init_forks(t_rules *rules)
{
	int	i;

	rules->forks = malloc(sizeof(pthread_mutex_t) * rules->nb_philos);
	if (!rules->forks)
		return (1);
	i = 0;
	while (i < rules->nb_philos)
	{
		if (pthread_mutex_init(&rules->forks[i], NULL))
		{
			while (--i >= 0)
				pthread_mutex_destroy(&rules->forks[i]);
			free(rules->forks);
			return (1);
		}
		i++;
	}
	return (0);
}

int	init_philos(t_rules *rules, t_philo **philos)
{
	int	i;

	*philos = malloc(sizeof(t_philo) * rules->nb_philos);
	if (!*philos)
		return (1);
	i = -1;
	while (++i < rules->nb_philos)
	{
		(*philos)[i].id = i + 1;
		(*philos)[i].meals_eaten = 0;
		(*philos)[i].last_meal = rules->start_time;
		(*philos)[i].rules = rules;
		(*philos)[i].left_fork = &rules->forks[i];
		(*philos)[i].right_fork = &rules->forks[(i + 1) % rules->nb_philos];
		if (pthread_mutex_init(&(*philos)[i].philo_lock, NULL))
		{
			while (--i >= 0)
				pthread_mutex_destroy(&(*philos)[i].philo_lock);
			free(*philos);
			return (1);
		}
	}
	return (0);
}

int	init_all(t_rules *rules, t_philo **philos)
{
	if (init_rules(rules))
		return (1);
	if (init_forks(rules))
		return (1);
	if (init_philos(rules, philos))
		return (1);
	return (0);
}

void	clean_all(t_rules *rules, t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < rules->nb_philos)
	{
		pthread_mutex_destroy(&rules->forks[i]);
		pthread_mutex_destroy(&philos[i].philo_lock);
	}
	free(rules->forks);
	pthread_mutex_destroy(&rules->print);
	pthread_mutex_destroy(&rules->dead_lock);
	free(philos);
}

