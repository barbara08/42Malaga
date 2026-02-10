#include "philo.h"

int	ft_simulation_finished(t_rules *rules)
{
	int	finished;

	pthread_mutex_lock(&rules->dead_lock);
	finished = rules->someone_died;
	pthread_mutex_unlock(&rules->dead_lock);
	return (finished);
}

void ft_print_action(t_philo *philo, char *msg)
{
	if (ft_simulation_finished(philo->rules))
		return;
	pthread_mutex_lock(&philo->rules->print);
	if (!ft_simulation_finished(philo->rules))
		printf("%ld %d %s\n",
			ft_get_time_ms() - philo->rules->start_time,
			philo->id, msg);
	pthread_mutex_unlock(&philo->rules->print);
}
void	ft_philo_eat(t_philo *philo)
{
	if (ft_simulation_finished(philo->rules))
		return;

	// Tomar forks según ID
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		ft_print_action(philo, "has taken a fork left");
		//usleep(5000); // 5ms de desfase
		pthread_mutex_lock(philo->right_fork);
		ft_print_action(philo, "has taken a fork right");
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		ft_print_action(philo, "has taken a fork right");
		//usleep(5000);
		pthread_mutex_lock(philo->left_fork);
		ft_print_action(philo, "has taken a fork left");
	}

	// Comer: actualizar last_meal justo antes de empezar a comer
	pthread_mutex_lock(&philo->philo_lock);
	philo->last_meal = ft_get_time_ms();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->philo_lock);

	ft_print_action(philo, "is eating");
	ft_smart_sleep(philo->rules->time_to_eat, philo->rules);

	// Soltar forks
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}
void ft_philo_actions(t_philo *philo)
{
	while (!ft_simulation_finished(philo->rules))
	{
		ft_philo_eat(philo);
		if (ft_simulation_finished(philo->rules))
			break;

		ft_print_action(philo, "is sleeping");
		ft_smart_sleep(philo->rules->time_to_sleep, philo->rules);
		if (ft_simulation_finished(philo->rules))
			break;

		ft_print_action(philo, "is thinking");
		usleep(50000); // pequeño descanso para dar tiempo a otros hilos
	}
}




/* ORIGINAL, ok, cambiado por la funcion nueva ft_simulation_finished
void	ft_print_action(t_philo *philo, char *msg)
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
	
	//chequeo al inicio para no empezar a comer si ya terminó todo
	//Esto evita que el filósofo entre en el ciclo de comer si el monitor ya puso someone_died en 1.
	pthread_mutex_lock(&philo->rules->dead_lock);
	if (philo->rules->someone_died)
	{
		pthread_mutex_unlock(&philo->rules->dead_lock);
		return ;
	}
	pthread_mutex_unlock(&philo->rules->dead_lock);
	//Coger Forks
	if (philo->id % 2 == 0)
		pthread_mutex_lock(philo->right_fork);
	else
		pthread_mutex_lock(philo->left_fork);
	
	ft_print_action(philo, "has taken a fork right");
	
	if (philo->id % 2 == 0)
		pthread_mutex_lock(philo->left_fork);
	else
		pthread_mutex_lock(philo->right_fork);
	
	ft_print_action(philo, "has taken a fork left");
	
	//Comer
	pthread_mutex_lock(&philo->philo_lock);
	philo->last_meal = ft_get_time_ms();
	pthread_mutex_unlock(&philo->philo_lock);
	
	ft_print_action(philo, "is eating");
	ft_smart_sleep(philo->rules->time_to_eat, philo->rules);
	
	//Incrementar(parametro opcional)
	pthread_mutex_lock(&philo->philo_lock);
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->philo_lock);
	
	//Soltar Forks
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
	
void	ft_philo_actions(t_philo *philo)
{
	while (1)
	{
		if (ft_simulation_finished(philo->rules))
			return;
		ft_philo_eat(philo);
		if (ft_simulation_finished(philo->rules))
			return;
		ft_print_action(philo, "is sleeping");
		ft_smart_sleep(philo->rules->time_to_sleep, philo->rules);
		if (ft_simulation_finished(philo->rules))
			return;
		ft_print_action(philo, "is thinking");
	}
}

*/