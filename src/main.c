/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:45:58 by rreimann          #+#    #+#             */
/*   Updated: 2024/12/14 17:24:41 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	hook_function(mlx_key_data_t keydata, void *fractol_data)
{
	t_fractol_data	*fd;

	fd = (t_fractol_data *)fractol_data;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_close_window(fd->mlx);
	}
}

int32_t	main(void)
{
	t_fractol_data	*fractol_data;

	fractol_data = malloc(sizeof(t_fractol_data));
	mlx_set_setting(MLX_MAXIMIZED, true);
	fractol_data->mlx = mlx_init(1000, 600, "Robert's Awesome Fractol", true);
	if (!fractol_data->mlx)
		exit(EXIT_FAILURE);
	fractol_data->img = mlx_new_image(fractol_data->mlx,
			fractol_data->mlx->width,
			fractol_data->mlx->height);
	mlx_image_to_window(fractol_data->mlx, fractol_data->img, 0, 0);
	mlx_key_hook(fractol_data->mlx, &hook_function, fractol_data);
	ft_printf("Main loop started\n");
	mlx_loop(fractol_data->mlx);
	mlx_terminate(fractol_data->mlx);
	free(fractol_data);
	return (EXIT_SUCCESS);
}
