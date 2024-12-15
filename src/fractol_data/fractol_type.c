/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:42:45 by rreimann          #+#    #+#             */
/*   Updated: 2024/12/14 19:59:24 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_pos	*init_pos()
{
	t_pos	*pos;

	pos = malloc(sizeof(t_pos));
	if (pos == NULL)
		return (NULL);
	pos->x = 0;
	pos->y = 0;
	return (pos);
}

static void	free_camera(t_camera *camera)
{
	free(camera->pos);
	free(camera);
}

void	free_fractol_data(t_fractol_data	*fd)
{
	free_camera(fd->camera);
	free(fd);
}

static t_camera	*init_camera()
{
	t_camera	*camera;

	camera = malloc(sizeof(t_camera));
	if (camera == NULL)
		return (NULL);
	camera->pos = init_pos();
	if (camera->pos == NULL)
	{
		free_camera(camera);
		return (NULL);
	}
	camera->zoom = 0;
	return (camera);
}

t_fractol_data	*init_fractol_data()
{
	t_fractol_data	*fd;

	fd = malloc(sizeof(t_fractol_data));
	if (!fd)
		return (NULL);
	fd->img = NULL;
	fd->mlx = NULL;
	fd->camera = NULL;
	fd->camera = init_camera();
	if (fd->camera == NULL)
		return (free_fractol_data(fd), NULL);
	return (fd);
}
