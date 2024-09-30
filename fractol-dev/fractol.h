/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahne <cdahne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 16:42:17 by cdahne            #+#    #+#             */
/*   Updated: 2024/09/12 16:41:33 by cdahne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <errno.h>
# define WINDOW_HEIGHT 768
# define WINDOW_WIDTH 1024
# define MAX_ITERATIONS 128

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_color
{
	uint8_t	a;
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
}	t_color;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_fractol
{
	void		*mlx;
	void		*win;
	t_img		*img;
	t_complex	min;
	t_complex	max;
	t_complex	factor;
	t_complex	c;
	t_complex	k;
	char		*name;
}	t_fractol;

t_color		ft_make_argb(int a, int r, int g, int b);
void		ft_put_pixel(t_img *img, int x, int y, t_color color);
int			key_handler(int keycode, t_fractol *fractol);
int			mouse_handler(int mousecode, int x, int y, t_fractol *fractol);
t_color		ft_julia_escapetime(t_fractol *fractol);
t_color		ft_mandel_escapetime(t_fractol *fractol);
t_color		ft_nova_escapetime(t_fractol *fractol);
void		ft_draw_fractol(t_fractol *fractol);
t_complex	init_complex(double re, double im);
t_fractol	*init_fractol(void *mlx, char **param);
t_complex	ft_init_param(char **param);
void		terminate(char *errmsg);
t_color		ft_color_gradient(double t);
int			close_window(t_fractol *fractol);
t_color		ft_choose_fractol(t_fractol *fractol);
double		ft_smooth_iteration(int i, t_complex z);
void		ft_free_all(t_fractol *fractol);
#endif
