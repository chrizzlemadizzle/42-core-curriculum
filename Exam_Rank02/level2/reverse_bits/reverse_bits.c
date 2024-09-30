#include <stdio.h>
#include <stdlib.h>

void	print_bits(unsigned char octet);

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	res = 0;
	int	i = 8;

	while (i--)
	{
		res = res << 1 | (octet & 1);
		octet = octet >> 1;
		
	}
	return (res);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		print_bits(atoi(argv[1]));
		printf("\n");
		print_bits(reverse_bits(atoi(argv[1])));
	}
	return (0);
}
