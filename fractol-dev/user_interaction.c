/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_interaction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahne <cdahne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:34:58 by cdahne            #+#    #+#             */
/*   Updated: 2024/09/12 10:49:12 by cdahne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(t_fractol *fractol)
{
	mlx_loop_end(fractol->mlx);
	ft_free_all(fractol);
	exit(0);
}

void	ft_move(int keycode, t_fractol *fractol)
{
	if (keycode == XK_a || keycode == XK_Left)
	{
		fractol->min.re -= 0.1 * (fractol->max.re - fractol->min.re);
		fractol->max.re -= 0.1 * (fractol->max.re - fractol->min.re);
	}
	else if (keycode == XK_d || keycode == XK_Right)
	{
		fractol->min.re += 0.1 * (fractol->max.re - fractol->min.re);
		fractol->max.re += 0.1 * (fractol->max.re - fractol->min.re);
	}
	else if (keycode == XK_s || keycode == XK_Down)
	{
		fractol->min.im += 0.1 * (fractol->max.im - fractol->min.im);
		fractol->max.im += 0.1 * (fractol->max.im - fractol->min.im);
	}
	else if (keycode == XK_w || keycode == XK_Up)
	{
		fractol->min.im -= 0.1 * (fractol->max.im - fractol->min.im);
		fractol->max.im -= 0.1 * (fractol->max.im - fractol->min.im);
	}
	ft_draw_fractol(fractol);
}

int	key_handler(int keycode, t_fractol *fractol)
{
	if (keycode == XK_Escape)
	{
		mlx_loop_end(fractol->mlx);
		ft_free_all(fractol);
		exit (0);
	}
	else if (keycode == XK_a || keycode == XK_Left || keycode == XK_d || \
		keycode == XK_Right || keycode == XK_s || keycode == XK_Down || \
		keycode == XK_w || keycode == XK_Up)
		ft_move(keycode, fractol);
	return (0);
}

int	mouse_handler(int mousecode, int x, int y, t_fractol *fractol)
{
	t_complex	mouse_pos;
	double		zoom;

	zoom = 1.0;
	mouse_pos = init_complex(\
		(double)x / WINDOW_WIDTH * \
		(fractol->max.re - fractol->min.re) + fractol->min.re, \
		(double)y / WINDOW_HEIGHT * \
		(fractol->max.im - fractol->min.im) + fractol->min.im);
	if (mousecode == 4)
		zoom = 10.0;
	else if (mousecode == 5)
		zoom = 0.1;
	fractol->min.re = mouse_pos.re - (mouse_pos.re - fractol->min.re) / zoom;
	fractol->min.im = mouse_pos.im - (mouse_pos.im - fractol->min.im) / zoom;
	fractol->max.re = mouse_pos.re - (mouse_pos.re - fractol->max.re) / zoom;
	fractol->max.im = mouse_pos.im - (mouse_pos.im - fractol->max.im) / zoom;
	ft_draw_fractol(fractol);
	return (0);
}
