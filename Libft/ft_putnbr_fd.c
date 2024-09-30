/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahne <cdahne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 12:23:21 by cdahne            #+#    #+#             */
/*   Updated: 2024/05/14 20:14:23 by cdahne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	un;
	char			digit;

	if (n < 0)
	{
		write(fd, "-", 1);
		un = -n;
	}
	else
		un = n;
	if (un >= 10)
	{
		ft_putnbr_fd(un / 10, fd);
		digit = un % 10 + '0';
		write(fd, &digit, 1);
	}
	else
	{
		digit = un + '0';
		write(fd, &digit, 1);
	}
}
