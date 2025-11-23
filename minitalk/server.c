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
	return (talk);
}

void	server_received(int signal_num)
{
	static int	pos_bit = 0;
	static char	character_bit = 0;
	
	character_bit += ((signal_num == SIGUSR2) << pos_bit++);
	if (pos_bit == 8)
	{
		write(1, &character_bit, 1);
		if (!character_bit)
			write(1, "\n", 1);
		pos_bit = 0;
		character_bit = 0;
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
        pause();
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
		ft_putstr("SUCCESS! PID NUMBER: ");
		ft_putnbr(talk->pid_server);
		write(1, "\n", 1);
		server_loop(talk);
	}
	free(talk);
	return (EXIT_SUCCESS);
}
