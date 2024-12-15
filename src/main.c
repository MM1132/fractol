/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:45:58 by rreimann          #+#    #+#             */
/*   Updated: 2024/12/15 22:18:05 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int32_t	main(void)
{
	t_fractol_data	*fractol_data;

	fractol_data = init_fractol_data();
	if (!fractol_data)
		exit(EXIT_FAILURE);
	// mlx_set_setting(MLX_MAXIMIZED, true);
	fractol_data->mlx = mlx_init(500, 500, "Robert's Awesome Fractol", true);
	if (!fractol_data->mlx)
		exit(EXIT_FAILURE);
	fractol_data->img = mlx_new_image(fractol_data->mlx,
			fractol_data->mlx->width,
			fractol_data->mlx->height);
	mlx_image_to_window(fractol_data->mlx, fractol_data->img, 0, 0);
	// put_mandelbrot(fractol_data);
	mlx_key_hook(fractol_data->mlx, &key_hook, fractol_data);
	// mlx_loop_hook(fractol_data->mlx, &loop_hook, fractol_data);
	// mlx_resize_hook(fractol_data->mlx, &resize_hook, fractol_data);
	// mlx_mouse_hook(fractol_data->mlx, &mouse_hook, fractol_data);
	// mlx_cursor_hook(fractol_data->mlx, &cursor_hook, fractol_data);
	mlx_scroll_hook(fractol_data->mlx, &scroll_hook, fractol_data);
	mlx_loop(fractol_data->mlx);
	mlx_terminate(fractol_data->mlx);
	free_fractol_data(fractol_data);
	return (EXIT_SUCCESS);
}
