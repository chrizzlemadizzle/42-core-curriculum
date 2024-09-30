#include "minitalk.h"

void	ft_send_char(pid_t server_pid, char octet)
{
	int	i;

	i = 8;
	while (i--)
	{
		if ((octet >> i & 1) == 0)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(50);
	}
}

void	ft_send_str(pid_t server_pid, char *str)
{
	if (kill(server_pid, 0) != 0)
	{
		ft_printf("No server with this PID found.\n");
		return ;
	}
	while (*str)
	{
		ft_send_char(server_pid, *str);
		str++;
	}
	return ;
}
void	acknowledgement(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("0");
	else if (sig == SIGUSR2)
		ft_printf("1");
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;

	signal(SIGUSR1, acknowledgement);
	signal(SIGUSR2, acknowledgement);
	if (argc == 3)
	{
		server_pid = atoi(argv[1]);
		ft_send_str(server_pid, argv[2]);
	}
	else
		ft_printf("Please enter two parameters: Server PID and string to transmit\n");
	return (0);
}
