/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:08:08 by rreimann          #+#    #+#             */
/*   Updated: 2024/12/22 00:39:11 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	complex_in_bounds(t_complex *complex, t_fractol_data *fd)
{
	double	distance_from_center;

	if (fd->fractol_type == FRACTOL_MANDELBROT)
	{
		distance_from_center = sqrt(pow(complex->im, 2) + pow(complex->re, 2));
		if (distance_from_center > 2)
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

int	complex_in_history(t_complex history[100], t_complex complex, int history_size)
{
	int	index;

	index = 0;
	while (index < 100 && index < history_size)
	{
		if (history[index].im == complex.im && history[index].re == complex.re)
		{
			return (1);
		}
		index++;
	}
	if (index < 100)
		history[index] = complex;
	return (0);
}

uint32_t	keep_squaring(t_complex *start, t_fractol_data *fd)
{
	int			counter;
	t_complex	new_complex;
	// t_complex	history[1000];
	// int			history_size;

	// history_size = 0;
	new_complex.im = 0;
	new_complex.re = 0;
	if (fd->fractol_type == FRACTOL_JULIA)
		add_to_complex(&new_complex, start);
	counter = 0;
	while (counter < (double)fd->precision && complex_in_bounds(&new_complex, fd))
	{
		// if (complex_in_history(history, new_complex, history_size))
		// 	return (counter);
		// history_size++;

		new_complex = square_complex(&new_complex);
		if (fd->fractol_type == FRACTOL_MANDELBROT)
		{
			add_to_complex(&new_complex, start);
		}
		else
			add_to_complex(&new_complex, &fd->constant);
		// counter += 1 / sqrt(pow(new_complex.re, 2) + pow(new_complex.im, 2)) + 2;
		counter += 1.2;
	}
	return (counter);
}

uint32_t	get_fractol_color(t_complex *start, t_fractol_data *fd)
{
	uint32_t	escape_value;

	escape_value = (double)keep_squaring(start, fd) / fd->precision * 255;
	return (rgba_to_hex(escape_value, 255 - escape_value, escape_value / 5, 255 - escape_value));
}

t_complex	window_to_complex(t_fractol_data *fd, uint32_t x, uint32_t y)
{
	t_complex	complex_number;
	double		half_width;
	double		half_height;
	uint32_t	smallest_dimension;

	smallest_dimension = get_smallest_dimension(fd);

	half_width = (double)fd->img->width / 2.0;
	half_height = (double)fd->img->height / 2.0;
	complex_number.re = fd->camera.pos.re + ((((double)x) - \
		half_width) / smallest_dimension) / fd->camera.zoom;
	complex_number.im = fd->camera.pos.im + ((((double)y) - \
		half_height) / smallest_dimension) / fd->camera.zoom;
	return (complex_number);
}
