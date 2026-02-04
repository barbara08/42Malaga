
/* ft_get_time_ms

Esta función convierte el tiempo actual en milisegundos, 
que luego podemos usar para medir duración de acciones, 
imprimir timestamps o comparar con time_to_die.

timeval es una estructura de C definida así:
struct timeval {
    time_t      tv_sec;  // segundos desde Epoch
    suseconds_t tv_usec; // microsegundos adicionales
};
tv_sec → segundos completos
tv_usec → microsegundos (1 segundo = 1.000.000 microsegundos)

gettimeofday() rellena tv con el tiempo actual del sistema.
Segundo parámetro (NULL) es para la zona horaria, pero ya no se usa.
Retorna -1 si hay error, por eso return 0 en ese caso.

Esta linea de codigo: 
return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));

tv.tv_sec * 1000 → convierte segundos a milisegundos
tv.tv_usec / 1000 → convierte microsegundos a milisegundos
Sumando ambos, obtienes tiempo total en ms.

Ej: Si tv.tv_sec = 5 y tv.tv_usec = 500000:
tv.tv_sec * 1000 = 5 * 1000 = 5000 ms
tv.tv_usec / 1000 = 500000 / 1000 = 500 ms
Total = 5500 ms

*/

/* ft_smart_sleep

time → cantidad de milisegundos que queremos “dormir”
start_time sirve para medir cuánto tiempo hemos dormido
“marca el momento en que empieza el sleep”

while(1)
Vamos a dormir de manera controlada, no usando usleep(time * 1000) directo.
Por qué no usar usleep largo: 
si un filósofo muere mientras dormía, necesitamos despertarlo inmediatamente.

Bloqueo mutex:
pthread_mutex_lock(&rules->dead_lock);

Antes de comprobar si alguien murió, bloqueamos el mutex
Esto evita condiciones de carrera al leer rules->someone_died
Muy importante porque múltiples hilos leen/escriben esta variable.

Condicion de salida:
Dos posibles razones para salir del sleep:
if (rules->someone_died || (ft_get_time_ms() - start_time >= time))

rules->someone_died → un filósofo murió, no queremos seguir durmiendo.
(ft_get_time_ms() - start_time >= time) → hemos dormido el tiempo requerido

pthread_mutex_unlock(&rules->dead_lock);
break;

Siempre desbloqueamos antes de salir
break termina el bucle → el “sleep inteligente” terminó

Si no se cumple la condición de salida (if):
pthread_mutex_unlock(&rules->dead_lock);
usleep(200);

Desbloqueamos el mutex para que otros hilos puedan leer/escribir someone_died
usleep(200) → dormimos 200 microsegundos antes de volver a comprobar
Esto evita que el hilo haga busy waiting completo, pero sigue respondiendo rápido si alguien muere.
