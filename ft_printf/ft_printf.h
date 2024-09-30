/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahne <cdahne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:06:49 by cdahne            #+#    #+#             */
/*   Updated: 2024/05/27 17:01:43 by cdahne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
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

#endif
