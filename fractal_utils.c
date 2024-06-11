/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: traveloa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:58:54 by traveloa          #+#    #+#             */
/*   Updated: 2024/06/04 15:50:31 by traveloa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color	is_mandelbrot(t_number n, int iter)
{
	t_number	z;
	int			i;
	t_number	tmp;
	t_color		color;

	z.img = 0.0;
	z.reel = 0.0;
	i = 0;
	while (i < iter && (z.img * z.img) + (z.reel * z.reel) < 4)
	{
		tmp.reel = z.reel;
		z.reel = (z.reel * z.reel) - (z.img * z.img) + n.reel;
		z.img = 2 * tmp.reel * z.img + n.img;
		i += 1;
	}
	if (i == iter)
	{
		color.ret = 1;
		return (color);
	}
	color.ret = 0;
	color.color = i;
	return (color);
}

t_color	is_julia(t_number n, int iter, t_number z)
{
	int			i;
	t_number	tmp;
	t_color		color;

	i = 0;
	while (i < iter && (n.img * n.img) + (n.reel * n.reel) < 4)
	{
		tmp.reel = n.reel;
		n.reel = (n.reel * n.reel) - (n.img * n.img) + z.reel;
		n.img = 2 * tmp.reel * n.img + z.img;
		i += 1;
	}
	if (i == iter)
	{
		color.ret = 1;
		return (color);
	}
	color.ret = 0;
	color.color = i;
	return (color);
}

static void	abs_value(t_number *z)
{
	if (z->reel < 0)
		z->reel *= -1;
	if (z->img < 0)
		z->img *= -1;
}

t_color	burning_ship(t_number n, int iter)
{
	t_number	z;
	int			i;
	t_number	tmp;
	t_color		color;

	z.img = 0.0;
	z.reel = 0.0;
	i = 0;
	while (i < iter && (z.img * z.img) + (z.reel * z.reel) < 4)
	{
		tmp.reel = z.reel;
		z.reel = (z.reel * z.reel) - (z.img * z.img) - n.reel;
		z.img = 2 * tmp.reel * z.img - n.img;
		i += 1;
		abs_value(&z);
	}
	if (i == iter)
	{
		color.ret = 1;
		return (color);
	}
	color.ret = 0;
	color.color = i;
	return (color);
}
