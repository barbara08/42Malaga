#include "philo.h"

int	main(int argc, char **argv)
{
	t_rules	rules;
	t_philo	*philos;

	if (ft_parse_args(argc, argv, &rules))
		return (1);
	if (init_all(&rules, &philos))
		return (1);
	rules.start_time = ft_get_time_ms();
	ft_start_routines(&rules, philos);
	ft_start_monitor(philos);
	ft_join_routines(&rules, philos);
	clean_all(&rules, philos);
	return (0);
}
