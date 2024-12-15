/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:44:49 by rreimann          #+#    #+#             */
/*   Updated: 2024/12/15 18:12:02 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "MLX42.h"
# include "libft.h"
# include <stdlib.h>
# include <string.h>

// TYPES
typedef struct s_pos
{
	double	x;
	double	y;
}			t_pos;

typedef struct s_camera
{
	t_pos	*pos;
	int32_t	zoom;
}			t_camera;

typedef struct s_fractol_data
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_camera	*camera;
}				t_fractol_data;

typedef struct s_complex
{
	double	re;
	double	im;
}			t_complex;

// Hooks
void	key_hook(mlx_key_data_t keydata, void *fractol_data);
void	resize_hook(int32_t width, int32_t height, void* fractol_data);

// Utils
uint32_t	rgba_to_hex(int r, int g, int b, int a);

// Unsorted stuff
t_fractol_data	*init_fractol_data();
void			free_fractol_data(t_fractol_data	*fd);
t_complex		*window_to_complex(uint32_t x, uint32_t y);
uint32_t		get_mandlebrot_color(t_complex *start);

#endif
