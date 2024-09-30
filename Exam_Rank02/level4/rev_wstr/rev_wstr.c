#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	char	*ptr = str;

	while (*str)
		str++;
	return (str - ptr);
}

int	main(int argc, char **argv)
{
	int	strlen;
	char	*rev;
	int	i = 0;
	int	j = 0;

	if (argc == 2)
	{
		strlen = ft_strlen(argv[1]);
		rev = (char *) malloc(strlen + 1);
		while (argv[1][i])
		{
			if (argv[1][i] == ' ' || argv[1][i] == '	')
			{
				j = i;
				while (j--)
				{
					rev[strlen - j] = argv[1][i - j];
				}
			}
			i++;
		}
		i = 0;
		while (rev[i])
		{
			write (1, &rev[i], 1);
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
