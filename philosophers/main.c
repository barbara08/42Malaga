#include "philo.h"

/* para ejecutar valdgrind en mac
en Makefile he añadido la regla asan (quitar)
tambien en PHONY (quitar)

Terminal:
//1. Compilar con asan
$ make asan
$ ./philo 5 800 200 200 7
//2. make
leaks --atExit -- ./philo 5 800 200 200 7

*/

int main(int ac, char **av)
{
    t_rules rules;
    t_philo *philos;

    if (ft_parse_args(ac, av, &rules))
        return (1);
    if (init_all(&rules, &philos))
        return (1);
    rules.start_time = ft_get_time_ms();
    /* debug 
    printf("Start: %ld\n", ft_get_time_ms() - rules.start_time);
    ft_smart_sleep(500, &rules);
    printf("After sleep: %ld\n", ft_get_time_ms() - rules.start_time);
    */

    ft_start_routines(&rules, philos);  // crea los threads de philos
    ft_start_monitor(philos); // crea el monitor
    ft_join_routines(&rules, philos);   // espera a que terminen los philos

    clean_all(&rules, philos);  // Liberar memoria y mutex
    return (0);
}
