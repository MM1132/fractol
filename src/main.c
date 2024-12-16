/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:45:58 by rreimann          #+#    #+#             */
/*   Updated: 2024/12/16 01:23:57 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int32_t	main(int argc, char **argv)
{
	t_fractol_data	*fractol_data;

	fractol_data = init_fractol_data(argc, argv);
	if (!fractol_data)
		exit(EXIT_FAILURE);
	fractol_data->mlx = mlx_init(2000, 1200, "Robert's Awesome Fractol", true);
	if (!fractol_data->mlx)
		exit(EXIT_FAILURE);
	fractol_data->img = mlx_new_image(fractol_data->mlx,
			fractol_data->mlx->width,
			fractol_data->mlx->height);
	mlx_image_to_window(fractol_data->mlx, fractol_data->img, 0, 0);
	put_fractol(fractol_data);
	mlx_key_hook(fractol_data->mlx, &key_hook, fractol_data);
	mlx_scroll_hook(fractol_data->mlx, &scroll_hook, fractol_data);
	mlx_loop(fractol_data->mlx);
	mlx_delete_image(fractol_data->mlx, fractol_data->img);
	mlx_terminate(fractol_data->mlx);
	free_fractol_data(fractol_data);
	return (EXIT_SUCCESS);
}
