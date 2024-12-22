/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:42:45 by rreimann          #+#    #+#             */
/*   Updated: 2024/12/22 00:03:54 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	free_fractol_data(t_fractol_data *fd)
{
	free(fd);
}

static t_camera	init_camera(void)
{
	t_camera	camera;

	camera.moving = true;
	camera.pos = (t_complex) {0.0, 0.0};
	camera.last_pos = camera.pos;
	camera.target_pos = camera.pos;
	camera.zoom = 1;
	camera.last_zoom = camera.zoom;
	camera.target_zoom = camera.zoom;
	return (camera);
}

t_fractol_data	*init_fractol_data(int argc, char **argv)
{
	t_fractol_data	*fd;

	fd = malloc(sizeof(t_fractol_data));
	if (!fd)
		return (NULL);
	fd->current_row = 0;
	fd->img = NULL;
	fd->mlx = NULL;
	fd->precision = 10;
	fd->keys = (t_keys) { false, false, false, false, false, false };
	fd->camera = init_camera();
	fd->constant = (t_complex) {0.0, 0.0};
	if (set_fractol_type(argc, argv, fd) < 0)
		return (free_fractol_data(fd), print_instrcutions(), NULL);
	return (fd);
}
