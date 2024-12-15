/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_type_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 23:07:07 by rreimann          #+#    #+#             */
/*   Updated: 2024/12/15 23:41:30 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_julia_constant(t_fractol_data *fd, long numeric_input)
{
	if (numeric_input == 1)
	{
		fd->constant->re = -0.7714;
		fd->constant->im = 0.2744;
	}
	else if (numeric_input == 2)
	{
		fd->constant->re = -0.5232;
		fd->constant->im = -0.6924;
	}
	else if (numeric_input == 3)
	{
		fd->constant->re = 0.2364;
		fd->constant->im = 0.5368;
	}
}

int	set_fractol_type(int argc, char **argv, t_fractol_data *fd)
{
	long	numeric_input;

	if (argc == 2)
		fd->fractol_type = FRACTOL_MANDELBROT;
	else if (argc == 3)
	{
		fd->fractol_type = FRACTOL_JULIA;
		numeric_input = ft_atoi(argv[2]);
		if (numeric_input < 1 || numeric_input > 3)
		{
			return (-1);
		}
		set_julia_constant(fd, numeric_input);
	}
	else
		return (-1);
	return (0);
}
