/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahne <cdahne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 10:17:25 by cdahne            #+#    #+#             */
/*   Updated: 2024/05/16 15:03:52 by cdahne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_countwords(char const *s, char c)
{
	unsigned int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s && *s != c)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

size_t	ft_wordlen(char const *s, char c)
{
	size_t	wordlen;
	char	*nextdel;

	nextdel = ft_strchr(s, c);
	if (nextdel == NULL)
		wordlen = ft_strlen(s);
	else
		wordlen = nextdel - s;
	return (wordlen);
}

char	**ft_parsewords(char **words, const char *s, char c, unsigned int wcnt)
{
	unsigned int	i;
	size_t			wordlen;

	i = 0;
	while (i < wcnt)
	{
		while (*s && *s == c)
			s++;
		wordlen = ft_wordlen(s, c);
		words[i] = ft_substr(s, 0, wordlen);
		if (!words[i])
		{
			while (i > 0)
			{
				free(words[i - 1]);
				i--;
			}
			free(words);
			return (NULL);
		}
		s = s + wordlen;
		i++;
	}
	words[i] = NULL;
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char			**words;
	unsigned int	wcnt;

	wcnt = ft_countwords(s, c);
	words = (char **) malloc ((wcnt + 1) * sizeof(char *));
	if (!words)
		return (NULL);
	return (ft_parsewords(words, s, c, wcnt));
}
