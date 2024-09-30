#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr_hex(int nbr)
{
	int	digit;

	if (nbr >= 16)
		ft_putnbr_hex(nbr / 16);
	digit = nbr % 16;
	if (digit >= 10)
		ft_putchar(digit - 10 + 'a');
	else
		ft_putchar(digit + '0');
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
	if (argc == 2)
	{
		int nbr = ft_atoi(argv[1]);
		if (nbr >= 0)
			ft_putnbr_hex(nbr);
	}
	write (1, "\n", 1);
	return (0);
}
