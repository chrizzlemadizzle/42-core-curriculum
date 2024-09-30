/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahne <cdahne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:25:24 by cdahne            #+#    #+#             */
/*   Updated: 2024/09/12 10:53:55 by cdahne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color	ft_make_argb(int a, int r, int g, int b)
{
	t_color	color;

	color.a = (uint8_t)a;
	color.r = (uint8_t)r;
	color.g = (uint8_t)g;
	color.b = (uint8_t)b;
	return (color);
}

double	ft_smooth_iteration(int i, t_complex z)
{
	double	i_smooth;
	double	magnitude_squared;

	magnitude_squared = pow(z.re, 2.0) + pow(z.im, 2.0);
	if (magnitude_squared <= 1)
		i_smooth = (double)i + 2;
	else
		i_smooth = (double)i + 2 - (log(log(magnitude_squared)) / log(2));
	return (i_smooth);
}

t_color	ft_interpolate_colors(double t, t_color color1, t_color color2)
{
	t_color	color;
	double	t_log;

	t_log = log(1 + t) / log(2);
	color = ft_make_argb(\
		(1 - t_log) * color1.a + t_log * color2.a, \
		(1 - t_log) * color1.r + t_log * color2.r, \
		(1 - t_log) * color1.g + t_log * color2.g, \
		(1 - t_log) * color1.b + t_log * color2.b);
	return (color);
}

t_color	ft_color_gradient(double i)
{
	t_color	color;
	double	i_lognorm;

	i_lognorm = log(1 + (double)i) / log(1 + (double)MAX_ITERATIONS);
	if (i_lognorm < 0.5)
		color = ft_interpolate_colors(i_lognorm / 0.5, \
			ft_make_argb(255, 160, 53, 160), \
			ft_make_argb(255, 245, 0, 245));
	else if (i_lognorm < 0.7)
		color = ft_interpolate_colors((i_lognorm - 0.5) / 0.2, \
			ft_make_argb(255, 245, 0, 245), \
			ft_make_argb(255, 0, 245, 208));
	else if (i_lognorm < 0.75)
		color = ft_interpolate_colors((i_lognorm - 0.7) / 0.05, \
			ft_make_argb(255, 0, 245, 208), \
			ft_make_argb(255, 0, 0, 0));
	else
		color = ft_interpolate_colors((i_lognorm - 0.75) / 0.25, \
			ft_make_argb(255, 0, 0, 0), \
			ft_make_argb(255, 245, 192, 0));
	return (color);
}
