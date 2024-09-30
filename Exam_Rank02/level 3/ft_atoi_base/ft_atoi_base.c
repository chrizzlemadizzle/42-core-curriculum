#include <stdio.h>

int	ft_get_factor(char digit, int str_base)
{
	int	factor;
	int	max;

	if (str_base <= 10)
		max = str_base + '0';
	else
		max = str_base + 'a' - 10;
	if (digit >= 'a' && digit <= 'f' && digit <= max)
		factor = digit - 'a' + 10;
	else if (digit >= 'A' && digit <= 'F' && digit <= max)
		factor = digit - 'A' + 10;
	else if (digit >= '0' && digit <= '9' && digit <= max)
		factor = digit - '0';
	else
		factor = -1;
	return (factor);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	sign = 1;
	int	result = 0;
	int	factor;

	if (*str == '-')
	{
		sign = -sign;
		str++;
	}
	while ((factor = ft_get_factor(*str, str_base)) >= 0)
	{
		result = result * str_base + factor;
		str++;
	}
	return (sign * result);
}

int	main(void)
{
	printf("%i", ft_atoi_base("0101", 2));
	return (0);
}
