/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahne <cdahne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 11:36:46 by cdahne            #+#    #+#             */
/*   Updated: 2024/09/11 15:53:38 by cdahne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>

static int	ft_int_part(const char *p)
{
	int	int_part;

	int_part = 0;
	while (isdigit((unsigned char)*p))
		int_part = int_part * 10 + (*p++ - '0');
	return (int_part);
}

static double	ft_frac_part(const char *p)
{
	int	frac_part;
	int	frac_divisor;

	frac_part = 0;
	frac_divisor = 1;
	if (*p++ == '.')
	{
		while (isdigit((unsigned char)*p))
		{
			frac_part = frac_part * 10 + (*p++ - '0');
			frac_divisor *= 10;
		}
	}
	return ((double)frac_part / frac_divisor);
}

double	ft_atof(const char *p)
{
	int		sign;
	int		int_part;
	double	frac_part;

	sign = 1;
	frac_part = 0;
	int_part = 0;
	if (*p == '-')
	{
		sign *= -1;
		p++;
	}
	else if (*p == '+')
		p++;
	int_part = ft_int_part(p);
	while (ft_isdigit((unsigned char)*p))
		p++;
	frac_part = ft_frac_part(p);
	return (sign * (int_part + frac_part));
}

// int main() {
//     printf("%f\n", ft_atof("123.456"));    // 123.456000
//     printf("%f\n", ft_atof("-123.456"));   // -123.456000
//     printf("%f\n", ft_atof("0.001"));      // 0.001000
//     printf("%f\n", ft_atof("789"));        // 789.000000
//     return 0;
// }
