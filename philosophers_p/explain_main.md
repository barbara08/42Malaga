
/*
El main no hace lógica de filósofos, solo:
- parsea
- inicializa struct y mutex
- inicia el tiempo de inicio
- lanza threads (create philo y monitor)
- espera (join philo y monitor)
- limpia (destroy y free)

----- FLUJO -----
parse args
   ↓
init structs + mutex
   ↓
set start_time
   ↓
create philosopher threads
   ↓
create monitor thread
   ↓
wait philosophers
   ↓
wait monitor
   ↓
destroy mutex + free
*/

----- Las variables -----
t_rules rules;
- Estructura global de reglas
- Vive en el stack del main
- Todos los threads accederán a ella por puntero

t_philo *philos;
- Array dinámico de filósofos
- Se reserva en init_all

pthread_t monitor_thread;
- Thread independiente
- Se encargará del monitor

----- El parseo -----
if (ft_parse_args(argc, argv, &rules))
    return (1);
Valida:
	- número de argumentos
	- que sean números
	- que no sean negativos
Rellena rules con valores iniciales
Si algo falla → salir

----- La inicialización general -----
if (init_all(&rules, &philos))
    return (1);
Aquí normalmente pasa todo esto:
- malloc de philos
- inicialización de mutex:
	forks
	print
	dead_lock
- inicialización de cada t_philo:
	id
	left_fork, right_fork
	philo_lock
	rules
Si falla algo → sales limpio.

----- El tiempo de inicio -----
rules.start_time = ft_get_time_ms();
- Marca el tiempo cero de la simulación
- Todos los prints usan:
	ft_get_time_ms() - rules.start_time
Hacerlo justo antes de crear los threads.

----- Crear threads de los philos -----
ft_create_threads(&rules, philos);
Lanza:
	1 thread por filósofo
Cada uno ejecuta:
	ft_philo_routine → ft_philo_actions
Desde aquí, los filósofos ya están vivos.

----- Crear thread del monitor -----
pthread_create(&monitor_thread, NULL, ft_monitor, philos);
- Se lanza después de los filósofos
- El monitor:
	observa
	no bloquea forks
	solo lee estados
Primero philos y después el monitor para evitar que el monitor vea estados no inicializados.

----- Esperar a que terminen los philos -----
ft_join_threads(&rules, philos);
- pthread_join para cada filósofo
- El main se bloquea aquí
- Los filósofos salen cuando:
		someone_died == 1

----- Esperar a que termine el monitor -----
pthread_join(monitor_thread, NULL);
Asegura:
- que el monitor terminó
- que no queda ningún thread vivo
El orden es correcto:
- filósofos
- monitor

----- Limpiar recursos -----
clean_all(&rules, philos);
Aquí:
- pthread_mutex_destroy de:
	forks
	print
	dead_lock
	philo_lock
- free(philos)

/*
El main se encarga únicamente de la gestión del ciclo de vida del programa:
parsea argumentos, inicializa estructuras, lanza los threads de filósofos y del monitor,
espera a que todos terminen y finalmente libera los recursos.
Toda la lógica de sincronización está delegada a los threads.
*/