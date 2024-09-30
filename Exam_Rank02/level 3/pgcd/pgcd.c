#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	unsigned int	a;
	unsigned int	b;

	if (argc == 3)
	{
		a = atoi(argv[1]);
		b = atoi(argv[2]);
		if (a > 0 && b > 0)
		{
			while (a != b)
			{
				if (a > b)
					a = a - b;
				else
					b = b - a;
			}
		}
		printf("%i", a);
	}
	printf("\n");
	return (0);
}
