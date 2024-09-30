/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahne <cdahne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:00:55 by cdahne            #+#    #+#             */
/*   Updated: 2024/09/23 12:00:58 by cdahne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_calloc(size_t nmemb, size_t size)
{
	char	*p;
	char	*tmp;

	if (nmemb != 0 && size >= SIZE_MAX / nmemb)
		return (NULL);
	p = (char *) malloc(nmemb * size);
	if (!p)
		return (NULL);
	tmp = p;
	while (nmemb--)
		*tmp++ = '\0';
	return (p);
}
