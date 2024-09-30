#include <unistd.h>

void	ft_putnbr(int nbr)
{
	char	digit;

	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	digit = nbr % 10 + '0';
	write(1, &digit, 1);
}

int	ft_atoi(char *nbr)
{
	int	res = 0;
	while (*nbr)
	{
		res = res * 10 + *nbr - '0';
		nbr++;
	}
	return (res);
}

int	main(int argc, char **argv)
{
	int	i = 1;
	if (argc == 2)
	{
		while (i <= 9)
		{
			ft_putnbr(i);
			write(1, " x ", 3);
			ft_putnbr(ft_atoi(argv[1]);
			write(1, " = ", 3);
			ft_putnbr(
			write(1, "\n", 1);
			i++;
		}

