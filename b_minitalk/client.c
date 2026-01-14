#include "minitalk.h"

t_mini	*client_start(void)
{
	t_mini	*talk;

	talk = malloc(sizeof(t_mini));
	if (!talk)
	{
		ft_putstr("ERROR!\n");
		exit(EXIT_FAILURE);
	}
	talk->pid_server = 0;
	//talk->pid_client = 0;
	return (talk);
}

void	client_send(t_mini *talk, char *message)
{
	int	i; //Índice para recorrer cada carácter del mensaje
	int	pos_bit; //Posición del bit actual (0-7)
	int	signal_type; //Tipo de señal a enviar (SIGUSR1 o SIGUSR2)

	i = -1;
	while (++i < ft_strlen(message))
	{
		pos_bit = -1; //Reinicia a -1 la posición del bit para el nuevo carácter
		signal_type = 0;
		//pre-incrementa pos_bit (empieza en 0) y envía cada bit del carácter
		while (++pos_bit < 8)
		{
			//message[i] >> pos_bit → desplaza el carácter para aislarlo en el bit actual
			//& 1 → extrae solo ese bit (0 o 1)
			if ((message[i] >> pos_bit) & 1) //
				signal_type = SIGUSR2;
			else
				signal_type = SIGUSR1;
			//Envía la señal al servidor usando su PID
			////kill() es la función de Unix para enviar señales entre procesos
			kill(talk->pid_server, signal_type);
			usleep(1000); //Espera 200 microsegundos entre cada bit, para asegurar que el servidor procese la señal antes de enviar la siguiente
		}
	}
	// Envía carácter nulo de terminación
    pos_bit = -1;
    while (++pos_bit < 8)
    {
        kill(talk->pid_server, SIGUSR1);
        usleep(1000);
    }
	return ;
}

int	main(int argc, char *argv[])
{
	t_mini	*talk;

	talk = NULL;
	if (argc != 3)
	{
		ft_putstr("ERROR!\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		talk = client_start();
		talk->pid_server = ft_atoi(argv[1]);
		if (talk->pid_server <= 0)
		{
			ft_putstr("ERROR!\n");
			free(talk);
			exit(EXIT_FAILURE);
		}
		client_send(talk, argv[2]);
	}
	free(talk);
	return (EXIT_SUCCESS);
}
