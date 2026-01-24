#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <string.h>
# include "structs.h"

// parse.c
size_t	ft_strlen(const char *str);
int		ft_print_error(const char *msg);
int		ft_is_number(char *str);
int		ft_atoi_positive(char *str);
int		ft_parse_args(int argc, char **argv, t_rules *rules);

// init.c
int		init_rules(t_rules *rules);
int		init_forks(t_rules *rules);
int		init_philos(t_rules *rules, t_philo **philos);
int		init_all(t_rules *rules, t_philo **philos);
void	clean_all(t_rules *rules, t_philo *philos);

// time.c
long	ft_get_time_ms(void);
void	ft_smart_sleep(long time, t_rules *rules);

// routines.c
void	ft_print_action(t_philo *philo, char *msg);
void	ft_philo_eat(t_philo *philo);
void	ft_philo_actions(t_philo *philo);
void	*ft_philo_routine(void *arg);
void	ft_start_routines(t_rules *rules, t_philo *philos);
void	ft_join_routines(t_rules *rules, t_philo *philos);

// monitor.c
int		ft_check_death(t_philo *philo, t_rules *rules);
int		ft_check_all_full(t_philo *philos, t_rules *rules);
void	*ft_monitor(void *arg);
void	ft_start_monitor(t_philo *philos);

#endif
