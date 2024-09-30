#include <stdio.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	read = 0;
	size_t	i = 0;

	while (*s)
	{
		i = 0;
		while (reject[i])
		{
			if (reject[i++] == *s)
				return (read);
		}
		read++;
		s++;
	}
	return (read);
}

int	main(void)
{
	char	*s1 = "abcdefghijklmnopqrstuvwxyz";
	char	*reject = "ef";
	printf("%zu", ft_strcspn(s1, reject));
	return (0);
}
