/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:45:58 by rreimann          #+#    #+#             */
/*   Updated: 2024/12/21 23:43:18 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	create_cross(t_fractol_data *fd)
{
	mlx_image_t	*cross;

	cross = mlx_new_image(fd->mlx,
			fd->mlx->width,
			fd->mlx->height);
	for (int32_t x = -10; x < 10; x++)
		mlx_put_pixel(cross, (cross->width / 2) + x, cross->height / 2, 0xFF0000FF);
	for (int32_t y = -10; y < 10; y++)
		mlx_put_pixel(cross, cross->width / 2, (cross->height / 2) + y, 0xFF0000FF);
	mlx_image_to_window(fd->mlx, cross, 0, 0);
}

int32_t	main(int argc, char **argv)
{
	t_fractol_data	*fractol_data;

	fractol_data = init_fractol_data(argc, argv);
	if (!fractol_data)
		exit(EXIT_FAILURE);
	fractol_data->mlx = mlx_init(1400, 800, "Robert's Awesome Fractol", true);
	if (!fractol_data->mlx)
		exit(EXIT_FAILURE);
	fractol_data->img = mlx_new_image(fractol_data->mlx,
			fractol_data->mlx->width,
			fractol_data->mlx->height);
	mlx_image_to_window(fractol_data->mlx, fractol_data->img, 0, 0);
	create_cross(fractol_data);
	mlx_key_hook(fractol_data->mlx, &key_hook, fractol_data);
	mlx_scroll_hook(fractol_data->mlx, &scroll_hook, fractol_data);
	mlx_loop_hook(fractol_data->mlx, &loop_hook, fractol_data);
	mlx_loop(fractol_data->mlx);
	mlx_terminate(fractol_data->mlx);
	return (EXIT_SUCCESS);
}
