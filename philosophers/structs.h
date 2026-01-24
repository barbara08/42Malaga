
#ifndef STRUCTS_H
# define STRUCTS_H

#include <pthread.h>

typedef struct s_rules
{
    int             nb_philos;      // Número de filósofos
    long            time_to_die;    // Tiempo máximo sin comer
    long            time_to_eat;    // Tiempo de comer
    long            time_to_sleep;  // Tiempo de dormir
    int             must_eat;       // Opcional: cuántas veces debe comer cada filósofo
    long            start_time;     // Momento de inicio
    int             someone_died;   // Flag para parar la simulación

    pthread_mutex_t *forks;         // Array de mutex para tenedores
    pthread_mutex_t print;          // Mutex para imprimir
    pthread_mutex_t dead_lock;     // Para proteger el flag someone_died
}   t_rules;

typedef struct s_philo
{
    int             id;             // ID del filósofo (1..N)
    int             meals_eaten;    // Cuántas veces ha comido
    long            last_meal;      // Momento del último plato

    pthread_t       thread;         // Thread del filósofo
    pthread_mutex_t *left_fork;     // Puntero al tenedor izquierdo
    pthread_mutex_t *right_fork;    // Puntero al tenedor derecho
    pthread_mutex_t philo_lock;    // Para proteger last_meal y meals_eaten

    t_rules         *rules;         // Puntero a las reglas globales
}   t_philo;

#endif