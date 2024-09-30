/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahne <cdahne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:36:26 by cdahne            #+#    #+#             */
/*   Updated: 2024/09/11 18:37:44 by cdahne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_free_all(t_fractol *fractol)
{
	mlx_destroy_window(fractol->mlx, fractol->win);
	mlx_destroy_image(fractol->mlx, fractol->img->img);
	mlx_destroy_display(fractol->mlx);
	free(fractol->img);
	free(fractol->mlx);
	free(fractol);
}

void	terminate(char *errmsg)
{
	perror(errmsg);
	exit(0);
}
