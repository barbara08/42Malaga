#include "minitalk.h"

t_mini	*client_start(void)
{
	t_mini	*talk;

	talk = malloc(sizeof(t_mini));
	if (!talk)
        return(NULL);
    
	talk->pid_server = 0;
	talk->pid_client = 0;
	
    return (talk);
}

void	client_send(t_mini *talk, char *message)
{
	int	i;
	int	bit_position;
	int	signal;

	i = -1;
	while (++i <= ft_strlen(message))
	//while (i <= ft_strlen(message)) no sale
	{
		bit_position = -1;
		signal = 0;
		while (++bit_position < 7)
		//while (bit_position < 7) no sale
		{
			if ((message[i] >> bit_position) & 1)
				signal = SIGUSR2;
			else
				signal = SIGUSR1;
			kill(talk->pid_server, signal);
			usleep(200);
            //bit_position++;
		}
        //i++;
	}
	return;
}

int	main(int argc, char **argv)
{
	t_mini	*talk;

	talk = NULL;
	if (argc != 3)
	{
		ft_putstr("ERROR!, YOU NEED 3 ARGIMENTS\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		talk = client_start();
		talk->pid_server = ft_atoi(argv[1]);
		if (talk->pid_server <=0)
		{
			ft_putstr("ERROR!, THE PID IS INCORRECT\n");
			free(talk);
			exit(EXIT_FAILURE);
		}
		client_send(talk, argv[2]);
	}
	free(talk);
	return (EXIT_SUCCESS);
}