/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:45:58 by rreimann          #+#    #+#             */
/*   Updated: 2024/12/15 18:13:41 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	scroll_hook(double xdelta, double ydelta, void* param)
{
	param++;

	printf("Delta: %f;%f\n", xdelta, ydelta);
}

void	put_mandelbrot(t_fractol_data *fd)
{
	uint32_t	index_y;
	uint32_t	index_x;
	uint32_t	color;
	t_complex	*complex;
	
	// Loop through the dimensions of the window
	index_y = 0;
	while (index_y < fd->img->height)
	{
		index_x = 0;
		while (index_x < fd->img->width)
		{
			complex = window_to_complex(index_x, index_y);
			if (complex == NULL)
				return ;
			color = get_mandlebrot_color(complex);
			free(complex);
			mlx_put_pixel(fd->img, index_x, index_y, color);
			index_x++;
		}
		index_y++;
	}
}

int32_t	main(void)
{
	t_fractol_data	*fractol_data;

	fractol_data = init_fractol_data();
	if (!fractol_data)
		exit(EXIT_FAILURE);
	// mlx_set_setting(MLX_MAXIMIZED, true);
	fractol_data->mlx = mlx_init(1000, 600, "Robert's Awesome Fractol", true);
	if (!fractol_data->mlx)
		exit(EXIT_FAILURE);
	fractol_data->img = mlx_new_image(fractol_data->mlx,
			fractol_data->mlx->width,
			fractol_data->mlx->height);
	put_mandelbrot(fractol_data);
	mlx_image_to_window(fractol_data->mlx, fractol_data->img, 0, 0);
	mlx_key_hook(fractol_data->mlx, &key_hook, fractol_data);
	// mlx_resize_hook(fractol_data->mlx, &resize_hook, fractol_data);
	// mlx_mouse_hook(fractol_data->mlx, &mouse_hook, fractol_data);
	// mlx_cursor_hook(fractol_data->mlx, &cursor_hook, fractol_data);
	mlx_scroll_hook(fractol_data->mlx, &scroll_hook, NULL);
	mlx_loop(fractol_data->mlx);
	mlx_terminate(fractol_data->mlx);
	free_fractol_data(fractol_data);
	return (EXIT_SUCCESS);
}
