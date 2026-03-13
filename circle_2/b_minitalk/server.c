#include "minitalk.h"

//Función crea e inicializa la estructura t_mini y devuelve un puntero a ella
t_mini	*server_start(void)
{
	t_mini	*talk;

	talk = malloc(sizeof(t_mini));
	if (!talk)
	{
		ft_putstr("ERROR!\n");
		exit(EXIT_FAILURE); //Imprime errror y termina programa con código de error
	}
	talk->pid_server = 0;
	//talk->pid_client = 0;
	return (talk);
}
//Función que maneja las señales recibidas (SIGUSR1 (0) o SIGUSR2(1))
//Recibe como parámetro signal_num (el número de la señal recibida)
void	server_received(int signal_num)
{
	static int	pos_bit = 0; //Guarda la posición del bit actual (0-7), solo se inicializa una vez, mantiene su valor entre llamadas
	static char	character_bit = 0; //Acumula los bits recibidos para formar un carácter completo(8bits)
	/*
	1. (signal_num == SIGUSR2) → devuelve 1 si es SIGUSR2, 0 si es SIGUSR1
	2. << pos_bit++ → coloca el bit en su posición correcta dentro del byte
	3. character_bit += → suma el bit al carácter acumulado (armar el carácter bit a bit)
	4. pos_bit++ → incrementa para el siguiente bit
	*/
	character_bit += ((signal_num == SIGUSR2) << pos_bit++);
	//Comprueba si ya hemos recibido 8 bits (un carácter completo)
	if (pos_bit == 8)
	{
		write(1, &character_bit, 1);
		//Si el carácter es nulo (fin de mensaje), escribe una nueva línea
		if (!character_bit)
			write(1, "\n", 1);
		// Reinicia las variables para recibir el siguiente carácter
		pos_bit = 0;
		character_bit = 0;
	}
	return ;
}

//Función que configura el servidor para recibir señales y entra en un bucle (loop) infinito esperando señales
//Esta función configura los manejadores de señales y mantiene el servidor escuchando infinitamente las señales SIGUSR1 y SIGUSR2 del cliente
void server_loop(t_mini *talk)
{
	/* if()
		//Cuando llamamos a signal(), NO se está ejecutando función. Solo se está registrando.
		//Cuando llegue la señal SIGUSR1, llama a la función server_received.
		//No lo llamamos ahora, solo le pasamos el puntero a la función, (su dirección en memoria)
		signal(SIGUSR1, server_received) → cuando llegue SIGUSR1, ejecuta server_received (cuando reciba la señal 0)
		signal(SIGUSR2, server_received) → cuando llegue SIGUSR2, ejecuta server_received (cuando reciba la señal 1)
		Si cualquiera falla (== SIG_ERR), entra en el bloque de error
	*/
	/*
		{
			Si falló el registro de señales:
			Imprime un mensaje de error
			Libera la memoria de talk
			Termina el programa con código de error
		}
	*/
    if (signal(SIGUSR1, server_received) == SIG_ERR
        || signal(SIGUSR2, server_received) == SIG_ERR)
    {
        ft_putstr("ERROR!, \n");
        free(talk);
        exit(EXIT_FAILURE);
    }
	/*
		Bucle infinito que mantiene el servidor activo
		pause() detiene el proceso esperando señales sin consumir CPU
		Cada vez que llega una señal, se ejecuta server_received y luego vuelve a pause()
	*/
    while (1)
        pause();
}

int	main(int argc, char *argv[])
{
	t_mini	*talk; //Declara un puntero a la estructura t_mini
	
	(void)argv; // Ignora el parámetro argv ya que no se usa
	talk = NULL;
	if (argc != 1)
	{
		ft_putstr("ERROR!, 1 argument\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		talk = server_start(); //Llama server_start() para crear la estructura
		talk->pid_server = getpid(); //Obtiene el PID del servidor y lo guarda en la estructura
		ft_putstr("SUCCESS! PID: "); //Imprime mensaje de éxito junto con el PID del servidor (linea de abajo)
		ft_putnbr(talk->pid_server); //Imprime el número del PID
		write(1, "\n", 1);
		server_loop(talk); //Llama a server_loop() para iniciar el bucle infinito de recepción de señales
	}
	free(talk);
	return (EXIT_SUCCESS);
}



/*
character_bit += ((signal_num == SIGUSR2) << pos_bit++);

Ejemplo de cómo se acumulan los bits recibidos medianteseñales para 'A' (01000001)
pos_bit		Bit en ASCII		Señal enviada		Cálculo
0				1				SIGUSR2				1 << 0 = 1
1				0				SIGUSR1				0 << 1 = 0
2				0				SIGUSR1				0 << 2 = 0
3				0				SIGUSR1				0 << 3 = 0
4				0				SIGUSR1				0 << 4 = 0
5				0				SIGUSR1				0 << 5 = 0
6				1				SIGUSR2				1 << 6 = 64
7				0				SIGUSR1				0 << 7 = 0

Sumando todos los valores: 1 + 64 = 65, que es el valor ASCII de 'A'
*/