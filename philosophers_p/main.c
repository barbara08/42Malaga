#include "philo.h"

int	main(int argc, char **argv)
{
	t_rules	rules;
	t_philo	*philos;
	pthread_t	monitor_thread;

	if (ft_parse_args(argc, argv, &rules))
		return (1);
	if (init_all(&rules, &philos))
		return (1);
	rules.start_time = ft_get_time_ms();
	ft_create_threads(&rules, philos);
	pthread_create(&monitor_thread, NULL, ft_monitor, philos);
	ft_join_threads(&rules, philos);
	pthread_join(monitor_thread, NULL);
	clean_all(&rules, philos);
	return (0);
}
