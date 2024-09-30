/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahne <cdahne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 13:02:31 by cdahne            #+#    #+#             */
/*   Updated: 2024/04/26 13:31:10 by cdahne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*tempdest;
	const unsigned char	*tempsrc;

	tempdest = dest;
	tempsrc = src;
	if (dest == src || n == 0)
		return (dest);
	if (dest > src && dest - src < (long) n)
	{
		while (n--)
			tempdest[n] = tempsrc[n];
		return (dest);
	}
	else if (src > dest && src - dest < (long) n)
	{
		while (n--)
			*tempdest++ = *tempsrc++;
		return (dest);
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
