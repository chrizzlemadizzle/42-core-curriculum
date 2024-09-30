/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahne <cdahne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:31:09 by cdahne            #+#    #+#             */
/*   Updated: 2024/05/14 19:31:03 by cdahne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*strjoin;
	size_t	i;

	len = ft_strlen(s1) + ft_strlen(s2);
	strjoin = (char *) malloc (len * sizeof(char) + 1);
	if (!strjoin)
		return (NULL);
	i = 0;
	while (*s1)
	{
		strjoin[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		strjoin[i] = *s2;
		i++;
		s2++;
	}
	strjoin[i] = '\0';
	return (strjoin);
}
