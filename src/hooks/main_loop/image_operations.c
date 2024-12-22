/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 23:31:26 by rreimann          #+#    #+#             */
/*   Updated: 2024/12/22 01:02:12 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	reset_image(t_fractol_data *fd)
{
	fd->img->instances[0].x = 0;
	fd->img->instances[0].y = 0;
	
	mlx_resize_image(fd->img, fd->mlx->width, fd->mlx->height);
}

void	translate_image(t_fractol_data *fd)
{
	t_complex	diff;
	double		pixel_diff_x;
	double		pixel_diff_y;
	uint32_t	smallest_dimension;
	double		zoom_diff;
	uint32_t	new_width;
	uint32_t	new_height;
	uint32_t	width_diff;
	uint32_t	height_diff;

	smallest_dimension = get_smallest_dimension(fd);

	diff.re = fd->camera.last_pos.re - fd->camera.pos.re;
	diff.im = fd->camera.last_pos.im - fd->camera.pos.im;
	pixel_diff_x = (diff.re * smallest_dimension) * fd->camera.zoom;
	pixel_diff_y = (diff.im * smallest_dimension) * fd->camera.zoom;

	fd->img->instances[0].x = (int)pixel_diff_x;
	fd->img->instances[0].y = (int)pixel_diff_y;

	// Zoom stuff
	// Calculate how many times current zoom is greater than the last zoom
	zoom_diff = fd->camera.zoom / fd->camera.last_zoom;

	new_width = fd->last_image_width * zoom_diff;
	new_height = fd->last_image_height * zoom_diff;

	
	// How many more pixels we have for the width and for the height
	width_diff = fd->last_image_width - new_width;
	height_diff = fd->last_image_height - new_height;

	fd->img->instances[0].x += width_diff / 2;
	fd->img->instances[0].y += height_diff / 2;
	
	mlx_resize_image(fd->img, new_width, new_height);
}
