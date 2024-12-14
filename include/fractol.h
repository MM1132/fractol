/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:44:49 by rreimann          #+#    #+#             */
/*   Updated: 2024/12/14 17:24:19 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "MLX42.h"
# include "libft.h"
# include <stdlib.h>
# include <string.h>

// TYPES
typedef struct s_fractol_data
{
	mlx_t		*mlx;
	mlx_image_t	*img;
}				t_fractol_data;

// Utils
uint32_t	rgba_to_hex(int r, int g, int b, int a);

#endif
