#include <unistd.h>

void	ft_putnbr(int nbr)
{
	char	digit;

	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	digit = nbr % 10 + '0';
	write (1, &digit, 1);
	return ;
}

int	main(int argc, char **argv)
{
	char	sum;

	(void)argv;
	sum = argc - 1; 
	ft_putnbr(sum);
	return (0);
}
