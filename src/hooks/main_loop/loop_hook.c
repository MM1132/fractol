/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:13:47 by rreimann          #+#    #+#             */
/*   Updated: 2024/12/21 18:17:28 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	reset_image(t_fractol_data *fd)
{
	fd->img->instances[0].x = 0;
	fd->img->instances[0].y = 0;
	
	mlx_resize_image(fd->img, fd->mlx->width, fd->mlx->height);
}

void	shift_image(t_fractol_data *fd)
{
	t_complex	diff;
	double		pixel_diff_x;
	double		pixel_diff_y;
	uint32_t	smallest_dimension;

	smallest_dimension = get_smallest_dimension(fd);

	diff.re = fd->camera.last_pos.re - fd->camera.pos.re;
	diff.im = fd->camera.last_pos.im - fd->camera.pos.im;
	pixel_diff_x = (diff.re * smallest_dimension) / fd->camera.zoom;
	pixel_diff_y = (diff.im * smallest_dimension) / fd->camera.zoom;

	fd->img->instances[0].x = (int)pixel_diff_x;
	fd->img->instances[0].y = (int)pixel_diff_y;
}

void	loop_hook(void	*fracol_data)
{
	static int frame_count = 0;
	static double last_time = 0;
	t_fractol_data	*fd;
	t_complex		pos_diff;
	double			zoom_diff;

	fd = (t_fractol_data *)fracol_data;

	//! WE DON'T KNOW HOW THIS WORKS YET
	frame_count++;
	double current_time = mlx_get_time();
	if (current_time - last_time >= 1.0) {
		printf("FPS: %d\n", frame_count);
		frame_count = 0;
		last_time = current_time;
	}

	pos_diff.re = fd->camera.target_pos.re - fd->camera.pos.re;
	pos_diff.im = fd->camera.target_pos.im - fd->camera.pos.im;

	zoom_diff = fd->camera.target_zoom - fd->camera.zoom;

	handle_arrow_movement(fd);
	
	if (fabs(pos_diff.re) > 0.02 * fd->camera.zoom || fabs(pos_diff.im) > 0.02 * fd->camera.zoom || fabs(zoom_diff) > 0.02 * fd->camera.zoom)
	{
		if (fd->camera.moving == false)
		{
			fd->camera.moving = true;
			fd->camera.last_pos = fd->camera.pos;
			fd->camera.last_zoom = fd->camera.zoom;
			fd->last_image_width = fd->img->width;
			fd->last_image_height = fd->img->height;
		}

		fd->camera.pos.re += pos_diff.re * 0.02;
		fd->camera.pos.im += pos_diff.im * 0.02;
		fd->camera.zoom += zoom_diff * 0.1;
		
		shift_image(fd);
	}
	else
	{
		if (fd->camera.moving == true)
		{
			fd->camera.moving = false;
			fd->camera.target_pos = fd->camera.pos;
			fd->camera.target_zoom = fd->camera.zoom;

			reset_image(fd);
			put_fractol(fd);
		}
	}

	if (fabs(fd->camera.speed.re) > 0.01 || fabs(fd->camera.speed.im) > 0.01)
	{
		fd->camera.pos.re += fd->camera.speed.re;
		fd->camera.pos.im += fd->camera.speed.im;

		fd->camera.speed.im *= 0.93;
		fd->camera.speed.re *= 0.93;

		shift_image(fd);
	}
}
