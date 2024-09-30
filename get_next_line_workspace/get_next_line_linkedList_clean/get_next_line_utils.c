/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahne <cdahne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:27:48 by cdahne            #+#    #+#             */
/*   Updated: 2024/06/14 14:43:56 by cdahne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// move memory from *src to *dest
// also handling overlapping memory blocks
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*tempdest;
	const unsigned char	*tempsrc;

	tempdest = dest;
	tempsrc = src;
	if (dest == src || n == 0)
		(void)dest;
	else if (dest > src && dest - src < (long) n)
	{
		while (n--)
			tempdest[n] = tempsrc[n];
	}
	else
	{
		while (n--)
			*tempdest++ = *tempsrc++;
	}
	return (dest);
}

// return pointer to first occurrence of c in *s, else NULL
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

// create new node from content and add it to the end of *lst
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

/* // helper function to print out all nodes of t_remainder
void	ft_print_list(t_list *list)
{
		while (list)
	{
		printf("%s\n", list->content);
		list = list->next;
	}
}*/

// allocate memory and set all memcells to '\0'
// avoid overflow
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
