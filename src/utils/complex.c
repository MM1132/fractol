/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:08:08 by rreimann          #+#    #+#             */
/*   Updated: 2024/12/19 17:34:17 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	complex_in_bounds(t_complex *complex, t_fractol_data *fd)
{
	if (fd->fractol_type == FRACTOL_MANDELBROT)
	{
		if (complex->re > 1 || complex->re < -2)
			return (0);
		if (complex->im > 1.5 || complex->im < -1.5)
			return (0);
	}
	else if (fd->fractol_type == FRACTOL_JULIA)
	{
		if (complex->re > 2 || complex->re < -2)
			return (0);
		if (complex->im > 2 || complex->im < -2)
			return (0);
	}
	return (1);
}

uint32_t	keep_squaring(t_complex *start, t_fractol_data *fd)
{
	uint32_t	counter;
	t_complex	new_complex;

	new_complex.im = 0;
	new_complex.re = 0;
	if (fd->fractol_type == FRACTOL_JULIA)
		add_to_complex(&new_complex, start);
	counter = 0;
	while (counter < fd->precision && complex_in_bounds(&new_complex, fd))
	{
		new_complex = square_complex(&new_complex);
		if (fd->fractol_type == FRACTOL_MANDELBROT)
		{
			add_to_complex(&new_complex, start);
		}
		else
			add_to_complex(&new_complex, fd->constant);
		counter++;
	}
	
	return (counter);
}

uint32_t	get_fractol_color(t_complex *start, t_fractol_data *fd)
{
	uint32_t	escape_value;

	escape_value = (double)keep_squaring(start, fd) / fd->precision * 255;
	return (rgba_to_hex(255, 255, 255, escape_value));
}

t_complex	window_to_complex(t_fractol_data *fd, uint32_t x, uint32_t y)
{
	t_complex	complex_number;
	double		half_width;
	double		half_height;
	// static int	counter = 0;

	// if (counter < 5)
	// {
	// 	printf("Camera pos: %f\n", fd->camera->pos->re);
	// 	counter++;
	// }

	half_width = (double)fd->img->width / 2.0;
	half_height = (double)fd->img->height / 2.0;
	complex_number.re = fd->camera->pos->re + ((((double)x) - \
		half_width) / 1000) * fd->camera->zoom;
	complex_number.im = fd->camera->pos->im + ((((double)y) - \
		half_height) / 1000) * fd->camera->zoom;
	return (complex_number);
}
