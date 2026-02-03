#include "philo.h"


//Función que ejecuta cada hilo (filósofo)
//Esta función no es un thread, es la rutina que ejecuta el thread
//El thread lo crea pthread_create,
//esta función es la routine que ejecuta el thread.
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
		Si el ID es par (philo par), duerme 1.5 ms al inicio.
		Para evitar que todos coman al mismo tiempo, es decir, 
		que todos los filósofos con ID par intenten coger primero 
		el tenedor izquierdo al mismo tiempo → prevenir los deadlocks.
	*/
	if (philo->id % 2 == 0)
		usleep(1500);
	/* Rutina normal
		Llama a la función (ft_philo_actions) que es la que implementa
		el ciclo de vida del filósofo: pensar → coger tenedores → comer → dormir.
		return NULL → finaliza el hilo.
	*/
	ft_philo_actions(philo);
	return (NULL);
}

// Funcion para crear los threads de los filósofos
void	ft_create_threads(t_rules *rules, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < rules->nb_philos)
	{
		/* Crea un thread para cada filósofo (estructura t_philo => pthread_t thread;)
			Guarda su ID en philos[i].thread
			Ejecuta ft_philo_routine
			Le pasa SU propio filósofo
			Each thread → 1 filósofo → 1 rutina 
		*/
		pthread_create(&philos[i].thread, NULL, ft_philo_routine, &philos[i]);
		i++;
	}
}

// Esperar a que todos los filósofos terminen
// Llama a pthread_join para cada hilo de filósofo
/* Garantiza:
	NO destruir mutex
	NO liberar memoria
	hasta que TODOS los threads estén join
*/
void	ft_join_threads(t_rules *rules, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < rules->nb_philos)
	{
		/*
			Bloquea el thread principal
			Espera a que ese philo termine
			Garantiza:
				no destruir mutex antes de tiempo
				no salir del programa antes
		*/
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

