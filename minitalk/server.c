#include "minitalk.h"

t_mini  *server_start(void)
{
	t_mini	*talk;

	talk = malloc(sizeof(t_mini));
	if (!talk)
        return(NULL);
	
    talk->pid_server = 0;
	talk->pid_client = 0;
	
    return (talk);
}

void    server_received(int boolean)
{
	static int	bit_position = 0;
	static char	character = 0;
	
	character += ((boolean & 1) << bit_position++);
	if (bit_position == 7)
	{
		write(1, &character, 1);
		if (!character)
			write(1, "\n", 1);
		bit_position = 0;
		character = 0;
	}
	return;
}

void	server_run(t_mini *talk)
{
	if (signal(SIGUSR1, server_received) == SIG_ERR
        || signal(SIGUSR2, server_received) == SIG_ERR)
    {
        ft_putstr("SIGNAL ERROR!\n");
        free(talk);
        exit(EXIT_FAILURE);
    }

    while (1)
        pause();   // espera señales sin consumir CPU
}

int	main(int argc, char **argv)
{
	t_mini	*talk;
	
	(void)argv;
	talk = NULL;
	if (argc != 1)
	{
		ft_putstr("ONLY 1 ARGUMENT!\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		talk = server_start();
		talk->pid_server = getpid();
		ft_putstr("SERVER READY YOU PID IS => ");
		ft_putnbr(talk->pid_server);
		write(1, "\n", 1);
		server_run(talk);
	}
	free(talk);
	return (EXIT_SUCCESS);
}

/* ORIGINAL, FNCIONA
void	server_run(t_mini *talk)
{
	while (1)
	{
		if ((signal(SIGUSR1, server_received) == SIG_ERR)
			|| (signal(SIGUSR2, server_received) == SIG_ERR))
		{
			ft_putstr("SIGNAL ERROR!\n");
			free(talk);
			exit(EXIT_FAILURE);
		}
		sleep(2);
	}
	return;
}
*/