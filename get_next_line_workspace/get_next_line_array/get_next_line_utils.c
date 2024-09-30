/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahne <cdahne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:27:48 by cdahne            #+#    #+#             */
/*   Updated: 2024/06/05 15:39:32 by cdahne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			ch;

	ch = c;
	i = 0;
	while (s[i] != ch && s[i])
		i++;
	if (!s[i] && ch != '\0')
		return (NULL);
	else
		return ((char *)&s[i]);
}

size_t	ft_strlen(const char *str)
{
	const char	*temp;

	temp = str;
	while (*temp)
		temp++;
	return (temp - str);
}
