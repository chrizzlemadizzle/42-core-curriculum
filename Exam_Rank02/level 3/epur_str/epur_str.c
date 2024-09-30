#include <unistd.h>

char	*ft_skip_spaces(char *str)
{
	while (*str && (*str == ' ' || *str == '	'))
			str++;
	return (str);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		char *str = argv[1];
		str = ft_skip_spaces(str);
		while (*str)
		{
			if (*str == ' ' || *str == '	')
			{
				str = ft_skip_spaces(str);
				if (*str)
					write(1, " ", 1);
			}
			else
				write(1, str++, 1);
		}
	}
	write(1, "\n", 1);
	return (0);
}
