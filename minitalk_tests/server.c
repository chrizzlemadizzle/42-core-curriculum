#include "minitalk.h"

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static unsigned char	octet;
	static int	i;

	i++;
	if (sig == SIGUSR2)
		octet += 1;
	if (i == 8)
	{
		ft_printf("%c", octet);
		i = 0;
		octet = 0;
	}
	else
		octet = octet << 1;
	if (sig == SIGUSR1)
		kill(info->si_pid, SIGUSR1);
	else if (sig == SIGUSR2)
		kill(info->si_pid, SIGUSR2);
	(void)context;
}

int	main(void)
{
	struct sigaction	signal_received;

	ft_printf("PID %d\n", getpid());
	ft_printf("Waiting for signals...\n");
	signal_received.sa_sigaction = handle_signal;
	signal_received.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &signal_received, NULL);
	sigaction(SIGUSR2, &signal_received, NULL);
	while (1)
		pause();
	return (0);
}
