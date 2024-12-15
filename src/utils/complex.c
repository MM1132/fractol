/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:08:08 by rreimann          #+#    #+#             */
/*   Updated: 2024/12/15 22:09:33 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	*square_complex(t_complex *c)
{
	t_complex	*squared_complex;

	squared_complex = malloc(sizeof(t_complex));
	if (squared_complex == NULL)
		return (NULL);
	squared_complex->im = 0;
	squared_complex->re = 0;
	// Calculation
	squared_complex->re += c->re * c->re;
	squared_complex->im += c->im * c->re * 2;
	squared_complex->re -= c->im * c->im;
	return (squared_complex);
}

int	complex_in_bounds(t_complex *complex)
{
	if (complex->re > 2 || complex->re < -2)
		return (0);
	if (complex->im > 2 || complex->im < -2)
		return (0);
	return (1);
}

uint32_t	keep_squaring(t_complex *start, uint32_t limit)
{
	uint32_t	counter;
	t_complex	*new_complex;
	t_complex	*tmp;

	new_complex = malloc(sizeof(t_complex));
	if (new_complex == NULL)
		return (0);
	new_complex->im = start->im;
	new_complex->re = start->re;
	counter = 0;
	while (counter < limit && complex_in_bounds(new_complex))
	{
		tmp = new_complex;
		new_complex = square_complex(new_complex);
		if (new_complex == NULL)
			return (free(tmp), 0);
		new_complex->im += start->im;
		new_complex->re += start->re;
		free(tmp);
		counter++;
	}
	free(new_complex);
	return (counter);
}

uint32_t	get_mandlebrot_color(t_complex *start, uint32_t precision)
{
	uint32_t	escape_value;

	escape_value = (double)keep_squaring(start, precision) / precision * 255;
	return (rgba_to_hex(escape_value + 100, 255 - escape_value / 2, 255 - escape_value / 4, 255));
}

#include <stdio.h>

t_complex	*window_to_complex(t_fractol_data *fd, uint32_t x, uint32_t y)
{
	t_complex	*complex_number;
	double		half_width;
	double		half_height;

	half_width = (double)fd->img->width / 2.0;
	half_height = (double)fd->img->height / 2.0;
	complex_number = malloc(sizeof(t_complex));
	if (complex_number == NULL)
		return (NULL);
	// printf("Width: %f\n", half_width);
	complex_number->re = fd->camera->pos->re + ((((double)x) - half_width) / 1000) * fd->camera->zoom;
	complex_number->im = fd->camera->pos->im + ((((double)y) - half_height) / 1000) * fd->camera->zoom;
	// complex_number->re = ((((double)x) - half_width + fd->camera->pos->x) / half_width) * fd->camera->zoom;
	// complex_number->im = ((((double)y) - half_height + fd->camera->pos->y) / half_height) * fd->camera->zoom;
	return (complex_number);
}
