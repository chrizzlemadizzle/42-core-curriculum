/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahne <cdahne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:31:45 by cdahne            #+#    #+#             */
/*   Updated: 2024/09/12 10:53:59 by cdahne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	init_complex(double re, double im)
{
	t_complex	complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}

t_complex	ft_init_param(char **param)
{
	if (ft_strcmp(param[1], "Julia") == 0 || \
		ft_strcmp(param[1], "Nova") == 0)
		return (init_complex(ft_atof(param[2]), ft_atof(param[3])));
	return (init_complex(0, 0));
}

t_img	*ft_init_image(t_fractol *fractol)
{
	t_img	*img;

	img = (t_img *) malloc (sizeof(t_img));
	if (!img)
	{
		ft_free_all(fractol);
		terminate("Error: Unable to initialize Image.");
	}
	img->img = mlx_new_image(fractol->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->size_line, &img->endian);
	return (img);
}

t_fractol	*init_fractol(void *mlx, char **param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *) malloc (sizeof(t_fractol));
	if (!fractol)
		terminate("Error: Unable to initialize fractol.");
	fractol->mlx = mlx;
	fractol->win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, param[1]);
	fractol->img = ft_init_image(fractol);
	fractol->min.re = -2.0;
	fractol->max.re = 2.0;
	fractol->min.im = -1 * (fractol->max.re - fractol->min.re) * \
		WINDOW_HEIGHT / WINDOW_WIDTH / 2;
	fractol->max.im = (fractol->max.re - fractol->min.re) * \
		WINDOW_HEIGHT / WINDOW_WIDTH / 2;
	fractol->k = ft_init_param(param);
	fractol->name = param[1];
	mlx_do_key_autorepeaton(fractol->mlx);
	mlx_hook(fractol->win, 2, 1L << 0, &key_handler, fractol);
	mlx_hook(fractol->win, 4, 1L << 2, &mouse_handler, fractol);
	mlx_hook(fractol->win, 17, 0, &close_window, fractol);
	return (fractol);
}
