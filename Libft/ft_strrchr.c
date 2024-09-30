/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahne <cdahne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:25:50 by cdahne            #+#    #+#             */
/*   Updated: 2024/05/08 20:06:38 by cdahne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	char	ch;

	p = NULL;
	ch = c;
	if (ch == 0)
		p = (char *)s + ft_strlen(s);
	while (*s)
	{
		if (*s == ch)
			p = (char *)s;
		s++;
	}
	return (p);
}
