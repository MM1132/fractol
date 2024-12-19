/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:42:45 by rreimann          #+#    #+#             */
/*   Updated: 2024/12/18 19:52:53 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	*init_complex(void)
{
	t_complex	*complex;

	complex = malloc(sizeof(t_complex));
	if (complex == NULL)
		return (NULL);
	complex->re = 0;
	complex->im = 0;
	return (complex);
}

static void	free_camera(t_camera *camera)
{
	free(camera->pos);
	free(camera);
}

void	free_fractol_data(t_fractol_data *fd)
{
	free_camera(fd->camera);
	free(fd->constant);
	free(fd);
}

static t_camera	*init_camera(void)
{
	t_camera	*camera;

	camera = malloc(sizeof(t_camera));
	if (camera == NULL)
		return (NULL);
	camera->pos = init_complex();
	if (camera->pos == NULL)
	{
		free_camera(camera);
		return (NULL);
	}
	camera->zoom = 10;
	camera->speed = (t_complex) {0.0, 0.0};
	camera->moving = false;
	camera->last_pos = *camera->pos;
	camera->target_pos = *camera->pos;
	camera->last_zoom = camera->zoom;
	camera->target_zoom = camera->zoom;
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
	fd->camera = NULL;
	fd->precision = 10;
	fd->camera = init_camera();
	if (fd->camera == NULL)
		return (free_fractol_data(fd), NULL);
	fd->constant = init_complex();
	if (fd->constant == NULL)
		return (free_fractol_data(fd), NULL);
	if (set_fractol_type(argc, argv, fd) < 0)
		return (free_fractol_data(fd), print_instrcutions(), NULL);
	return (fd);
}
