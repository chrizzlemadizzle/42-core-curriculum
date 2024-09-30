/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahne <cdahne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:21:18 by cdahne            #+#    #+#             */
/*   Updated: 2024/08/19 16:13:32 by cdahne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_count_digits(unsigned long n, unsigned int radix)
{
	unsigned int	dec;

	dec = 0;
	if (n == 0)
		return (1);
	while (n >= 1)
	{
		dec++;
		n = n / radix;
	}
	return (dec);
}

static int	ft_invalid_argument(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(base) <= 1)
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] < 32 || base[i] > 127)
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	return (1);
}

static void	ft_putnbr_base_rec(unsigned long nbr, char *base)
{
	unsigned int	radix;

	radix = ft_strlen(base);
	if (nbr >= radix)
	{
		ft_putnbr_base_rec(nbr / radix, base);
		ft_putchar(base[nbr % radix]);
	}
	else if (nbr < radix)
		ft_putchar(base[nbr % radix]);
}

unsigned int	ft_putnbr_base(unsigned long nbr, char *base)
{
	unsigned int	radix;

	if (!ft_invalid_argument(base))
		return (0);
	radix = ft_strlen(base);
	ft_putnbr_base_rec(nbr, base);
	return (ft_count_digits(nbr, radix));
}
/*
int	main(void)
{
	int	nbr;
	char	*base;

	base = "0123";
	nbr = 9;
	ft_putnbr_base(nbr, base);
	return (0);
}*/
