/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahne <cdahne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 12:23:21 by cdahne            #+#    #+#             */
/*   Updated: 2024/08/19 16:13:29 by cdahne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_count_decimals(int n)
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

unsigned int	ft_putnbr(int n)
{
	unsigned int	un;
	unsigned int	dec;

	dec = 0;
	if (n < 0)
	{
		ft_putchar('-');
		un = -n;
	}
	else
		un = n;
	if (un >= 10)
	{
		ft_putnbr(un / 10);
		ft_putchar(un % 10 + '0');
	}
	else
	{
		ft_putchar(un + '0');
	}
	return (ft_count_decimals(n));
}
