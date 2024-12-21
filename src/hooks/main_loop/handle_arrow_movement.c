/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_arrow_movement.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:22:07 by rreimann          #+#    #+#             */
/*   Updated: 2024/12/21 18:07:37 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	move_diagonally(t_fractol_data *fd, double diagonal_speed)
{
	if (fd->keys.up && fd->keys.right)
	{
		fd->camera.target_pos.re += diagonal_speed;
		fd->camera.target_pos.im -= diagonal_speed;
		return (1);
	}
	else if (fd->keys.right && fd->keys.down)
	{
		fd->camera.target_pos.re += diagonal_speed;
		fd->camera.target_pos.im += diagonal_speed;
		return (1);
	}
	else if (fd->keys.down && fd->keys.left)
	{
		fd->camera.target_pos.re -= diagonal_speed;
		fd->camera.target_pos.im += diagonal_speed;
		return (1);
	}
	else if (fd->keys.left && fd->keys.up)
	{
		fd->camera.target_pos.re -= diagonal_speed;
		fd->camera.target_pos.im -= diagonal_speed;
		return (1);
	}
	return (0);
}

void	handle_arrow_movement(t_fractol_data *fd)
{
	double	speed;

	speed = fd->camera.zoom / 100;
	if (!move_diagonally(fd, speed * 1.41))
	{
		if (fd->keys.up == true)
			fd->camera.target_pos.im -= speed;
		else if (fd->keys.left == true)
			fd->camera.target_pos.re -= speed;
		else if (fd->keys.down == true)
			fd->camera.target_pos.im += speed;
		else if (fd->keys.right == true)
			fd->camera.target_pos.re += speed;
	}
}
