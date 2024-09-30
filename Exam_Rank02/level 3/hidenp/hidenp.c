#include <unistd.h>

/*
int	main(int argc, char **argv)
{
	int	i = 0;
	int	j = 0;

	if (argc == 3)
	{
		if (!argv[1][0])
		{
			write (1, "1\n", 2);
			return (1);
		}
		while (argv[1][i])
		{
			while (argv[2][j] && argv[1][i] != argv[2][j])
				j++;
			if (argv[1][i] == argv[2][j] && argv[2][j])
				i++;
			else
			{
				write(1, "0\n", 2);
				return (0);
			}
		}
		write (1, "1", 1);
	}
	write(1, "\n", 1);
	return (0);
}*/

int	main(int argc, char **argv)
{
	int	i = 0;
	int	j = 0;

	if (argc == 3)
	{
		while (argv[1][i] && argv[2][j])
		{
			if (argv[1][i] == argv[2][j])
				i++;
			j++;
		}
		if (!argv[1][i])
			write (1, "1", 1);
		else
			write (1, "0", 1);
		}
	write (1, "\n", 1);
	return (0);
}
