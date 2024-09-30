/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahne <cdahne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:51:36 by cdahne            #+#    #+#             */
/*   Updated: 2024/04/26 13:52:40 by cdahne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;

	if (n == 0)
		return (NULL);
	p = (unsigned char *)s;
	while (n--)
	{
		if (*p == (unsigned char) c)
			return ((void *)p);
		p++;
	}
	return (NULL);
}
