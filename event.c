/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: traveloa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 08:32:53 by traveloa          #+#    #+#             */
/*   Updated: 2024/06/11 08:43:30 by traveloa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_handler(int keymap, t_var *var)
{
	if (keymap == 65307)
		ft_close(var);
	else if (keymap == 65506)
		ft_colorshift(var);
	else if (keymap == 65363)
	{
		var->x_mouv -= 0.5 * var->zoom;
		render_img(var);
	}
	else if (keymap == 65361)
	{
		var->x_mouv += 0.5 * var->zoom;
		render_img(var);
	}
	else if (keymap == 65364)
	{
		var->y_mouv += 0.5 * var->zoom;
		render_img(var);
	}
	else if (keymap == 65362)
	{
		var->y_mouv -= 0.5 * var->zoom;
		render_img(var);
	}
	return (0);
}

void	mouse_pos(t_var *var, int x, int y)
{
	t_number	tmp;

	tmp.reel = ((NEW_MAX - NEW_MIN) * ((float)x)) / (WIDTH) + NEW_MIN;
	tmp.img = ((NEW_MIN - NEW_MAX) * ((float)y)) / (LENGTH) + NEW_MAX;
	var->x_mouv += var->zoom * tmp.reel / 2;
	var->y_mouv += var->zoom * tmp.img / 2;
}

int	mouse_handler(int button, int x, int y, t_var *var)
{
	if (button == 5)
	{
		mouse_pos(var, x, y);
		var->zoom *= 1.2;
		mlx_destroy_image(var->mlx_ptr, var->img);
		var->img = mlx_new_image(var->mlx_ptr, WIDTH, LENGTH);
		var->addr = mlx_get_data_addr(var->img, &var->bpp, &var->line_length,
				&var->endian);
		put_pixel(var);
		mlx_put_image_to_window(var->mlx_ptr, var->win, var->img, 0, 0);
	}
	else if (button == 4)
	{
		mouse_pos(var, x, y);
		var->zoom *= 0.8;
		mlx_destroy_image(var->mlx_ptr, var->img);
		var->img = mlx_new_image(var->mlx_ptr, WIDTH, LENGTH);
		var->addr = mlx_get_data_addr(var->img, &var->bpp, &var->line_length,
				&var->endian);
		put_pixel(var);
		mlx_put_image_to_window(var->mlx_ptr, var->win, var->img, 0, 0);
	}
	return (0);
}

void	handle_key(t_var *var)
{
	mlx_hook(var->win, 2, 1l << 0, key_handler, var);
	mlx_mouse_hook(var->win, mouse_handler, var);
	mlx_hook(var->win, 17, 0, ft_close, var);
}

int	ft_close(t_var *var)
{
	mlx_destroy_image(var->mlx_ptr, var->img);
	mlx_destroy_window(var->mlx_ptr, var->win);
	mlx_destroy_display(var->mlx_ptr);
	free(var->mlx_ptr);
	exit(1);
	return (0);
}
