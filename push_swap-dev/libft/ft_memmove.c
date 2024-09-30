/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahne <cdahne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:02:32 by cdahne            #+#    #+#             */
/*   Updated: 2024/09/23 12:02:33 by cdahne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// move memory from *src to *dest
// also handling overlapping memory blocks
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*tempdest;
	const unsigned char	*tempsrc;

	tempdest = dest;
	tempsrc = src;
	if (dest == src || n == 0)
		(void)dest;
	else if (dest > src && dest - src < (long) n)
	{
		while (n--)
			tempdest[n] = tempsrc[n];
	}
	else
	{
		while (n--)
			*tempdest++ = *tempsrc++;
	}
	return (dest);
}
