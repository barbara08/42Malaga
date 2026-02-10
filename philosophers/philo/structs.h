#ifndef STRUCTS_H
# define STRUCTS_H

# include <pthread.h>

typedef struct s_rules
{
	int				nb_philos;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				must_eat;
	long			start_time;
	int				someone_died;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	dead_lock;
}	t_rules;

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	long			last_meal;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	philo_lock;
	t_rules			*rules;
}	t_philo;

#endif