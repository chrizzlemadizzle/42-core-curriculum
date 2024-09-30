/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahne <cdahne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:33:09 by cdahne            #+#    #+#             */
/*   Updated: 2024/09/12 10:53:58 by cdahne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color	ft_choose_fractol(t_fractol *fractol)
{
	if (ft_strcmp("Mandelbrot", fractol->name) == 0)
		return (ft_mandel_escapetime(fractol));
	else if (ft_strcmp("Julia", fractol->name) == 0)
		return (ft_julia_escapetime(fractol));
	else if (ft_strcmp("Nova", fractol->name) == 0)
		return (ft_nova_escapetime(fractol));
	return (ft_make_argb(0, 0, 0, 0));
}

// z(n+1) = z(n) + (z(n)^3 - 1) / ( 3 * z(n)^2) + z(0)
t_color	ft_nova_escapetime(t_fractol *fractol)
{
	int			i;
	t_complex	z;
	double		d;
	t_color		color;
	double		i_smooth;

	i = 0;
	z = init_complex(fractol->c.re, fractol->c.im);
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 && i < MAX_ITERATIONS)
	{
		d = 9 * pow(pow(z.re, 2.0) - pow(z.im, 2.0), 2.0) \
			+ 36 * pow(z.re, 2.0) * pow(z.im, 2.0);
		z = init_complex(z.re - (3 * (pow(z.re, 3.0) - 3 * z.re * \
			pow(z.im, 2.0) - 1) * (pow(z.re, 2.0) - pow(z.im, 2.0)) + 6 * z.re \
			* z.im * (3 * pow(z.re, 2.0) * z.im - pow(z.im, 3.0))) / d + \
			fractol->k.re, \
			z.im - (3 * (pow(z.re, 2.0) - pow(z.im, 2.0)) * \
			(3 * pow(z.re, 2.0) * z.im - pow(z.im, 3.0)) - 6 * z.re * z.im * \
			(pow(z.re, 3.0) - 3 * z.re * pow(z.im, 2.0) - 1)) / d + \
			fractol->k.im);
		i++;
	}
	i_smooth = ft_smooth_iteration(i, z);
	color = ft_color_gradient(i_smooth);
	return (color);
}

t_color	ft_julia_escapetime(t_fractol *fractol)
{
	int			i;
	t_complex	z;
	t_color		color;
	double		i_smooth;

	i = 0;
	z = init_complex(fractol->c.re, fractol->c.im);
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 && i < MAX_ITERATIONS)
	{
		z = init_complex(pow(z.re, 2.0) - pow(z.im, 2.0) + fractol->k.re, \
			2 * z.re * z.im + fractol->k.im);
		i++;
	}
	i_smooth = ft_smooth_iteration(i, z);
	color = ft_color_gradient(i_smooth);
	return (color);
}

t_color	ft_mandel_escapetime(t_fractol *fractol)
{
	int			i;
	t_complex	z;
	t_color		color;
	double		i_smooth;

	z = init_complex(fractol->c.re, fractol->c.im);
	i = 0;
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 && i < MAX_ITERATIONS)
	{
		z = init_complex(\
			pow(z.re, 2.0) - pow(z.im, 2.0) + fractol->c.re, \
			2 * z.re * z.im + fractol->c.im);
		i++;
	}
	i_smooth = ft_smooth_iteration(i, z);
	color = ft_color_gradient(i_smooth);
	return (color);
}
