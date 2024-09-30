#include <stdio.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
	size_t	i = 0;

	while (*s1)
	{
		i = 0;
		while (s2[i])
		{
			if (s2[i] == *s1)
				return ((char *)s1);
			i++;
		}
		s1++;
	}
	return (NULL);
}

int	main(void)
{
	char	*s1 = "abcdefghijkl";
	char	*accept = "def";

	printf("%li", ft_strpbrk(s1, accept) - s1);
	return (0);
}
