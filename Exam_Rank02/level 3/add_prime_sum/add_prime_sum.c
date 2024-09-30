#include <unistd.h>
#include <stdio.h>
#include <limits.h>

int	ft_is_prime(int i)
{
	int	d = 2;
	
	if (i <= 1)
		return (0);
	while (d * d <= i)
	{
		if (i % d == 0)
			return (0);
		d++;
	}
	return (1);
}

void	ft_putnbr(int i)
{
	char	digit;

	if (i >= 10)
		ft_putnbr(i / 10);
	digit = i % 10 + '0';
	write(1, &digit, 1);
	return ;
}

int	ft_atoi(char *number)
{
	int	res = 0;

	while (*number)
	{
		res = res * 10 + *number - '0';
		number++;
	}
	return (res);
}

int	main(int argc, char *argv[])
{
	unsigned int	nbr;
	unsigned int	sum;
	if (argc == 2)
	{
		nbr = ft_atoi(argv[1]);
		sum = 0;
		while (nbr > 1)
		{
			if (ft_is_prime(nbr))
				sum += nbr;
			nbr--;
		}
		ft_putnbr(sum);
	}
	if (argc != 2)
		ft_putnbr(0);
	write(1, "\n", 1);
	return (0);
}
