/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: traveloa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 08:30:30 by traveloa          #+#    #+#             */
/*   Updated: 2024/06/11 08:32:21 by traveloa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_exit(void)
{
	ft_putstr_fd("\033[1;31m Error \033[0m\n", 2);
	ft_putstr_fd("Usage : ./fractol [fractal name]\n", 2);
	ft_putstr_fd("\t./fractol j [reel] [img]\n", 2);
	ft_putstr_fd("\033[0;34m Fractal name : \033[0m \n", 2);
	ft_putstr_fd("- mandelbrot -> m\n", 2);
	ft_putstr_fd("- julia -> j\n", 2);
	ft_putstr_fd("- burning ship -> bs\n", 2);
	exit (0);
}

void	check_input(char **argv, t_var *var, int argc)
{
	if (argc == 2)
	{
		if (ft_strncmp(argv[1], "m", 1) == 0 && !argv[1][1])
			var->fractal = 1;
		else if (ft_strncmp(argv[1], "j", 5) == 0 && !argv[1][1])
			var->fractal = 2;
		else if (ft_strncmp(argv[1], "bs", 2) == 0 && !argv[1][2])
			var->fractal = 3;
		else
			error_exit();
	}
	else if (argc == 4)
	{
		if (ft_strncmp(argv[1], "j", 1) == 0 && !argv[1][1])
		{
			var->fractal = 4;
			var->c.reel = ft_atoif(argv[2]);
			var->c.img = ft_atoif(argv[3]);
		}
		else
			error_exit();
	}
	else
		error_exit();
}
