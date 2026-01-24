#include "philo.h"

void ft_print_action(t_philo *philo, char *msg)
{
    pthread_mutex_lock(&philo->rules->dead_lock);
    if (!philo->rules->someone_died)
    {
        pthread_mutex_lock(&philo->rules->print);
        printf("%ld %d %s\n", ft_get_time_ms() - philo->rules->start_time,
               philo->id, msg);
        pthread_mutex_unlock(&philo->rules->print);
    }
    pthread_mutex_unlock(&philo->rules->dead_lock);
}

void	ft_philo_eat(t_philo *philo)
{
	if (philo->id % 2 == 0)
		pthread_mutex_lock(philo->right_fork);
	else
		pthread_mutex_lock(philo->left_fork);
	ft_print_action(philo, "has taken a fork");
	if (philo->id % 2 == 0)
		pthread_mutex_lock(philo->left_fork);
	else
		pthread_mutex_lock(philo->right_fork);
	ft_print_action(philo, "has taken a fork");
	pthread_mutex_lock(&philo->philo_lock);
	philo->last_meal = ft_get_time_ms();
	pthread_mutex_unlock(&philo->philo_lock);
	ft_print_action(philo, "is eating");
	ft_smart_sleep(philo->rules->time_to_eat, philo->rules);
	pthread_mutex_lock(&philo->philo_lock);
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->philo_lock);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	ft_philo_actions(t_philo *philo)
{
	while (1)
	{
		pthread_mutex_lock(&philo->rules->dead_lock);
		if (philo->rules->someone_died)
		{
			pthread_mutex_unlock(&philo->rules->dead_lock);
			break ;
		}
		pthread_mutex_unlock(&philo->rules->dead_lock);
		ft_philo_eat(philo);
		ft_print_action(philo, "is sleeping");
		ft_smart_sleep(philo->rules->time_to_sleep, philo->rules);
		ft_print_action(philo, "is thinking");
	}
}

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

void ft_start_routines(t_rules *rules, t_philo *philos)
{
    int i;

    i = 0;
    while (i < rules->nb_philos)
    {
        pthread_create(&philos[i].thread, NULL, ft_philo_routine, &philos[i]);
        i++;
    }
}
void ft_join_routines(t_rules *rules, t_philo *philos)
{
    int i;

    i = 0;
    while (i < rules->nb_philos)
    {
        pthread_join(philos[i].thread, NULL);
        i++;
    }
}



/* original, pero faltan cosas

void ft_print_action(t_philo *philo, char *msg)
{
    pthread_mutex_lock(&philo->rules->print);
    if (!philo->rules->someone_died)
        printf("%ld %d %s\n", ft_get_time_ms() - philo->rules->start_time,
               philo->id, msg);
    pthread_mutex_unlock(&philo->rules->print);
}

void *ft_philo_routine(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    while (!philo->rules->someone_died)
    {
        // 1. thinking
        ft_print_action(philo, "is thinking");

        // 2. take forks
        pthread_mutex_lock(philo->left_fork);
        ft_print_action(philo, "has taken a fork");
        pthread_mutex_lock(philo->right_fork);
        ft_print_action(philo, "has taken a fork");

        // 3. eating
        philo->last_meal = ft_get_time_ms();
        ft_print_action(philo, "is eating");
        ft_smart_sleep(philo->rules->time_to_eat, philo->rules);
        philo->meals_eaten++;

        // 4. unlock forks
        pthread_mutex_unlock(philo->left_fork);
        pthread_mutex_unlock(philo->right_fork);

        // 5. sleeping
        ft_print_action(philo, "is sleeping");
        ft_smart_sleep(philo->rules->time_to_sleep, philo->rules);
    }

    return (NULL);
}*/