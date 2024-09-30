#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i = 0;
	int	j = 0;

	if (argc == 3)
	{
		while (argv[1][i])
		{
			while (argv[2][j])
			{
				if (argv[1][i] == argv[2][j])
					write (1, &argv[1][i], 1);
				j++;
			}
			j = 0;
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
