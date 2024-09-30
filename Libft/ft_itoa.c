/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahne <cdahne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:56:40 by cdahne            #+#    #+#             */
/*   Updated: 2024/04/25 13:51:23 by cdahne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_count_decimals(int n)
{
	unsigned int	dec;
	unsigned int	un;

	dec = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		dec++;
		un = -n;
	}
	else
		un = n;
	while (un >= 1)
	{
		dec++;
		un = un / 10;
	}
	return (dec);
}

char	*ft_itoa(int n)
{
	char			*number;
	size_t			len;
	unsigned int	un;

	len = ft_count_decimals(n);
	number = (char *) malloc ((len + 1) * sizeof(char));
	if (!number)
		return (NULL);
	if (n < 0)
	{
		*number = '-';
		un = -n;
	}
	else
		un = n;
	if (un == 0)
		*number = '0';
	number[len] = '\0';
	while (un >= 1)
	{
		number[len - 1] = un % 10 + '0';
		un = un / 10;
		len--;
	}
	return (number);
}
