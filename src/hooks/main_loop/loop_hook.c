/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:13:47 by rreimann          #+#    #+#             */
/*   Updated: 2024/12/22 01:00:47 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	loop_hook(void	*fracol_data)
{
	static int		frame_count;
	static double	last_time;
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

	// Change target position
	handle_arrow_movement(fd);
	handle_zoom(fd);

	// The distance to the target position
	pos_diff.re = fd->camera.target_pos.re - fd->camera.pos.re;
	pos_diff.im = fd->camera.target_pos.im - fd->camera.pos.im;

	// The zoom distance to the target zoom
	zoom_diff = fd->camera.target_zoom - fd->camera.zoom;

	if (zoom_diff > 0.02)
		printf("Zoom diff: %f\n", zoom_diff);
	
	if (fabs(pos_diff.re) > 0.02 / fd->camera.zoom || fabs(pos_diff.im) > 0.02 / fd->camera.zoom || fabs(zoom_diff) > 0.02 / fd->camera.zoom)
	{
		if (fd->camera.moving == false)
		{
			fd->camera.moving = true;
			fd->camera.last_pos = fd->camera.pos;
			fd->camera.last_zoom = fd->camera.zoom;
			fd->last_image_width = fd->img->width;
			fd->last_image_height = fd->img->height;
		}

		// Change the camera's position closer to the target
		fd->camera.pos.re += pos_diff.re * 0.02;
		fd->camera.pos.im += pos_diff.im * 0.02;

		// And change the zoom closer to the target
		fd->camera.zoom += zoom_diff * 0.02;
		
		// Now we are shifting the image
		translate_image(fd);
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
}
