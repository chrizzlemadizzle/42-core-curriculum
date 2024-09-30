/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahne <cdahne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:06:01 by cdahne            #+#    #+#             */
/*   Updated: 2024/05/27 16:57:50 by cdahne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_conversion(va_list ap, char cnvspc)
{
	if (cnvspc == '%')
	{
		write(1, "%%", 1);
		return (1);
	}
	if (cnvspc == 'c')
		return (ft_putchar((char)va_arg(ap, int)));
	if (cnvspc == 's')
		return (ft_putstr(va_arg(ap, char *)));
	if (cnvspc == 'p')
		return (ft_putptr((intptr_t)va_arg(ap, void *)));
	if (cnvspc == 'd' || cnvspc == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	if (cnvspc == 'u')
		return (ft_putnbr_base((unsigned int)va_arg(ap, unsigned int),
				"0123456789"));
	if (cnvspc == 'x')
		return (ft_putnbr_base((unsigned int)va_arg(ap, int),
				"0123456789abcdef"));
	if (cnvspc == 'X')
		return (ft_putnbr_base((unsigned int)va_arg(ap, int),
				"0123456789ABCDEF"));
	return (0);
}

static const char	*ft_parse_formattags(const char *format)
{
	format++;
	if (*format && *format == '%')
		return (format);
	else
	{
		while (*format && *format != '%'
			&& ft_strchr("0123456789 .-#+", *format))
			format++;
	}
	if (ft_strchr("cspdiuxX", *format))
		return (format);
	return (NULL);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			counter;
	const char	*cnvspc;

	if (!format)
		return (-1);
	counter = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format != '%')
			counter += write(1, format++, 1);
		else
		{
			cnvspc = ft_parse_formattags(format);
			if (!cnvspc)
				return (-1);
			counter += ft_conversion(ap, *cnvspc);
			format = cnvspc + 1;
		}
	}
	va_end(ap);
	return (counter);
}
