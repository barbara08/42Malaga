
/* pthread_mutex_init(&rules->print, NULL)
El NULL NO es el valor del mutex.
Ese NULL es el segundo parámetro de la función:
const pthread_mutexattr_t *attr
---- RESUMEN ----
NULL = usar los valores por defecto
- NO es una inicialización
- NO pone nada a NULL
La única inicialización real es esta parte:
pthread_mutex_init(&rules->print, NULL);
Y lo que hace es:
	- crear el mutex
	- dejarlo listo
	- con configuración estándar
El NULL solo dice:
NULL = “no quiero atributos especiales, usa los valores por defecto”

En esta línea => pthread_mutex_init(&rules->print, NULL);
se inicializa el mutex print, quedando listo para su uso con los valores por defecto.
es decir, pthread_mutex_init inicializa el mutex y lo deja en estado desbloqueado.
*/


/* init_rules
1. Inicializar el estado de muerte
rules->someone_died = 0;
someone_died es un flag compartido
Significa:
0 → nadie ha muerto todavía
1 → algún filósofo ha muerto → se acaba la simulación
Importante:
Este valor será leído por varios threads, por eso luego se protege con un mutex (dead_lock).

2. Guardar el tiempo de inicio
rules->start_time = ft_get_time_ms();
Guarda el momento exacto en el que empieza la simulación
ft_get_time_ms() suele:
Usar gettimeofday() o clock_gettime()
Devolver el tiempo actual en milisegundos
¿Para qué sirve?
Para imprimir tiempos relativos:
123 3 is eating
(123 ms desde que empezó la simulación)

3. Inicializar el mutex de impresión
if (pthread_mutex_init(&rules->print, NULL))
    return (1);
Crea un mutex llamado print
¿Para qué?
Evitar que varios filósofos escriban en pantalla al mismo tiempo
Sin esto hay líneas mezcladas y caos
pthread_mutex_init devuelve:
0 → OK
Cualquier otro valor → error
Si falla → la función devuelve 1

4. Inicializar el mutex de muerte
if (pthread_mutex_init(&rules->dead_lock, NULL))
    return (1);
Este mutex protege la variable:
rules->someone_died
Sirve para:
Leer si alguien ha muerto
Marcar que alguien ha muerto
Evita race conditions entre threads

5. 
return (0);
Si llega aquí:
Todos los valores están inicializados
Los mutex están listos
La simulación puede arrancar

RESUMEN:
Esta función:
- Inicializa el estado global
- Guarda el tiempo inicial de la simulación
- Crea mutex para:
	. Imprimir de forma ordenada
	. Controlar la muerte de filósofos
		Devuelve 0 si todo va bien, 1 si algo falla
*/

/* init_forks
Esta función reserva memoria para los tenedores 
y crea un mutex por cada filósofo,
inicializándolos para garantizar el acceso exclusivo

1. Reservar memoria para los tenedores
rules->forks = malloc(sizeof(pthread_mutex_t) * rules->nb_philos);
Reserva un array de mutexes
Cada mutex representa un tenedor
¿Para qué?
Cada filósofo necesita dos tenedores para comer	

2. Bucle para inicializar cada tenedor
Recorres todos los tenedores
Para cada posición:
Inicializas un mutex independiente
significa:
“este tenedor ya puede ser cogido por un solo filósofo a la vez”

3. Manejo de errores durante la inicialización
La función clean_all está bien
PERO no sirve para errores durante la inicialización
while (--i >= 0)
				pthread_mutex_destroy(&rules->forks[i]);

4. return (0);
Todos los mutex están:
- creados
- inicializados
- desbloqueados
- listos para usar
Devuelve 0 si todo va bien, 1 si algo falla
OJO
¿Por qué no llamas a clean_all aquí?
Porque clean_all asume que todos los recursos están inicializados.
En caso de error parcial durante init_forks, 
solo se deben liberar los mutex que ya fueron creados.

*/

