/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 19:01:56 by rreimann          #+#    #+#             */
/*   Updated: 2024/12/18 19:48:23 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_mandelbrot_row(t_fractol_data *fd)
{
	uint32_t	index_x;
	t_complex	complex;
	uint32_t	color;

	index_x = 0;
	while (index_x < fd->img->width)
	{
		complex = window_to_complex(fd, index_x, fd->current_row);
		color = get_fractol_color(&complex, fd);
		mlx_put_pixel(fd->img, index_x, fd->current_row, color);
		index_x++;
	}
	fd->current_row++;
	if (fd->current_row >= fd->img->height)
	{
		fd->current_row = 0;
	}
}

void	put_fractol(t_fractol_data *fd)
{
	uint32_t	index_y;
	uint32_t	index_x;
	uint32_t	color;
	t_complex	complex;
	static int	counter;

	counter++;
	printf("Put Fractol %d\n", counter);

	index_y = 0;
	while (index_y < fd->img->height)
	{
		index_x = 0;
		while (index_x < fd->img->width)
		{
			complex = window_to_complex(fd, index_x, index_y);
			color = get_fractol_color(&complex, fd);
			mlx_put_pixel(fd->img, index_x, index_y, color);
			index_x++;
		}
		index_y++;
	}
}
