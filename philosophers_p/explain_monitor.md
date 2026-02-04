El monitor decide cuándo se acaba la simulación y por qué.
El monitor es un thread independiente que comprueba continuamente
si algún filósofo ha superado time_to_die o si todos han comido must_eat. Cuando ocurre cualquiera de esas condiciones, activa someone_died, lo que provoca que todos los threads terminen de forma segura.

*/ 	ft_check_death
Detecta si un filósofo ha muerto
return:
1 → alguien murió (fin de simulación)
0 → sigue vivo
1. Proteger last_meal
pthread_mutex_lock(&philo->philo_lock);
Protege: philo->last_meal
- El filósofo escribe
- El monitor lee
time_since_last_meal = ft_get_time_ms() - philo->last_meal;
- Calcula cuánto tiempo lleva sin comer
pthread_mutex_unlock(&philo->philo_lock);
- Libera el mutex
- No lo mantiene bloqueado innecesariamente
2. Comprobación de muerte
if (time_since_last_meal > rules->time_to_die)
- Si supera time_to_die
- El filósofo muere
3. Proteger someone_died
pthread_mutex_lock(&rules->dead_lock);
Protege la variable global: rules->someone_died
if (!rules->someone_died)
Evita:
- imprimir dos muertes
- que dos threads “declaren” muerte a la vez
4. Imprimir la muerte (una sola vez)
rules->someone_died = 1; => Marca el fin de la simulación

pthread_mutex_lock(&rules->print);
printf("%ld %d died\n",
    ft_get_time_ms() - rules->start_time, philo->id);
pthread_mutex_unlock(&rules->print);
- Print protegido
- Timestamp correcto
- Formato exacto del subject

pthread_mutex_unlock(&rules->dead_lock);
- Libera dead_lock

return (1);
- Señala al monitor:
    “Se acabó, alguien murió”

5. Si no murió
return (0);
*/

/* ft_check_all_full
Comprueba si todos han comido lo suficiente (must_eat)
(Parámetro opcional)
1. Caso sin must_eat
if (rules->must_eat == -1)
    return (0);
No hay límite de comidas
Nunca se cumple “todos llenos”
2. Recorrer filósofos (while)
all_full = 1;
- Asumimos que todos están llenos
- Intentaremos demostrar lo contrario
pthread_mutex_lock(&philos[i].philo_lock);
if (philos[i].meals_eaten < rules->must_eat)
    all_full = 0;
pthread_mutex_unlock(&philos[i].philo_lock);
- Protege meals_eaten
- Si uno solo no ha comido lo suficiente:
all_full = 0;

3. Si todos han comido
if (all_full)
pthread_mutex_lock(&rules->dead_lock);
rules->someone_died = 1;
pthread_mutex_unlock(&rules->dead_lock);
- Se reutiliza someone_died como:   flag de parada global
- No hay muerte real
- Pero la simulación termina
return (1);
4. Si no
return (0);

*/

/* *ft_monitor

1. Inicialización
philos = (t_philo *)arg;
rules = philos[0].rules;
- Recibe el array de filósofos
- Accede a rules desde cualquiera
2. Bucle infinito
while (1)
El monitor vigila constantemente
3. Revisar muertes
i = 0;
while (i < rules->nb_philos)
{
    if (ft_check_death(&philos[i], rules))
        return (NULL);
    i++;
}
- Revisa uno por uno
- En cuanto detecta una muerte:
        - imprime
        - sale
        - el thread termina
4. Revisar must_eat
if (ft_check_all_full(philos, rules))
    return (NULL);
Si todos comieron:
- termina la simulación
- sin imprimir muerte
5. Pequeña pausa
usleep(100);
- Evita:  consumo del 100% de CPU
- 100 µs → muy frecuente, muy preciso

*/
----------------------------------------------
Qué hacen en conjunto las 3 funciones:
* Objetivo del monitor: decidir CUÁNDO termina la simulación.
La simulación acaba si:
- Un filósofo muere
- Todos han comido must_eat

* Relación con los filósofos
- Filósofos:
    - ejecutan acciones
    - modifican su estado
- Monitor:
    - lee ese estado
    - decide el final
    - activa someone_died

* Separación perfecta de responsabilidades.

* Mapa de mutex
Dato	        Mutex

last_meal	    philo_lock
meals_eaten	    philo_lock
someone_died	dead_lock
printf	        print
forks	        mutex fork

