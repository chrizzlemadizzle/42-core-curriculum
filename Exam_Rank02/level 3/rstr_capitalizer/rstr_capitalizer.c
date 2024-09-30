#include <unistd.h>

int	ft_is_upper(char c)
{
	if (c >= 'A' && c <= 'Z')
		return(1);
	return (0);
}

int	ft_is_lower(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	int	i = 1;
	if (argc > 1)
	{
		while (i <= argc)
		{
			char *str = argv[i];
			while (*str)
			{
				if (*(str + 1) && (

