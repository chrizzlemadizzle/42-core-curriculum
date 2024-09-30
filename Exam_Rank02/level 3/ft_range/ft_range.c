#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int	size;
	int	*arr;
	int	i = 0;

	if (end >= start)
	{
		size = end - start;
		arr = malloc(size * sizeof(int));
		while (i < size)
		{
			arr[i] = start + i;
			i++;
		}
	}
	else
	{
		size = start - end;
		arr = malloc(size * sizeof(int));
		while (i < size)
		{
			arr[i] = start - i;
			i++;
		}
	}
	return (&arr[0]);
}

int	main(void)
{
	int	*arr;
	
	arr = ft_range(1, 3);
	printf("range(1, 3)\n");
	printf("%i\n", arr[0]);
	printf("%i\n", arr[1]);
	printf("%i\n", arr[2]);

	arr = ft_range(0, -3);
	printf("range(0, -3)\n");
	printf("%i\n", arr[0]);
	printf("%i\n", arr[1]);
	printf("%i\n", arr[2]);
	printf("%i\n", arr[3]);
}
