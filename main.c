/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: traveloa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:04:19 by traveloa          #+#    #+#             */
/*   Updated: 2024/06/11 08:39:24 by traveloa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractal(t_var *var)
{
	var->col_index = 0;
	var->color_list[0] = 0x0001FFFF;
	var->color_list[1] = 0xF0FFFF01;
	var->color_list[2] = 0x05A57C00;
	var->color_list[3] = 0xF9FF0101;
	var->color = var->color_list[var->col_index];
	var->zoom = 1;
	var->x_mouv = 0;
	var->y_mouv = 0;
	var->mlx_ptr = mlx_init();
	var->win = mlx_new_window(var->mlx_ptr, WIDTH, LENGTH, "Fractol");
	var->img = mlx_new_image(var->mlx_ptr, WIDTH, LENGTH);
	var->addr = mlx_get_data_addr(var->img, &var->bpp, &var->line_length,
			&var->endian);
}

int	main(int argc, char *argv[])
{
	t_var		var;

	check_input(argv, &var, argc);
	init_fractal(&var);
	put_pixel(&var);
	mlx_put_image_to_window(var.mlx_ptr, var.win, var.img, 0, 0);
	handle_key(&var);
	mlx_loop(var.mlx_ptr);
}
