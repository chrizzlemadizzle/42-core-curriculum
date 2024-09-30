/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahne <cdahne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:08:40 by cdahne            #+#    #+#             */
/*   Updated: 2024/04/25 14:17:06 by cdahne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			len;
	char			*mappedstr;
	unsigned int	i;

	len = ft_strlen(s);
	mappedstr = (char *) malloc ((len + 1) * sizeof(char));
	if (!mappedstr)
		return (NULL);
	i = 0;
	while (s[i])
	{
		mappedstr[i] = f(i, s[i]);
		i++;
	}
	mappedstr[i] = '\0';
	return (mappedstr);
}
