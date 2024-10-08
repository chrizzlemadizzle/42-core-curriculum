/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahne <cdahne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:45:50 by cdahne            #+#    #+#             */
/*   Updated: 2024/09/03 10:45:50 by cdahne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2++)
	{
		if (!*s1++)
			return (0);
	}
	return (*(const unsigned char *)s1 - *(const unsigned char *)(s2 - 1));
}
