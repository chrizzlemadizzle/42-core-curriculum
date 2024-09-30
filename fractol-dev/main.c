/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahne <cdahne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 16:41:59 by cdahne            #+#    #+#             */
/*   Updated: 2024/09/12 10:54:01 by cdahne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_put_pixel(t_img *img, int x, int y, t_color color)
{
	char	*dst;

	dst = img->addr + y * img->size_line + x * (img->bits_per_pixel / 8);
	dst[3] = (char)color.a;
	dst[2] = (char)color.r;
	dst[1] = (char)color.g;
	dst[0] = (char)color.b;
}

void	ft_draw_fractol(t_fractol *fractol)
{
	int			x;
	int			y;
	t_color		color;

	fractol->factor.re = (fractol->max.re - fractol->min.re) / \
		(WINDOW_WIDTH - 1);
	fractol->factor.im = (fractol->max.im - fractol->min.im) / \
		(WINDOW_HEIGHT - 1);
	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		fractol->c.im = fractol->min.im + y * fractol->factor.im;
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			fractol->c.re = fractol->min.re + x * fractol->factor.re;
			color = ft_choose_fractol(fractol);
			ft_put_pixel(fractol->img, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(\
		fractol->mlx, fractol->win, fractol->img->img, 0, 0);
}

void	ft_check_args(int argc, char **argv)
{
	if (argc < 2)
		terminate("Not enough parameters!\
			\nChoose from 'Mandelbrot', 'Julia', 'Nova'.\n");
	if (ft_strcmp(argv[1], "Mandelbrot") != 0 && ft_strcmp(argv[1], "Julia") \
		!= 0 && ft_strcmp(argv[1], "Nova") != 0)
		terminate("Please choose between Mandelbrot, Julia or Nova!");
	if (ft_strcmp(argv[1], "Julia") == 0)
	{
		if (argc < 4)
			terminate("You chose the Julia set.\
				\nPlease enter parameters as starting conditions.\
				\nFor example:\
				\nJulia 0.355 0.355\
				\nJulia 0.285 0.01\
				\nJulia -0.8 0.156");
	}
	if (ft_strcmp(argv[1], "Nova") == 0)
	{
		if (argc < 4)
			terminate("You chose the Nova set.\
				\nPlease enter parameters as starting conditions.\
				\nYou may start with: Nova 0 0\
				\nand tinker with small value changes.");
	}
}

int	main(int argc, char **argv)
{
	t_fractol	*fractol;
	void		*mlx;

	ft_check_args(argc, argv);
	mlx = mlx_init();
	fractol = init_fractol(mlx, argv);
	ft_draw_fractol(fractol);
	mlx_loop(fractol->mlx);
	return (0);
}
