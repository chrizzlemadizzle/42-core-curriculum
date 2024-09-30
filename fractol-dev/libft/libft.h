/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahne <cdahne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:06:49 by cdahne            #+#    #+#             */
/*   Updated: 2024/09/12 09:17:03 by cdahne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

int				ft_printf(const char *format, ...);
char			*ft_strchr(const char *s, int c);
int				ft_putchar(char c);
int				ft_putstr(char *s);
size_t			ft_strlen(const char *str);
unsigned int	ft_putnbr(int n);
unsigned int	ft_putnbr_base(unsigned long nbr, char *base);
unsigned int	ft_putptr(intptr_t p);
int				ft_atoi(const char *nptr);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_isdigit(int c);
double			ft_atof(const char *p);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
void			*ft_memcpy(void *dest, const void *src, size_t n);
#endif
