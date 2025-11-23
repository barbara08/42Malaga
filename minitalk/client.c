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
	return (talk);
}

void	client_send(t_mini *talk, char *message)
{
	int	i;
	int	pos_bit;
	int	signal_type;

	i = -1;
	while (++i < ft_strlen(message))
	{
		pos_bit = -1;
		signal_type = 0;
		while (++pos_bit < 8)
		{
			if ((message[i] >> pos_bit) & 1)
				signal_type = SIGUSR2;
			else
				signal_type = SIGUSR1;
			kill(talk->pid_server, signal_type);
			usleep(200);
		}
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
