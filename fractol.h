/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: traveloa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:27:40 by traveloa          #+#    #+#             */
/*   Updated: 2024/06/11 08:40:09 by traveloa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx_linux/mlx.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# define NEW_MIN -2
# define NEW_MAX 2
# define WIDTH 800
# define LENGTH 800
# define ITER 500 

typedef struct s_number
{
	float		img;
	float		reel;
}			t_number;

typedef struct s_var
{
	void			*mlx_ptr;
	void			*win;
	void			*img;
	char			*addr;
	int				bpp;
	int				line_length;
	int				endian;
	t_number		n;
	float			x_mouv;
	float			y_mouv;
	float			zoom;
	int				fractal;
	t_number		c;
	int				color_list[4];
	int				col_index;
	int				color;
}				t_var;

typedef struct s_color
{
	int	color;
	int	ret;
}				t_color;

float	ft_atoif(const char *nptr);
t_color	burning_ship(t_number n, int iter);
t_color	is_mandelbrot(t_number n, int iter);
void	put_pixel(t_var *var);
t_color	is_julia(t_number n, int iter, t_number c);
int		ft_close(t_var *var);
void	render_img(t_var *var);
int		key_handler(int keymap, t_var *var);
int		mouse_handler(int button, int x, int y, t_var *var);
void	handle_key(t_var *var);
void	check_input(char **argv, t_var *var, int argc);
void	error_exit(void);
int		ft_colorshift(t_var *var);
void	scale(t_var *var, float x, float y);
void	fractal(t_var *var, int iter, t_color *color);
#endif
