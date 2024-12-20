/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:08:08 by rreimann          #+#    #+#             */
/*   Updated: 2024/12/20 02:08:31 by rreimann         ###   ########.fr       */
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
	t_complex	history[100];
	int			history_size;

	history_size = 0;
	new_complex.im = 0;
	new_complex.re = 0;
	if (fd->fractol_type == FRACTOL_JULIA)
		add_to_complex(&new_complex, start);
	counter = 0;
	while (counter < (double)fd->precision && complex_in_bounds(&new_complex, fd))
	{
		if (complex_in_history(history, new_complex, history_size))
		{
			history_size++;
			return (counter);
		}

		new_complex = square_complex(&new_complex);
		if (fd->fractol_type == FRACTOL_MANDELBROT)
		{
			add_to_complex(&new_complex, start);
		}
		else
			add_to_complex(&new_complex, fd->constant);
		//counter += 1 / sqrt(pow(new_complex.re, 2) + pow(new_complex.im, 2));
		counter++;
	}
	return (counter);
}

uint32_t	get_fractol_color(t_complex *start, t_fractol_data *fd)
{
	uint32_t	escape_value;
	static uint32_t	color_changer;

	if (color_changer < 255)
		color_changer++;
	else
		color_changer = 0;

	escape_value = (double)keep_squaring(start, fd) / fd->precision * 255;
	return (rgba_to_hex(escape_value, 255 - escape_value, escape_value / (color_changer % 4 + 1) * 5, 255 - escape_value));
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
