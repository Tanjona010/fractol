/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: traveloa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:00:34 by traveloa          #+#    #+#             */
/*   Updated: 2024/06/11 08:39:18 by traveloa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render_img(t_var *var)
{
	mlx_destroy_image(var->mlx_ptr, var->img);
	var->img = mlx_new_image(var->mlx_ptr, WIDTH, LENGTH);
	var->addr = mlx_get_data_addr(var->img, &var->bpp, &var->line_length,
			&var->endian);
	put_pixel(var);
	mlx_put_image_to_window(var->mlx_ptr, var->win, var->img, 0, 0);
}

int	ft_colorshift(t_var *var)
{
	if (var->col_index == 3)
		var->col_index = 0;
	else
		var->col_index += 1;
	var->color = var->color_list[var->col_index];
	render_img(var);
	return (0);
}

void	scale(t_var *var, float x, float y)
{
	var->n.reel = var->zoom * ((NEW_MAX - NEW_MIN) * (x)) / (WIDTH) + NEW_MIN;
	var->n.img = var-> zoom * ((NEW_MIN - NEW_MAX) * (y)) / (LENGTH) + NEW_MAX;
	var->n.reel += var->x_mouv;
	var->n.img += var->y_mouv;
}

void	fractal(t_var *var, int iter, t_color *color)
{
	if (var->fractal == 1)
		*color = is_mandelbrot(var->n, iter);
	else if (var->fractal == 2)
	{
		var->c.reel = 0;
		var->c.img = 0.8;
		*color = is_julia(var->n, iter, var->c);
	}
	else if (var->fractal == 3)
		*color = burning_ship(var->n, iter);
	else if (var->fractal == 4)
		*color = is_julia(var->n, iter, var->c);
}

void	put_pixel(t_var *var)
{
	float		x;
	float		y;
	char		*tmp;
	t_color		color;

	y = 0;
	color.color = 0;
	while (y < LENGTH)
	{
		x = 0;
		while (x < WIDTH)
		{
			scale(var, x, y);
			tmp = var->addr + ((int)y * var->line_length)
				+ ((int)x * (var->bpp / 8));
			fractal(var, ITER, &color);
			color.color = (var->color) * (color.color) / ITER + var->color;
			if (color.ret == 0)
				*(unsigned int *)tmp = color.color;
			x++;
		}
		y++;
	}
}
