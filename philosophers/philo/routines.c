#include "philo.h"

void	*ft_philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->rules->nb_philos == 1)
	{
		ft_print_action(philo, "has taken a fork");
		ft_smart_sleep(philo->rules->time_to_die, philo->rules);
		return (NULL);
	}
	if (philo->id % 2 == 0)
		usleep(1500);
	ft_philo_actions(philo);
	return (NULL);
}

void	ft_create_threads(t_rules *rules, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < rules->nb_philos)
	{
		pthread_create(&philos[i].thread, NULL, ft_philo_routine, &philos[i]);
		i++;
	}
}

void	ft_join_threads(t_rules *rules, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < rules->nb_philos)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
}
