*This project has been created as part of the 42 curriculum by <bmartin->*

# Philosophers

## Description

The **Philosophers** project is an implementation of the classic *Dining Philosophers* problem, designed to introduce students to **concurrency**, **multithreading**, and **synchronization** in C using the threads library.

In this project, each philosopher is represented by a thread. Philosophers alternate between thinking, eating, and sleeping. In order to eat, a philosopher must acquire two forks, which are shared resources protected by mutexes. The main challenge is to manage access to these shared resources while avoiding race conditions, deadlocks, and starvation.

The simulation ends when a philosopher dies (fails to eat within `time_to_die`) or when all philosophers have eaten a specified number of times (`must_eat`) if this optional argument is provided.

## Instructions

### Compilation

The project is compiled using the provided Makefile, here you will find the compilation flags.

Run the following command in the root directory of the repository:

```bash
make
```
or

```bash
make -s
```

This command will generate an executable named philo.

### Execution

The parameters are:

./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]

```bash
./philo 8 310 200 100
./philo 5 800 200 200 7
```

All time values are expressed in milliseconds.

## Resources

Artificial Intelligence tools were used **only to understand the project and clarify concepts**.  
All implementation, coding, testing, and debugging were performed entirely by me.