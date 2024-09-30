/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahne <cdahne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:06:49 by cdahne            #+#    #+#             */
/*   Updated: 2024/09/23 16:10:37 by cdahne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int				ft_printf(const char *format, ...);
char			*ft_strchr(const char *s, int c);
int				ft_putchar(char c);
int				ft_putstr(char *s);
size_t			ft_strlen(const char *str);
unsigned int	ft_putnbr(int n);
unsigned int	ft_putnbr_base(unsigned long nbr, char *base);
unsigned int	ft_putptr(intptr_t p);
long			ft_atoi(const char *nptr);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_isdigit(int c);
double			ft_atof(const char *p);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
char			**ft_split(char const *s, char c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strdup(const char *s);
char			*ft_get_next_line(int fd);
char			*ft_calloc(size_t nmemb, size_t size);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), \
	void (*del)(void *));
t_list			*ft_lstnew(void *content);
int				ft_lstsize(t_list *lst);
#endif
