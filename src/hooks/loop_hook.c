/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:13:47 by rreimann          #+#    #+#             */
/*   Updated: 2024/12/19 17:58:49 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	reset_image(t_fractol_data *fd)
{
	fd->img->instances[0].x = 0;
	fd->img->instances[0].y = 0;
}

void	shift_image(t_fractol_data *fd)
{
	t_complex	diff;
	double	pixel_diff_x;
	double	pixel_diff_y;

	diff.re = fd->camera->last_pos.re - fd->camera->pos->re;
	diff.im = fd->camera->last_pos.im - fd->camera->pos->im;
	pixel_diff_x = (diff.re * 1000) / fd->camera->zoom;
	pixel_diff_y = (diff.im * 1000) / fd->camera->zoom;

	fd->img->instances[0].x = (int)pixel_diff_x;
	fd->img->instances[0].y = (int)pixel_diff_y;

	// ZOOM
	// double zoom_diff = fd->camera->last_zoom - fd->camera->zoom;
	// uint32_t new_width = (uint32_t)(fd->img->width + 1);
	// uint32_t new_height = (uint32_t)(fd->img->height + 1);

	// mlx_resize_image(fd->img, new_width, new_height);
}

void	loop_hook(void	*fracol_data)
{
	t_fractol_data	*fd;
	t_complex		pos_diff;
	double			zoom_diff;

	fd = (t_fractol_data *)fracol_data;

	pos_diff.re = fd->camera->target_pos.re - fd->camera->pos->re;
	pos_diff.im = fd->camera->target_pos.im - fd->camera->pos->im;

	zoom_diff = fd->camera->target_zoom - fd->camera->zoom;
	
	if (fabs(pos_diff.re) > 0.01 * fd->camera->zoom || fabs(pos_diff.im) > 0.01 * fd->camera->zoom || fabs(zoom_diff) > 0.01 * fd->camera->zoom)
	{
		if (fd->camera->moving == false)
		{
			fd->camera->moving = true;
			fd->camera->last_pos = *fd->camera->pos;
			fd->camera->last_zoom = fd->camera->zoom;
		}

		fd->camera->pos->re += pos_diff.re * 0.1;
		fd->camera->pos->im += pos_diff.im * 0.1;
		fd->camera->zoom += zoom_diff * 0.1;
		
		shift_image(fd);
	}
	else
	{
		if (fd->camera->moving == true)
		{
			fd->camera->moving = false;
			fd->camera->target_pos = *fd->camera->pos;
			fd->camera->target_zoom = fd->camera->zoom;

			reset_image(fd);
			put_fractol(fd);
		}
	}





	fd = (t_fractol_data *)fracol_data;
	if (fabs(fd->camera->speed.re) > 0.01 || fabs(fd->camera->speed.im) > 0.01)
	{

		fd->camera->pos->re += fd->camera->speed.re;
		fd->camera->pos->im += fd->camera->speed.im;

		fd->camera->speed.im *= 0.93;
		fd->camera->speed.re *= 0.93;

		shift_image(fd);
	}
}
