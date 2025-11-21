#include "minitalk.h"

t_mini	*server_start(void)
{
	t_mini	*talk;

	talk = malloc(sizeof(t_mini));
	if (!talk)
	{
		ft_putstr("ERROR!\n");
		exit(EXIT_FAILURE);
	}
	talk->pid_server = 0;
	talk->pid_client = 0;
	return (talk);
}

void	server_received(int signal_num)
{
	static int	bit_displacement = 0;
	static char	letter = 0;
	
	letter += ((signal_num == SIGUSR2) << bit_displacement++);
	if (bit_displacement == 8)
	{
		write(1, &letter, 1);
		if (!letter)
			write(1, "\n", 1);
		bit_displacement = 0;
		letter = 0;
	}
	return ;
}
void server_loop(t_mini *talk)
{
    if (signal(SIGUSR1, server_received) == SIG_ERR
        || signal(SIGUSR2, server_received) == SIG_ERR)
    {
        ft_putstr("ERROR!, \n");
        free(talk);
        exit(EXIT_FAILURE);
    }

    while (1)
        pause();   // espera señales sin consumir CPU
}

int	main(int argc, char *argv[])
{
	t_mini	*talk;
	
	(void)argv;
	talk = NULL;
	if (argc != 1)
	{
		ft_putstr("ERROR!, 1 argument\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		talk = server_start();
		talk->pid_server = getpid();
		ft_putstr("SUCCESS!, PID: ");
		ft_putnbr(talk->pid_server);
		write(1, "\n", 1);
		server_loop(talk);
	}
	free(talk);
	return (EXIT_SUCCESS);
}
