/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahne <cdahne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:08:21 by cdahne            #+#    #+#             */
/*   Updated: 2024/05/08 20:07:36 by cdahne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
