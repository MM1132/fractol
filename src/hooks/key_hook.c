/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:53:55 by rreimann          #+#    #+#             */
/*   Updated: 2024/12/15 23:55:05 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	key_hook(mlx_key_data_t keydata, void *fractol_data)
{
	t_fractol_data	*fd;

	fd = (t_fractol_data *)fractol_data;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(fd->mlx);
	else if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_W)
			fd->camera->pos->im -= fd->camera->zoom / 50;
		else if (keydata.key == MLX_KEY_A)
			fd->camera->pos->re -= fd->camera->zoom / 50;
		else if (keydata.key == MLX_KEY_S)
			fd->camera->pos->im += fd->camera->zoom / 50;
		else if (keydata.key == MLX_KEY_D)
			fd->camera->pos->re += fd->camera->zoom / 50;
		else if (keydata.key == MLX_KEY_Q)
		{
			if (fd->precision > 10)
				fd->precision -= 10;
		}
		else if (keydata.key == MLX_KEY_E)
			fd->precision += 10;
		put_fractol(fd);
	}
}