/* init_philo

Crea e inicializa a todos los filósofos
- Reserva memoria para el array de t_philo
- Inicializa los campos de cada filósofo
- Asigna sus tenedores (forks) en círculo
- Inicializa el mutex privado de cada filósofo

1. Reservar memoria para los filósofos (uno por cada philo)
*philos = malloc(sizeof(t_philo) * rules->nb_philos);

2. Inicializar el índice
i = -1;
while (++i < rules->nb_philos)
Truco típico para ahorrar una línea
Primer i real será 0

3. Asignar el ID
(*philos)[i].id = i + 1;
IDs empiezan en 1, no en 0
Coincide con el output del subject:
1 is eating

4. Inicializar comidas
(*philos)[i].meals_eaten = 0;
Ningún filósofo ha comido aún
Se irá incrementando

5. Inicializar último tiempo de comida
(*philos)[i].last_meal = rules->start_time;
Al empezar la simulación:
todos “acaban de comer”
Evita muertes instantáneas
Se usará para calcular (current_time - last_meal > time_to_die)

6. Guardar puntero a rules
(*philos)[i].rules = rules;
Cada filósofo necesita acceso a:
- tiempos
- flags
- mutex globales
En vez de pasar todo por parámetros → guardamos el puntero

7. Asignar tenedor izquierdo
(*philos)[i].left_fork = &rules->forks[i];
- El fork izquierdo del filósofo i:
	es el fork i
- Es un puntero a un mutex

8. Asignar tenedor derecho
(*philos)[i].right_fork = &rules->forks[(i + 1) % rules->nb_philos];
(i + 1) → el fork de la derecha
% rules->nb_philos:
	- el último filósofo vuelve al primero
	- mesa circular

Ejemplo con 5 filósofos:
philo	Left fork	Right fork
1		0			1
2		1			2
3		2			3
4		3			4
5		4			0
Círculo perfecto.

** OJO: De la estructura 
La variable =>  pthread_t	thread;
NO se inicializa con pthread_mutex_init ni nada parecido.
pthread_t se “inicializa” cuando llamamos a pthread_create.
En la función ft_start_routines

9. Inicializar el mutex privado del filósofo
if (pthread_mutex_init(&(*philos)[i].philo_lock, NULL))
- Cada filósofo tiene su propio mutex
- Protege datos como:
	last_meal
	meals_eaten
- Evita race conditions entre:
	el hilo del filósofo
	el hilo monitor
9.1 Manejo de errores durante la inicialización
while (--i >= 0)
				pthread_mutex_destroy(&rules->forks[i]);
			free(rules->forks);
			return (1);
Limpia correctamente en caso de que falle 
la inicialización de un mutex a mitad

*/
/* init_all
Inicializa todas las estructuras necesarias para la simulación:
Devuelve 0 → todo inicializado correctamente
Devuelve 1 → hubo un error en alguna inicialización
Recibe:
rules → la estructura global de la simulación
philos → puntero al array de filósofos (se inicializa dentro de init_philos)

simulación correcta para empezar:
return (0);
rules inicializado
forks inicializados
filósofos inicializados

Esta función es como un constructor global de la simulación.
Garantiza que cada paso depende del anterior (muy importante el orden):
Evita inicializar filósofos si rules o forks fallan
Devuelve 1 inmediatamente si hay error → patrón típico de early return

RESUMEN
(rules) → debe estar lista
(forks) → debe estar lista
(philos) → solo se ponen si los pasos anteriores fueron bien
Si algo falla en un paso → aborta y limpia lo hecho

*/

/* clean_all
Esta función libera todos los recursos usados durante la simulación:

Esto está bien SI:
Todos los mutex fueron inicializados
Todos los filósofos existen
La simulación terminó correctamente

Es decir:
cleanup final, no cleanup de error 
por eso en init_forks y en init_philo tienen el cleanup de error

*/