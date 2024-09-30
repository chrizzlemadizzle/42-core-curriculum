/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahne <cdahne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:27:48 by cdahne            #+#    #+#             */
/*   Updated: 2024/06/13 17:14:52 by cdahne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*tempdest;
	const unsigned char	*tempsrc;

	tempdest = dest;
	tempsrc = src;
	if (dest == src || n == 0)
		return (dest);
	if (dest > src && dest - src < (long) n)
	{
		while (n--)
			tempdest[n] = tempsrc[n];
		return (dest);
	}
	else if (src > dest && src - dest < (long) n)
	{
		while (n--)
			*tempdest++ = *tempsrc++;
		return (dest);
	}
	else
	{
		while (n--)
			*tempdest++ = *tempsrc++;
	}
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

void	ft_lstadd_back_new(t_list **lst, char *content)
{
	t_list	*newlist;

	newlist = (t_list *) malloc(sizeof(t_list));
	if (!newlist)
		return ;
	newlist->content = content;
	newlist->next = NULL;
	if (*lst == NULL)
		*lst = newlist;
	else
	{
		while (*lst)
		{
			if (!(*lst)->next)
				break ;
			*lst = (*lst)->next;
		}
		(*lst)->next = newlist;
	}
}

/*
void	ft_print_list(t_list *list)
{
		while (list)
	{
		printf("%s\n", list->content);
		list = list->next;
	}
}*/

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
