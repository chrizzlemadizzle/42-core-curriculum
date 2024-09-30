/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahne <cdahne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:05:26 by cdahne            #+#    #+#             */
/*   Updated: 2024/05/08 17:21:18 by cdahne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*tempdest;
	const unsigned char	*tempsrc;

	if (n == 0 || dest == src)
		return (dest);
	if ((dest > src && dest - src < (long) n)
		|| (src > dest && src - dest < (long) n))
		return (NULL);
	tempdest = dest;
	tempsrc = src;
	while (n--)
		*tempdest++ = *tempsrc++;
	return (dest);
}
