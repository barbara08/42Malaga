/* ft_print_action
Imprimir una acción del filósofo de forma segura y solo si nadie ha muerto.
1. Primer mutex: dead_lock
pthread_mutex_lock(&philo->rules->dead_lock);
Protege la variable global rules->someone_died
Es obligatorio porque:
	Varios threads pueden:
		leer
		o escribir
		someone_died
	Sin este mutex:
		race condition
		prints después de la muerte

2. Comprobar
if (!philo->rules->someone_died)
Si nadie ha muerto aún → se puede imprimir
Si alguien ya murió → NO imprimir nada

3. Segundo mutex: print
pthread_mutex_lock(&philo->rules->print);
Protege printf
Es obligatorio porque:
Sin este mutex veríamos algo así:
123 1 is ea
124 2 has taken a fork
ting

4. printf
Timestamp relativo
ID del philo
Mensaje

5. Unlock del mutex print
pthread_mutex_unlock(&philo->rules->print);
Libera el acceso a stdout
Otro thread ya puede imprimir

6. Unlock del mutex dead_lock
pthread_mutex_unlock(&philo->rules->dead_lock);
Libera la protección de someone_died
Otros threads pueden comprobar / modificar el estado
*/

/* philo_eat
Esta función es donde nacen o mueren los deadlocks
Gestionar TODA la acción de comer:
	coger los dos tenedores
	actualizar estado interno
	simular el tiempo de comida
	soltar los tenedores
1. Elección del primer tenedor (clave anti-deadlock)
* Primer if
	Qué hace:
	philo pares → cogen primero el derecho
	philo impares → cogen primero el izquierdo
* Primer print (ft_print_action) "has taken a fork"
Se imprime cada vez que se coge un tenedor
2. Elección del segundo tenedor (complementario)
* Segundo if
	Ahora coge el otro tenedor
	En este punto ya tiene los dos
* Segundo print (ft_print_action) "has taken a fork"
Se imprime cada vez que se coge un tenedor
3. Protección de estado interno (philo_lock)
pthread_mutex_lock(&philo->philo_lock);
philo->last_meal = ft_get_time_ms();
pthread_mutex_unlock(&philo->philo_lock);

Protege last_meal porque:
	El monitor de muerte lee last_meal
	Si no hay mutex → race condition
philo_lock es por filósofo, no global

4. ft_print_action(philo, "is eating");
Indica que:
ya tiene los dos forks
acaba de actualizar last_meal

5. Simulación del tiempo de comida
ft_smart_sleep(philo->rules->time_to_eat, philo->rules);
Simula comer
Se despierta periódicamente
Comprueba si alguien murió

6. Incrementar comidas (con mutex)
pthread_mutex_lock(&philo->philo_lock);
philo->meals_eaten++;
pthread_mutex_unlock(&philo->philo_lock);

Protege meals_eaten porque:
El monitor puede comprobar:
	if (meals_eaten >= must_eat)
Sin mutex → valores corruptos

7. Soltar los forks
pthread_mutex_unlock(philo->left_fork);
pthread_mutex_unlock(philo->right_fork);

Liberamos ambos forks
El orden aquí no importa
Ya no hay riesgo de deadlock
Siempre soltar los forks
Incluso si alguien murió

*/

/* ft_philo_actions

