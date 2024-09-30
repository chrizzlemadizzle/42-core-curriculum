#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		int	a = atoi(argv[1]);
		char	op = argv[2][0];
		int	b = atoi(argv[3]);
		int	res = 0;

		if (op == '+')
			res = a + b;
		if (op == '-')
			res = a - b;
		if (op == '*')
			res = a * b;
		if (op == '/')
			res = a / b;
		if (op == '%')
			res = a % b;
		printf("%i\n", res);
	}
	else 
		write (1, "\n", 1);
	return (0);
}
