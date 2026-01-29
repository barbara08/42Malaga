#include "philo.h"


//Función que ejecuta cada hilo (filósofo)
//Recibe arg → un puntero genérico void* que será un t_philo*
//Cast de void* a t_philo* para usar la estructura t_philo
void	*ft_philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	/* 
		Si solo hay 1 filósofo, no puede coger dos tenedores → morirá.
		Simulamos que:
		Toma el único tenedor
		Espera hasta morir (time_to_die) usando ft_smart_sleep
		Retorna NULL → hilo termina.
	*/
	if (philo->rules->nb_philos == 1)
	{
		ft_print_action(philo, "has taken a fork");
		ft_smart_sleep(philo->rules->time_to_die, philo->rules);
		return (NULL);
	}
	/*
		Evitar que todos coman al mismo tiempo
		Si el ID es par, duerme 1.5 ms al inicio.
		Esto desfase los hilos para que no todos intenten coger los tenedores a la vez → previene deadlocks.
	*/
	if (philo->id % 2 == 0)
		usleep(1500);
	/* Rutina normal
		Llama a la función que implementa el ciclo de vida del filósofo: pensar → coger tenedores → comer → dormir.
		return NULL → finaliza el hilo.
	*/
	ft_philo_actions(philo);
	return (NULL);
}

void	ft_start_routines(t_rules *rules, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < rules->nb_philos)
	{
		pthread_create(&philos[i].thread, NULL, ft_philo_routine, &philos[i]);
		i++;
	}
}

void	ft_join_routines(t_rules *rules, t_philo *philos)
{
	int	i;

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